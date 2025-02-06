#ifndef AVL_H
#define AVL_H

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node;

typedef node *tree;

tree insertNode(tree root, int value);
void printPreOrder(tree root);
tree removeNode(tree root, int value);

#endif