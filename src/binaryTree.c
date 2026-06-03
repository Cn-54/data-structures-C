#include "binaryTree.h"
#include <stdlib.h>


struct Node{
    void *data;
    struct Node *left;
    struct Node *right;
};

struct Tree{
    struct Node *root;
};

BT *create() {
    BT *tree = malloc(sizeof(BT));
    if (!tree) return NULL;
    tree->root = NULL;
    return tree;
}

Node *newNode(void *data) {
    Node *node = malloc(sizeof(Node));
    if (!node) return NULL;
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

void setLeft(Node *parent, Node *child) {
    if (!parent) return;
    parent->left = child;
}

void bt_setRight(Node *parent, Node *child) {
    if (!parent) return;
    parent->right = child;
}

void *getData(Node *node) {
    if (!node) return NULL;
    return node->data;
}

Node *getLeft(Node *node) {
    if (!node) return NULL;
    return node->left;
}

Node *getRight(Node *node) {
    if (!node) return NULL;
    return node->right;
}

Node *getRoot(BT *tree) {
    if (!tree) return NULL;
    return tree->root;
}

void setRoot(BT *tree, Node *node) {
    if (!tree) return;
    tree->root = node;
}

static void destroyNodes(Node *node) {
    if (!node) return;
    destroyNodes(node->left);
    destroyNodes(node->right);
    free(node->data);
    free(node);
}

void bt_destroy(BT *tree) {
    if (!tree) return;
    destroyNodes(tree->root);
    free(tree);
}