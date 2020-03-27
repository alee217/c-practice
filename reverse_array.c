#include <stdio.h>

#define LEN 4

void Reverse(unsigned int arr[], int len) {
    if (len <= 1) {
        return;
    }

    int i = 0;
    int j = len - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main(int argc, char** argv) {
    unsigned int arr[] = {1, 2, 3, 4};
    reverse(arr, LEN);
    for (int i = 0; i < LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}