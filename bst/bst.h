#ifndef _BST_H_
#define _BST_H_

typedef struct node_st {
    int key;
    void *element;
    struct node_st *left;
    struct node_st *right;
} Node;

Node *insert(Node *root, int key, void *element);

void *lookup(Node *root, int key);

Node *delete(Node *root, int key, void **ret_del);

void free_tree(Node *root);

#endif /* _BST_H_ */
