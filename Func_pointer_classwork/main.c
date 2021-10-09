#include <stdio.h>
#include <stdlib.h>

int length = 100;

int Compare(int left, int right){
    return left > right;
}

void Sort(int* data, int n, int (*Compare)(int, int)){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(Compare(data[i], data[j])){
                int tmp;
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}


int main() {
    int *data =  NULL;
    data = (int*) malloc(length * sizeof(int));
    for(int i = 0; i < length; i++){
        data[i] = i^2 - 5*i - 15;
        printf("%d ", data[i]);
    }
    printf("\n");

    Sort(data, length, Compare);

    for(int i = 0; i < length; i++){
        printf("%d ", data[i]);
    }

    return 0;
}
