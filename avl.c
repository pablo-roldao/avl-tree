#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

int height(tree root) {
  if (root == NULL)
    return 0;
  return root->height;
}

int max(int a, int b) { return (a > b) ? a : b; }

tree leftRotate(tree a) {
  tree c = a->right;
  tree b = c->left;

  c->left = a;
  a->right = b;

  a->height = max(height(a->left), height(a->right)) + 1;
  c->height = max(height(c->left), height(c->right)) + 1;

  return c;
}

tree rightRotate(tree d) {
  tree b = d->left;
  tree c = b->right;

  b->right = d;
  d->left = c;

  d->height = max(height(d->left), height(d->right)) + 1;
  b->height = max(height(b->left), height(b->right)) + 1;

  return b;
}

int getBalance(tree root) {
  if (root == NULL)
    return 0;
  return height(root->left) - height(root->right);
}

tree insertNode(tree root, int value) {
  if (root == NULL) {
    tree newNode = (tree)malloc(sizeof(node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
  }

  if (value < root->value) {
    root->left = insertNode(root->left, value);
  } else if (value > root->value) {
    root->right = insertNode(root->right, value);
  } else {
    return root;
  }

  root->height = max(height(root->left), height(root->right)) + 1;

  int balance = getBalance(root);

  if (balance > 1 && value < root->left->value) {
    return rightRotate(root);
  }

  if (balance > 1 && value > root->left->value) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && value > root->right->value) {
    return leftRotate(root);
  }

  if (balance < -1 && value < root->right->value) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void printPreOrder(tree root) {
  if (root != NULL) {
    printf("[%d]", root->value);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

node *getSuccessor(tree root) {
  if (root == NULL || root->right == NULL) {
    return NULL;
  }

  node *successor = root->right;
  while (successor->left != NULL) {
    successor = successor->left;
  }
  return successor;
}

tree removeNode(tree root, int value) {
  if (root == NULL) {
    return root;
  }

  if (value < root->value) {
    root->left = removeNode(root->left, value);
  } else if (value > root->value) {
    root->right = removeNode(root->right, value);
  } else {
    if (root->left == root->right) {
      free(root);
      return NULL;
    }

    if (root->left != NULL && root->right != NULL) {
      node *successor = getSuccessor(root);
      root->value = successor->value;
      root->right = removeNode(root->right, successor->value);
      return root;
    }

    if (root->left != NULL && root->right == NULL) {
      tree leftSubtree = root->left;
      free(root);
      return leftSubtree;
    }

    if (root->left == NULL && root->right != NULL) {
      tree rightSubtree = root->right;
      free(root);
      return rightSubtree;
    }
  }

  root->height = max(height(root->left), height(root->right)) + 1;

  int balance = getBalance(root);

  if (balance > 1 && getBalance(root->left) >= 0) {
    return rightRotate(root);
  }

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0) {
    return leftRotate(root);
  }

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}