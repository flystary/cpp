#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

using namespace std;
vector<int> test_array = {1, 2, 3};

int main()
{
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);

    int client_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    connect(client_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    write(client_sock, (char*)test_array.data(), sizeof(int)*test_array.size());

    close(client_sock);
    
    return 0;
}
