#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 54321

int main()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    int opt = 0;
    setsockopt(serverSocket,
               SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
               &opt,
               sizeof(opt));

    struct sockaddr_in address;
    int addrLen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(serverSocket, (struct sockaddr *)&address, addrLen);
    listen(serverSocket, 3);
    int newSocket = accept(serverSocket,
                     (struct sockaddr *)&address,
                     (socklen_t*)&addrLen);

    char buffer[1024] = {0};
    read(newSocket, buffer, 1024);
    printf("Server says: Received request '%s'\n", buffer);

    char *hello = "Hello from server. Trans by tcpip socket!";
    send(newSocket, hello, strlen(hello), 0);
    printf("Server says: hello message sent.\n");

    return 0;
}