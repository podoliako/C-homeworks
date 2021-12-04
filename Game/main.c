#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <hwloc.h>
#include "Functions.h"

#define MAX 80
#define PORT 8080
#define SA struct sockaddr


// Function designed for chat between client and server.
void game(int *sockfd)
{
    int Positions[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char buff[MAX];
    write(sockfd[0], "You are the first\n", sizeof(buff));
    write(sockfd[1], "You are the second\n", sizeof(buff));
    // infinite loop for chat
    int finish = 0;
    for (;;) {
        //first
        for(int p = 0; p < 2; p++) {
            bzero(buff, MAX);
            for (int i = 0; i < 9; i++) buff[i] = (char) Positions[i];
            if (checkIfPlayerWon(Positions, 1) == 1 || checkIfPlayerWon(Positions, 2) == 1) {
                finish = 1;
            }
            buff[9] = (char) finish;
            write(sockfd[p], buff, sizeof(buff));

            bzero(buff, MAX);
            read(sockfd[p], buff, sizeof(buff));
            makeMove(Positions, (int) buff[0], p + 1);
        }

        if (finish == 1) break;
    }
}

int main()
{
    int sockfd, len;
    int connfd[2];
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification


    int players = 0;

    while (players != 2) {
        if ((listen(sockfd, 2)) != 0) {
            printf("Listen failed...\n");
            exit(0);
        } else
            printf("Server listening..\n");
        len = sizeof(cli);

        // Accept the data packet from client and verification

        connfd[players] = accept(sockfd, (SA *) &cli, &len);
        if (connfd[players] < 0) {
            printf("server accept failed...\n");
            exit(0);
        } else {
            printf("server accept the client...\n");
            players++;
        }

    }
        // Function for chatting between client and server
    game(connfd);

    close(sockfd);
}


