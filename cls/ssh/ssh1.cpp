#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <libssh/libssh.h>

int verify_knownhost(ssh_session session);
char *getpass(const char *str);
int show_remote_processes(ssh_session session);

int main()
{
        ssh_session my_ssh_session;
        int rc;
        char *password;
        int  port = 7722;

        /*创建一个会话*/
        my_ssh_session = ssh_new();
        if(my_ssh_session == NULL)
        {
                exit(-1);
        }

        /*设置会话相关信息*/
        ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "10.168.1.133");
        //ssh_options_set(my_ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
        ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, &port);
        ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "freetype");

        /*连接到服务器*/
        rc = ssh_connect(my_ssh_session);
        if(rc != SSH_OK)
        {
                fprintf(stderr, "Error connecting to localhost: %s\n", ssh_get_error(my_ssh_session));
                ssh_free(my_ssh_session);
                exit(-1);
        }

        /*其它认证方式*/
        /*if(verify_knownhost(my_ssh_session) < 0)
        {
                ssh_disconnect(my_ssh_session);
                ssh_free(my_ssh_session);
                exit(-1);
        }*/

        /*密码认证方式*/
        password = getpass("Password: ");
        rc = ssh_userauth_password(my_ssh_session, NULL, password);
        if(rc != SSH_AUTH_SUCCESS)
        {
                fprintf(stderr, "Error authenticating with password: %s\n", ssh_get_error(my_ssh_session));
                ssh_disconnect(my_ssh_session);
                ssh_free(my_ssh_session);
                exit(-1);
        }

        fprintf(stderr, "connect success!\n");
        show_remote_processes(my_ssh_session);

        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);

        exit(0);
}

char *getpass(const char *str)
{
        static char password[64];
        int index;

        fprintf(stdout, "%s", str);

        if(fgets(password, sizeof(password), stdin) == NULL)
        {
                fprintf(stderr, "fgets error\n");
                return NULL;
        }

        index = strlen(password) - 1;

        if(password[index] == '\n')
        {
                password[index] = '\0';
        }

        return password;
}

/*服务器认证方式*/
int verify_knownhost(ssh_session session)
{
        int state;
        int hlen;
        unsigned char  *hash = NULL;
        char *hexa;
        char buf[10];

        state = ssh_is_server_known(session);

        hlen = ssh_get_pubkey_hash(session, &hash);
        if(hlen < 0)
        {
                free(hash);
                return -1;
        }

        switch(state)
        {
                case SSH_SERVER_KNOWN_OK:
                        break;

                case SSH_SERVER_KNOWN_CHANGED:
                        fprintf(stderr, "Host key for server changed: it is now:\n");
                        ssh_print_hexa("Public key hash", hash, hlen);
                        fprintf(stderr, "For security reasons, connection will be stopped\n");
                        free(hash);
                        return -1;

                case SSH_SERVER_FOUND_OTHER:
                        fprintf(stderr, "The host key for this server was not found but an other type of key exists.\n");
                        fprintf(stderr, "An attacker might change the default server key to confuse your client into thinking the key does not exist\n");
                        free(hash);
                        return -1;

                case SSH_SERVER_FILE_NOT_FOUND:
                        fprintf(stderr, "Could not find known host file.\n");
                        fprintf(stderr, "If you accept the host key here, the file will be automatically created.\n");

                case SSH_SERVER_NOT_KNOWN:
                        hexa = ssh_get_hexa(hash, hlen);
                        fprintf(stderr, "The server is unknown. Do you trust the host key?\n");
                        fprintf(stderr, "Public key hash: %s\n", hexa);
                        free(hexa);

                        if(fgets(buf, sizeof(buf), stdin) == NULL)
                        {
                                free(hash);
                                return -1;
                        }

                        if(strncasecmp(buf, "yes", 3) != 0)
                        {
                                free(hash);
                                return -1;
                        }

                        if(ssh_write_knownhost(session) < 0)
                        {
                                fprintf(stderr, "Error %s\n", strerror(errno));
                                free(hash);
                                return -1;
                        }

                        break;

                case SSH_SERVER_ERROR:
                        fprintf(stderr, "Error %s",ssh_get_error(session));
                        free(hash);
                        return -1;
        }

        free(hash);

        return 0;
}

int show_remote_processes(ssh_session session)
{
        ssh_channel channel;
        int rc;
        char buffer[256];
        int nbytes;

        channel = ssh_channel_new(session);
        if(channel == NULL)
        {
                return SSH_ERROR;
        }

        rc = ssh_channel_open_session(channel);
        if(rc != SSH_OK)
        {
                ssh_channel_free(channel);
                return rc;
        }

        rc = ssh_channel_request_exec(channel, "pwd");
        if(rc != SSH_OK)
        {
                ssh_channel_close(channel);
                ssh_channel_free(channel);
                return rc;
        }

        nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
        while(nbytes > 0)
        {
                if(write(1, buffer, nbytes) != (unsigned int)nbytes)
                {
                        ssh_channel_close(channel);
                        ssh_channel_free(channel);
                        return SSH_ERROR;
                }

                nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
        }

        if(nbytes < 0)
        {
                ssh_channel_close(channel);
                ssh_channel_free(channel);
                return SSH_ERROR;
        }

        ssh_channel_send_eof(channel);
        ssh_channel_close(channel);
        ssh_channel_free(channel);

        return SSH_OK;
}
