#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

vector<int> test_array(3);

int main()
{
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serv_sock == -1) {
        cout << "server_socket failed" << endl;
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))){
        cout << "bind failed" << endl;
        return -1;
    }

    if (listen(serv_sock, 20) < 0)
    {
        cout << "listen failed" << endl;
        return -1;
    }

    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int client_sock = accept(serv_sock, (struct sockaddr*)&client_addr, &client_addr_size);
    if(client_sock == -1) 
    { 
        cout << "client_socket failed" << endl; 
        return -1; 
    }     

    read(client_sock, (char*)test_array.data(), sizeof(int)*test_array.size());
    for(int i=0;i<test_array.size();i++){
        cout << test_array[i] << " ";
    }
    cout << endl;
    close(client_sock);
    close(serv_sock);
    return 0;
}
