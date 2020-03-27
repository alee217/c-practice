#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int FindFirstWord(char* str, char** retword) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            break;
        }
        i++;
    }
    (*retword) = (char*) malloc(sizeof(char) * i+1);
    if ((*retword) == NULL) {
        return 0;
    }
    strncpy((*retword), str, i);
    (*retword)[i] = '\0';
    return 1;
}

int main(int argc, char** argv) {
    char* retstr;

    char* str = "To be or not to be";
    if (!FindFirstWord(str, &retstr)) {
        printf("failed");
        return 0;
    }
    printf(retstr);
    printf("\n%d\n", strlen(retstr));
    free(retstr);
    return 0;
}