#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {

int N = 7;
for (int i = 0; i < N; i++){
    size_t pid = fork ();

    if (pid == 0){
        printf ("%d: %d -> %d\n", i + 1,  getppid(), getpid());
    }

    else if (pid > 0){
        wait(0);
        printf ("%zu : kid is over\n", pid);
        exit(i);
        }
    }
}
