#ifndef _LL_H_
#define _LL_H_

typedef struct node_st {
    void *element;
    struct node_st *next;
} Node;

Node *Push(Node *head, void *element);

Node *Pop(Node *head, void **ret_elem);

int size_of_list(Node *head);

void ll_free(Node *head);

#endif /* _LL_H_ */
