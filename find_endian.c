#include <stdio.h>

int main(int argc, char** argv) {
    int n = 1;
    char* char_ptr = (char *) &n;
    if (char_ptr[0]) {
        printf("little-endian\n");
    } else {
        printf("big-endian\n");
    }
    return 0;
}