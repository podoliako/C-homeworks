#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void split(char* string, char* delimiters, char** tokens, int* tokensCount){
    *tokensCount = 0;
    tokens[0] = malloc(sizeof(char) * strlen(string));
    int letters_in_string = 0;

    for(int i = 0; i < strlen(string); i++){
        int is_space_found = 0;
        int fake_space = 0;
        for(int j = 0; j < strlen(delimiters); j++){
            if (string[i] == delimiters[j] && string[i+1] != delimiters[j]) {
                *tokensCount += 1;
                is_space_found = 1;
                letters_in_string = 0;
                tokens[*tokensCount] = malloc(sizeof(char) * strlen(string));
                break;
            }
            if (string[i] == delimiters[j] && string[i+1] == delimiters[j]){
                fake_space = 1;
                break;
            }
        }
        if (is_space_found == 0 && fake_space == 0) {
            tokens[*tokensCount][letters_in_string++] = string[i];
        }
    }

}

int main() {
    char* line;
    char* spaces;
    int counter;
    char** tokens;
    line = "aaa   bbb                             ccc";
    printf("%s\n", line);
    spaces = " ";

    split(line, spaces, tokens, &counter);

    for(int i = 0; i < counter + 1; i++){
            printf("%s ", tokens[i]);
    }
    printf("\nThere were %d delimiters", counter);
    for(int i = 0; i < counter; i++) free(tokens[i]);

    return 0;
}
/* TODO: 1) "aaa   bbb               ccc" <- для такого вариант входных данных программа падает. Если несколько разделительных символов идет подряд, то они 
интерпретируются как отдельные слова, что неверно.
2) на каждый вызов malloc должен быть вызов free
*/
