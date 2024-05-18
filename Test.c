#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Provide valid IP address and Port number!\n");
        exit(EXIT_FAILURE);
    }

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Failure in WSA startup..\n");
        exit(EXIT_FAILURE);
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET)
    {
        printf("Error creating socket: %d\n", WSAGetLastError());
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    printf("Connecting to the server...\n");
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        printf("Error connecting to the server: %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (1)
    {
        memset(buffer, '\0', sizeof(buffer));
        printf("Enter: ");
        scanf(" %[^\n]s", buffer);
        send(s, buffer, strlen(buffer) + 1, 0);

        memset(buffer, '\0', sizeof(buffer));
        recv(s, buffer, sizeof(buffer), 0);
        printf("Received: %s\n", buffer);

        if (strcmp("Bye", buffer) == 0)
            break;
    }

    closesocket(s);
    WSACleanup();
}
