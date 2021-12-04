#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <hwloc.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Functions.h"

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void game(int sockfd)
{
    int Positions[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char buff[MAX];
    read(sockfd, buff, sizeof(buff));
    int player;
    if(buff[12] == 'f') player = 1;
    else player = 2;
    printf("%s", buff);
    for(;;) {
        //receive field
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        for(int i = 0; i < 9; i ++) Positions[i] = (int)buff[i];

        if(buff[9] == 1) {
            printf("You lose(((\n");
            break;
        }

        printField(Positions);

        //make move
        printf("Make your move: ");
        int move;
        int status = 0;
        while (status == 0) {
            scanf("%d", &move);
            status = makeMove(Positions, move, player);
        }
        printField(Positions);


        //send move
        bzero(buff, sizeof(buff));
        buff[0] = (char)move;
        write(sockfd, buff, sizeof(buff));

        if(checkIfPlayerWon(Positions, player)){
            printf("You won!\n");
            break;
        }
    }
}


int main() {
    int sockfd;
    struct sockaddr_in servaddr, cli;

    // socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // function for chat
    game(sockfd);

    // close the socket
    close(sockfd);
    return 0;
}
