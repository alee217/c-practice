#include <stdio.h>
#include "ll.h"

int main(int argc, char** argv) {
    Node *list = NULL;
    char *hi = "Hello";
    char *bye = "Goodbye";
    char *blek = "Blek";
    void *pop_res = NULL;

    list = Push(list, (void *) hi);
    list = Push(list, (void *) bye);
    list = Push(list, (void *) blek);

    Node *curr = list;
    while (curr != NULL) {
        printf("%s\n", (char *) curr->element);
	curr = curr->next;
    }

    printf("%d\n", size_of_list(list));

    list = Pop(list, &pop_res);

    printf("%s\n", (char *) pop_res);
    printf("%d\n", size_of_list(list));

    ll_free(list);

    return 0;
}
