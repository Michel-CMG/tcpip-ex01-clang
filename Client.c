#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


#define PORT 54321

int DoTheJob_ForTest()
{
    char *hello = "Hello from client. Trans by tcpip socket!";
    int mySocket = 0;
    mySocket = socket(AF_INET, SOCK_STREAM, 0);    // Consider no error now

    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);

    // Convert IP address from text to binary
    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);

    // Connect socket and send request message
    connect(mySocket, (struct sockaddr *)&servAddr, sizeof(servAddr));
    send(mySocket, hello, strlen(hello), 0);
    printf("Client says: Hello Message sent.\n");

    // Read response message
    char buffer[1024] = {0};
    read(mySocket, buffer, 1024);
    printf("Client says: Received the message '%s'", buffer);

    return 0;
}

int main()
{
    printf("Let's program to send the hello message\n");
    printf("Dont forget to install libc6-dev\n");
    return DoTheJob_ForTest();
}