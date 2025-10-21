#include <winsock2.h>
#include <stdio.h>

#define HOST "127.0.0.1"
#define PORT 4000

int main() {
    WSADATA w; WSAStartup(MAKEWORD(2,2), &w);
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in a = {0};
    a.sin_family = AF_INET;
    a.sin_port = htons(PORT);
    a.sin_addr.s_addr = inet_addr(HOST);

    bind(s, (struct sockaddr*)&a, sizeof(a));
    listen(s, 5);
    printf("Server listening on %s:%d\n", HOST, PORT);

    while (1) {
        char buf[50] = {0};
        SOCKET c = accept(s, 0, 0);
        recv(c, buf, sizeof(buf)-1, 0);
        printf("%s\n", buf);
        closesocket(c);
    }

    closesocket(s);
    WSACleanup();
}
