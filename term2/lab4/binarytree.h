#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Node
{
    char* question;
    struct Node* left;
    struct Node* right;
    int height;
} node;

node *newNode(char *value);
void balance(node* root);
void leftRotate(node* root);
void rightRotate(node* root);
void swap(node* a, node* b);
int getBalance(node* root);
int updateHeight(node* nd);
void updateAllHeights(node* nd);
int getHeight(node* root);
void freeTree(node* root);

#endif //_BINARYTREE_H_