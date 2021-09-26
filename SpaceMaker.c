#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ich {
    int amount;
    char* words;
};

void split(char* string, char* delimiters, char** tokens, int* tokensCount){
    struct ich result;
    result.words = malloc(sizeof(char) * strlen(string) * 2);
    result.amount = 0;
    for(int i = 0; i < strlen(string); i++){
        int is_space_found = 0;
        for(int j = 0; j < strlen(delimiters); j++){
            if (string[i] == delimiters[j]){
                result.amount += 1;
                strcat(result.words, "', '");

                is_space_found = 1;
                break;
            }
        }
        if (is_space_found == 0) result.words[strlen(result.words)] = string[i];
    }
    *tokens = malloc(sizeof(char) * strlen(result.words) * 2);
    strcat(*tokens, result.words);
    //printf("%s\n", string);
    *tokensCount = result.amount;
}

int main() {
    char* line;
    char* spaces;
    int counter;
    char* tokens;
    line = "gasdg gadgogoxn oadsg sgo osgtqw etao g ogo";
    printf("%s\n", line);
    spaces = " ";

    split(line, spaces, &tokens, &counter);

    printf("'%s', %d spaces", tokens, counter);

    return 0;
}
/* TODO: 1) "aaa   bbb               ccc" <- для такого вариант входных данных программа падает. Если несколько разделительных символов идет подряд, то они 
интерпретируются как отдельные слова, что неверно.
2) на каждый вызов malloc должен быть вызов free
*/
