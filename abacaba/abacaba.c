#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GenerateString(int n, char* line){
    char letter = 'a';
    line[0] = letter;
    char *another_line = malloc(sizeof(char) * 50);

    for(int i = 0; i < n - 1; i++){
        letter++;
        strncpy(another_line, line, strlen(line));
        line[strlen(line)] = letter;
        strcat(line, another_line);
    }
    free(another_line);


}

int main() {
    char *line = malloc(sizeof(char) * 50);
    GenerateString(6, line);
    printf("%s \n", line);
    free(line);
    return 0;
}

// Старайтесь не использовать "магических" констант. 
// Вместо того, чтобы просто использовать число 50, лучше завести константу const int MaxStringLength = 50;
