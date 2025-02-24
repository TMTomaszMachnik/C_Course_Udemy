// #include<sys/socket.h>
// #include<arpa/inet.h>
// #include<unistd.h>
// #include<stdio.h>
// #include<memory.h>
// #include<stdlib.h>
// short socketCreate(void) {
//     short hSocket;
//     printf("Create the socket\n");
//     hSocket = socket(AF_INET, SOCK_STREAM, 0);
//     return hSocket;
// }

// int bindSocket(int hSocket){
//     int iRetval = -1;
//     int clientPort = 12345;

//     struct sockaddr_in remote = {0};

//     remote.sin_family = AF_INET;

//     remote.sin_addr.s_addr = htonl(INADDR_ANY);
//     remote.sin_port = htons(clientPort);

//     iRetval = bind(hSocket, (struct sockaddr*)&remote, sizeof(remote));
//     return iRetval;
// }

// int main(int argc, char *argv[]){
//     int socket_desc = 0, sock = 0, clientLen = 0;
//     struct sockaddr_in client;
//     char client_message[200] = {0};
//     char message[100] = {0};
//     const char *pMessage = "Hello there";

//     socket_desc = socketCreate();
//     if(socket_desc == -1){
//         printf("Create failure, exiting...");
//         exit(1);
//     }

//     printf("Socket created\n");

//     if(bindSocket(socket_desc) < 0 ){
//         perror("bind dailed, exiting...");
//         exit(1);
//     }
//     printf("Bind done\n");
//     listen(socket_desc, 3);

//     while(1) {
//         printf("Waiting for connections..\n");
//         clientLen = sizeof(struct sockaddr_in);

//         sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&clientLen);
//         if (sock < 0){
//             perror("Failed");
//             return 1;
//         }
//         printf("Connection accepted\n");
//         memset(client_message, '\0',sizeof client_message);
//         memset(message, '\0',sizeof message);

//         if(recv(sock, client_message,200,0) < 0){
//             printf("Failed");
//             break;
//         }
//         printf("Client reply: %s\n",client_message);
//         if(strcmp(pMessage,client_message) == 0){
//             strcpy(message, "hi there");
//         }
//         else {
//             strcpy(message, "invalid message");
//         }
//         if(send(sock, message, strlen(message), 0) < 0) {
//             printf("Send failed");
//             return 1;
//         }
//         close(sock);
//         sleep(1);
//     }
//     return 0;
// }


#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

short socketCreate(void) {
    short hSocket;
    printf("Creating the socket...\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindSocket(int hSocket) {
    int iRetval = -1;
    int clientPort = 12345;
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(clientPort);

    iRetval = bind(hSocket, (struct sockaddr *)&server, sizeof(server));
    return iRetval;
}

int main() {
    int socket_desc, client_sock, clientLen;
    struct sockaddr_in client;
    char client_message[200] = {0};

    socket_desc = socketCreate();
    if (socket_desc == -1) {
        printf("Socket creation failed!\n");
        return 1;
    }
    
    if (bindSocket(socket_desc) < 0) {
        perror("Bind failed!");
        return 1;
    }
    printf("Bind successful, server running...\n");

    listen(socket_desc, 3);

    while (1) {
        printf("Waiting for connections...\n");
        clientLen = sizeof(struct sockaddr_in);
                            
        client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&clientLen);
        if (client_sock < 0) {
            perror("Accept failed!");
            return 1;
        }
        printf("Connection accepted!\n");

        // Clear buffer
        memset(client_message, '\0', sizeof(client_message));

        // Receive data
        if (recv(client_sock, client_message, sizeof(client_message), 0) < 0) {
            printf("Receive failed\n");
            break;
        }

        printf("ESP8266 Data Received: %s\n", client_message);

        // Send response
        char response[] = "Data Received\n";
        send(client_sock, response, strlen(response), 0);

        close(client_sock);
    }

    return 0;
}
