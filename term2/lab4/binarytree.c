#include "binarytree.h"

node *newNode(char *value)
{
    node *tmp = (node *) malloc(sizeof(node));
    (*tmp).question = (char*)calloc(strlen(value)+1, sizeof(char));
    (*tmp).question=strcpy((*tmp).question,value);
    (*tmp).question[strlen(value)]='\0';
    (*tmp).left = NULL;
    (*tmp).right = NULL;
    (*tmp).height=0;
    return tmp;
}
int getHeight(node* root)
{
    return root==NULL? -1:root->height;
}
int getMax(int a, int b)
{
    return a>b? a:b;
}
int updateHeight(node* nd) {
    int left_height = (nd->left != NULL) ? nd->left->height : -1;
    int right_height = (nd->right != NULL) ? nd->right->height : -1;
    (*nd).height = 1 + getMax(left_height, right_height);
    return nd->height;
}

void updateAllHeights(node* nd) {
    if (nd != NULL) {
        updateAllHeights(nd->left);
        updateAllHeights(nd->right);
        updateHeight(nd);
    }
}

int getBalance(node* root)
{
    return (root==NULL)? 0: getHeight((*root).right)-getHeight((*root).left);
}
void swap(node* a, node* b)
{
    char* tmp=(char*)malloc((1+strlen((*a).question))*sizeof(char));
    tmp=strdup((*a).question);
    (*a).question=(char*)realloc((*a).question,1+strlen((*b).question));
    (*a).question=strdup((*b).question);
    (*b).question=(char*)realloc((*b).question,1+strlen(tmp));
    (*b).question=strdup(tmp);
    free(tmp);
}
void rightRotate(node* root)
{
    swap(root,(*root).left);
    node* buffer=(*root).right;
    (*root).right=(*root).left;
    (*root).left=(*(*root).right).left;
    (*(*root).right).left=(*(*root).right).right;
    (*(*root).right).right=buffer;
    updateHeight((*root).right);
    updateHeight(root);
    free(buffer);
}
void leftRotate(node* root)
{
    swap(root, (*root).right);
    node* buffer = (*root).left;
    (*root).left = (*root).right;
    (*root).right = (*(*root).left).right;
    (*(*root).left).right = (*(*root).left).left;
    (*(*root).left).left = buffer;
    updateHeight((*root).left);
    updateHeight(root);
    free(buffer);
}
void balance(node* root)
{
    if (root == NULL)
        return;
    int balanceFactor = getBalance(root);
    if (balanceFactor > 1)
    {
        if (getBalance((*root).right) < 0)
        {
            rightRotate((*root).right);
        }
        leftRotate(root);
    }
    else if (balanceFactor < -1)
    {
        if (getBalance((*root).left) > 0)
        {
            leftRotate((*root).left);
        }
        rightRotate(root);
    }
}
void freeTree(node* root)
{
    if(root==NULL)
        return;
    freeTree((*root).left);
    freeTree((*root).right);
    free((*root).question);
    free(root);
}