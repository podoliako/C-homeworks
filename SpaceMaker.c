#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ich {
    int amount;
    char* words;
};

struct ich SpaceMaker(char* line, char* spaces){
    struct ich result;
    result.words = malloc(sizeof(char) * strlen(line) * 2);
    result.amount = 0;
    for(int i = 0; i < strlen(line); i++){
        int is_space_found = 0;
        for(int j = 0; j < strlen(spaces); j++){
            if (line[i] == spaces[j]){
                result.amount += 1;
                strcat(result.words, " space ");
                is_space_found = 1;
                break;
            }
        }
      //  printf("%s, %d spaces\n", result.words, result.amount);
      //  printf("%c = ", line[i]);
        if (is_space_found == 0) result.words[strlen(result.words)] = line[i];
      //  printf("%c\n", result.words[strlen(result.words) - 1]);
    }
    //printf("%s, %d spaces", result.words, result.amount);
    return result;
}

int main() {
    char* line;
    char* spaces;
    line = "gasdg gadgogoxn oadsg sgo osgtqw etao g ogo";
    printf("%s\n", line);
    spaces = " ";
    struct ich exit;
    exit = SpaceMaker(line, spaces);
    printf("%s, %d spaces", exit.words, exit.amount);

    return 0;
}

