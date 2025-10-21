#include <winsock2.h>
#include <stdio.h>

#define PORT 4000
#define HOST "127.0.0.1"

int main(){
       WSADATA w; WSAStartup(MAKEWORD(2,2), &w);
    
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in adrs = {0};
    adrs.sin_family = AF_INET;
    adrs.sin_port = htons(PORT);
    adrs.sin_addr.s_addr = inet_addr(HOST);

    connect(s, (struct sockaddr*)&adrs, sizeof(adrs));

     char buffer[50];
    printf("Enter you message to send (max 50 chars): ");
    fgets(buffer, sizeof(buffer), stdin);
    send(s, buffer, strlen(buffer), 0);

    closesocket(s);
    WSACleanup();

}