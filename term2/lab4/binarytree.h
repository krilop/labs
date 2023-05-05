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


#endif //_BINARYTREE_H_