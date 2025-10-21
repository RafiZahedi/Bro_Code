#include <winsock2.h>
#include <stdio.h>

#define HOST "127.0.0.1"
#define PORT 1234

int main(int argc, char **argv) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData)) {
        printf("Error in WSAStartup\n");
        return -1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        printf("Error in Socket\n");
        return -1;
    }

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(HOST);

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr))) {
        printf("Error in Bind\n");
        return -1;
    }

    if (listen(s, 5)) {
        printf("Error in Listen\n");
        return -1;
    }

    printf("Server listening on %s:%d\n", HOST, PORT);

    while (1) {
        char buffer[100] = {0};
        struct sockaddr_in client_addr;
        int client_addrlen = sizeof(client_addr);

        SOCKET client_socket = accept(s, (struct sockaddr *)&client_addr, &client_addrlen);
        if (client_socket != INVALID_SOCKET) {
            int recv_count = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
            if (recv_count > 0) {
                buffer[recv_count] = '\0';
                char *client_ip = inet_ntoa(client_addr.sin_addr);
                printf("%s:%d -> %s\n", client_ip, ntohs(client_addr.sin_port), buffer);
            closesocket(client_socket);
        }
    }

    closesocket(s);
    WSACleanup();
    return 0;
}}