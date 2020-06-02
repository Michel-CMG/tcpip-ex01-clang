#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 54321

int main()
{
    int mySocket = 0;
    mySocket = socket(AF_INET, SOCK_STREAM, 0);    // Consider no error now

    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);

    // Convert IP address from text to binary
    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);

    // Connect socket and send request message
    connect(mySocket, (struct sockaddr *)&servAddr, sizeof(servAddr));

    char *hello = "Hello from client. Trans by tcpip socket!";
    send(mySocket, hello, strlen(hello), 0);
    printf("Client says: Hello Message sent.\n");

    // Read response message
    char buffer[1024] = {0};
    read(mySocket, buffer, 1024);
    printf("Client says: Received the message '%s'\n", buffer);

    return 0;
}