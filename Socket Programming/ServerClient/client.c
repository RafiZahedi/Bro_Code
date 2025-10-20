#include <winsock2.h>
#include <windows.h> 
#include <stdio.h>
#include <string.h>

#define PORT 1234
#define HOST "127.0.0.1"

int main(int argc, char ** argv){
    if (argc <2){
        printf("Usage: %s \"data to send\"\n", argv[0]);
        return 0;
        // printf("Done");
    }
    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(2,2), &wsaData)){
        printf("****Error In WSAStartup!**** \n");
        return -1;
    }
    SOCKET s = socket (AF_INET, SOCK_STREAM, 0);
    if(s == INVALID_SOCKET){
        printf("Error in Socket\n");
        return -1;
    }

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT); // convert to big endian just in case.
    addr.sin_addr.s_addr = inet_addr(HOST);

    if(connect(s, (struct sockaddr*)&addr, sizeof(struct sockaddr_in))){
        printf("Error in connect\n");
        return -1;
    }

    int send_count = send(s, argv[1], strlen(argv[1]), 0);
    printf("SUCCESS, %d bytes has been sent\n", send_count);

    closesocket(s);
    WSACleanup();
    return 0;
}