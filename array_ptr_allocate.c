#include <stdio.h>
#include <stdlib.h>

#define LEN 3

int** AllocateIntPtrArr(int arr[], int len) {
    int** ret;
    ret = (int**) malloc(sizeof(int*) * len);
    if (ret == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        ret[i] = &arr[i];
    }

    return ret;
}

int main(int argc, char** argv) {
    int arr[] = {1, 2, 3};
    int **res = AllocateIntPtrArr(arr, LEN);
    for (int i = 0; i < LEN; i++) {
        printf("%d ", *res[i]);
    }
    free(res);
    return 0;
}