#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GenerateString(int n, char* line){
    char letter = 'a';
    line[0] = letter;
    char *another_line = (char*)malloc(25);
    for(int i = 0; i < n - 1; i++){
        letter++;
        strncpy(another_line, line, strlen(line));
        line[strlen(line)] = letter;
        strcat(line, another_line);
    }
    printf("%s \n", line);
}

int main() {
    char *line = (char*)malloc(25);
    GenerateString(6, line);
    return 0;
}

