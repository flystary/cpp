#include <stdlib.h>
#include <stdio.h>
#include <libssh/libssh.h>

int main(int argc, char** argv)
{
    ssh_session session;
    int port = 7722;
    int rc;

    session = ssh_new();
    if(session == NULL)
        exit(-1);

    ssh_options_set(session, SSH_OPTIONS_HOST, "10.168.1.133");
    ssh_options_set(session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(session, SSH_OPTIONS_USER, "root");
    
    rc = ssh_connect(session);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error connecting to remote host: %s\n", ssh_get_error(session));
        ssh_free(session);
        exit(-1);
    }

    rc = ssh_userauth_password(session, NULL, "Xnetworks.c0M");
    if (rc != SSH_AUTH_SUCCESS)
    {
        fprintf(stderr, "Authentication failed: %s\n", ssh_get_error(session));
        ssh_disconnect(session);
        ssh_free(session);
        exit(-1);
    }

    ssh_channel channel = ssh_channel_new(session);
    if (channel == NULL)
    {
        fprintf(stderr, "Error create SSH channel: %s\n", ssh_get_error(session));
        ssh_disconnect(session);
        ssh_free(session);
        exit(-1);
    }

    rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error opening SSH channel: %s\n", ssh_get_error(session));
        ssh_channel_free(channel);
        ssh_disconnect(session);
        ssh_free(session);
        exit(-1);
    }

    rc = ssh_channel_request_exec(channel, "ls -al");
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error executing remote command: %s\n", ssh_get_error(session));
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        ssh_disconnect(session);
        ssh_free(session);
        exit(-1);
    }

    char buffer[256];
    int nbytes;
    while ((nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0)) > 0)
    {
        printf("%.*s", nbytes, buffer);
    }

    if (nbytes < 0)
    {
        fprintf(stderr, "Error reading SSH channel: %s\n", ssh_get_error(session));
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        ssh_disconnect(session);
        ssh_free(session);
        exit(-1);
    }
    
    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    ssh_disconnect(session);
    ssh_free(session);

    return 0;
}
