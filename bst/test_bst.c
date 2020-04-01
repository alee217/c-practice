#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

void print_tree(Node *tree);

int main(int argc, char **argv) {
    Node *tree = NULL;

    /*           3
     *       1       5
     *     0   2        6
     */
    tree = insert(tree, 3, "a");
    tree = insert(tree, 1, "b");
    tree = insert(tree, 2, "c");
    tree = insert(tree, 5, "d");
    tree = insert(tree, 0, "e");
    tree = insert(tree, 6, "f");

    print_tree(tree);
    printf("\n");

    printf("%s\n", (char *) lookup(tree, 1));
    printf("%s\n", (char *) lookup(tree, 3));
    assert(lookup(tree, 7) == NULL);

    void *ret_del;
    tree = delete(tree, 7, &ret_del);
    assert(ret_del == NULL);
    
    tree = delete(tree, 1, &ret_del);
    assert(ret_del != NULL);
    assert(!strcmp((char*) ret_del, "b"));

    print_tree(tree);
    printf("\n");

    free_tree(tree);

    return 0;
}

void print_tree(Node *root) {
    if (root != NULL) {
        printf("(%d, %s) ", root->key, (char *) root->element);
	print_tree(root->left);
	print_tree(root->right);
    }
}
