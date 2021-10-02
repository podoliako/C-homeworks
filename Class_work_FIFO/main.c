#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int client;
    scanf("%d", &client);

    int max_length = 80;

    char *file_1 ="fifo1";
    if (mkfifo(file_1, 0666) < 0) printf("ERROR\n");

    char * file_2 = "fifo2";
    if (mkfifo(file_2, 0666) < 0) printf("ERROR\n");

    size_t pid = fork ();

    if(pid == 0){
        char arr[max_length];
        int is_running = 1;
        int fd;
        if(client == 1) fd = open(file_1, O_WRONLY);
        else fd = open(file_2, O_WRONLY);
        while (is_running){
            fgets(arr, max_length, stdin);
            write(fd, arr, strlen(arr)+1);

        }
        close(fd);
    }

    else if(pid > 0){
        int fd1;
        char str[max_length];
        int is_running = 1;
        if(client == 1) fd1 = open(file_2,O_RDONLY);
        else fd1 = open(file_1, O_RDONLY);
        while(is_running){
            read(fd1, str, max_length);
            printf("User%d: %s\n", client, str);
        }
        close(fd1);
    }
}

