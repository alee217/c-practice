#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include <string.h>

char *get_next_line();

int *to_int_array(char *string, int *retarraylen);

char **to_bit_array(int *int_arr, int arrlen);

int main(int argc, char **argv) {
    char *line = get_next_line();
    
    int arrlen;
    int *int_arr = to_int_array(line, &arrlen);
    for (int i = 0; i < arrlen; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");
}

char *get_next_line() {
    char *line = (char *) malloc(sizeof(char));
    assert(line != NULL);
    fprintf(stdout, "Enter next sequence of integers:\n");
    int count = 0;
    while (1) {
        line = realloc(line, count+2);
        assert(line != NULL);
        if (fgets(&line[count], 2, stdin) == NULL) {
            return line;
        }
        if (line[count] == '\n') {
            line[count] = '\0';
            return line;
        }
        count++;
    }
    // Should not get here
    return NULL;
}

int *to_int_array(char *string, int *retarraylen) {
    char *nexttok = strtok(string, " \t");
    int curr_index = 0;
    int *ret_array = (int *) malloc(sizeof(int));
    assert(ret_array != NULL);
    while (nexttok != NULL) {
        int nextint;
        assert(sscanf(nexttok, "%d", &nextint));
        ret_array = (int *) realloc(ret_array, (curr_index + 1) * sizeof(int));
        assert(ret_array != NULL);
        ret_array[curr_index] = nextint;

        curr_index++;
        nexttok = strtok(NULL, " \t");
    }
    *retarraylen = curr_index++;
    return ret_array;
}
