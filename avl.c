#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

tree insertNode(tree root, int value) {
    //to do
    return NULL;
}

void printPreOrder(tree root) {
    if (root != NULL) {
        printf("%d", root->value);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

tree removeNode(tree root, int value) {
    //to do
    return NULL;
}