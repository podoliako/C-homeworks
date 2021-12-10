#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

void findFile(char folder[255], int maxDepth, int depth, char key[100])
{
    if(depth <= maxDepth) {
        DIR *dfd;
        struct dirent *dp;
        dfd = opendir(folder);

        while ((dp = readdir(dfd)) != NULL) {

            if (dp->d_type != 4) {
                if (strcmp(dp->d_name, key) == 0) printf("%s/%s \n", folder, dp->d_name);
            }
            else if ((dp->d_type == 4) && ((strcmp(dp->d_name, ".") != 0) && (strcmp(dp->d_name, "..") != 0))) {
                char fld[255];
                strcpy(fld, strcat(folder, "/"));
                findFile(strcat(fld, dp->d_name), maxDepth, depth + 1, key);
            }
        }
        closedir(dfd);
    }
}

// fix it: только с помощью дебагера можно проверить работоспособность? нужно вывести список мест, где нашли файлы
int main(int argc, char **argv)
{
    char filename[256];
    if (argc < 2) strcpy(filename, ".");
    else strcpy(filename, argv[1]);
    findFile(filename, atoi(argv[2]), 0, argv[3]);
    return 0;
}
