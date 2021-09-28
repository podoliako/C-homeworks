#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void split(char* string, char* delimiters, char** tokens, int* tokensCount){
    *tokensCount = 0;
    tokens[0] = malloc(sizeof(char) * strlen(string));
    int letters_in_string = 0;
    for(int i = 0; i < strlen(string); i++){
        int is_space_found = 0;
        for(int j = 0; j < strlen(delimiters); j++){
            if (string[i] == delimiters[j]){
                *tokensCount += 1;
                is_space_found = 1;
                letters_in_string = 0;
                tokens[*tokensCount] =  malloc(sizeof(char)*strlen(string));
                break;

            }
        }
        if (is_space_found == 0) {
            tokens[*tokensCount][letters_in_string++] = string[i];
        }
    }

}

int main() {
    char* line;
    char* spaces;
    int counter;
    char** tokens;
    line = "gasdg gadgogoxn oadsg sgo osgtqw etao g ogo";
    printf("%s\n", line);
    spaces = " ";

    split(line, spaces, tokens, &counter);

    for(int i = 0; i < counter; i++){
            printf("%s, ", tokens[i]);
    }

    for(int i = 0; i < counter; i++) free(tokens[i]);

    return 0;
}

