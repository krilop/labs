#include "binarytree.h"

node *newNode(char *value)
{
    node *tmp = (node *) malloc(sizeof(node));
    (*tmp).question = (char*)calloc(strlen(value)+1, sizeof(char));
    (*tmp).question = strdup(value);
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
void updateHeight(node* root)
{
    (*root).height=getMax(getHeight((*root).left),getHeight((*root).right))+1;
}
int getBalance(node* root)
{
    return (root==NULL)? 0: getHeight((*root).right)-getHeight((*root).left);
}
void swap(node* a, node* b)
{
    char* tmp=(char*)calloc(1+strlen((*a).question), sizeof(char));
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
    swap(root,(*root).right);
    node* buffer=(*root).left;
    (*root).left=(*root).right;
    (*root).right=(*(*root).left).right;
    //(*(*root).right).left=(*(*root).right).right;
    (*(*root).left).right=(*(*root).left).left;
    (*(*root).left).left=buffer;
    updateHeight((*root).left);
    updateHeight(root);
    free(buffer);
}
void balance(node* root)
{
    int balance= getBalance(root);
    if(balance==-2)
    {
        if(getBalance((*root).left)==1) leftRotate((*root).left);
        rightRotate(root);
    }
    else if(balance==2)
    {
        if(getBalance((*root).right)==1) rightRotate((*root).right);
        leftRotate(root);

    }

}