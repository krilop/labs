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
void updateHeight(node* root);
int getHeight(node* root);

#endif //_BINARYTREE_H_