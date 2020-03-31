#include <stdlib.h>
#include <assert.h>
#include "ll.h"

Node *Push(Node *head, void *element) {
    Node *n = (Node *) malloc(sizeof(Node));
    assert(n != NULL);
    n->element = element;
    n->next = head;
}

Node *Pop(Node *head, void **ret_elem) {
    Node *prev = head;
    head = head->next;
    *(ret_elem) = prev->element;
    free(prev);
    return head;
}

int size_of_list(Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
	head = head->next;
    }
    return count;
}

void ll_free(Node *head) {
    assert(head != NULL);
    if (head->next == NULL) {
        free(head);
	return;
    }
    Node *prev = head;
    head = head->next;
    while (head != NULL) {
        free(prev);
	prev = head;
	head = head->next;
    }
    free(prev);
}

