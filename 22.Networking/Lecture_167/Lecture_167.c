#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<time.h>
short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int socketConnect(int hSocket) {
    int iRetval = -1;
    int ServerPort = 12345;
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr*)&remote, sizeof(remote));
    return iRetval;
}

int socketSend(int hSocket, char* Rqst, short lenRqst) {
    int shorRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;
    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("timeout\n");
        return -1;
    }
    shorRetval = send(hSocket,Rqst,lenRqst,0);
    return shorRetval; 
}

int socketReceive(int hSocket, char* Rsp,short RcvSize){
    int shorRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;
    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("timeout\n");
        return -1;
    }
    shorRetval = recv(hSocket,Rsp,RcvSize,0);
    printf("Response %s", Rsp);
    return shorRetval; 
}

int main(int argc, char *argv[]) {
    int hSocket;
    char sendMessage[] = "Hello there";
    char recvMessage[200] = {0};

    // 1. Create socket
    hSocket = socketCreate();
    if (hSocket == -1) {
        exit(1);
    }

    // 2. Connect to server
    if (socketConnect(hSocket) < 0) {
        close(hSocket);
        exit(1);
    }
    printf("Connected to server\n");

    // 3. Send message
    if (socketSend(hSocket, sendMessage, strlen(sendMessage)) < 0) {
        close(hSocket);
        exit(1);
    }
    printf("Message sent: %s\n", sendMessage);

    // 4. Receive response
    if (socketReceive(hSocket, recvMessage, sizeof(recvMessage) - 1) < 0) {
        close(hSocket);
        exit(1);
    }

    // 5. Close socket
    close(hSocket);
    printf("Connection closed\n");

    return 0;
}