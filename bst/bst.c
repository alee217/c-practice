#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

static Node *lookup_node(Node *root, int key);

static Node *insert_node(Node *root, Node *in);

Node *insert(Node *root, int key, void *element) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->key = key;
    n->element = element;
    n->left = NULL;
    n->right = NULL;

    if (root == NULL) {
        return n;
    }

    return insert_node(root, n);
}

static Node *insert_node(Node *root, Node *in) {
    if (root == NULL) {
        return in;
    }
    if (in->key < root->key) {
	    root->left = insert_node(root->left, in);
    } else {
        root->right = insert_node(root->right, in);
    }
    
    return root;
}

void *lookup(Node *root, int key) {
    Node *res = lookup_node(root, key);
    if (res == NULL) {
        return NULL;
    }
    return res->element;
}

static Node *lookup_node(Node *root, int key) {
    if (root != NULL) {
        if (key == root->key) {
	        return root;
        }
        if (key < root->key) {
            return lookup_node(root->left, key);
        } else {
            return lookup_node(root->right, key);
        }
    }
    return NULL;
}

Node *delete(Node *root, int key, void **ret_del) {
    if (root != NULL) {
        if (key == root->key) {
            *ret_del = root->element;
            Node *ret_root;
            if (root->left == NULL) {
                ret_root = root->right;
            } else if (root->right== NULL) {
                ret_root = root->left;
            } else if (root->left->key < root->right->key) {
                ret_root = insert_node(root->left, root->right);
            } else {
                ret_root = insert_node(root->right, root->left);
            }
            free(root);
            return ret_root;
        }
        if (key < root->key) {
            root->left = delete(root->left, key, ret_del);
        } else {
            root->right = delete(root->right, key, ret_del);
        }
        return root;
    }
    *ret_del = NULL;
    return NULL;
}

void free_tree(Node *root) {
    if (root != NULL) {
        free_tree(root->right);
        free_tree(root->left);
	free(root);
    }
}
