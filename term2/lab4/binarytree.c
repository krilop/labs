#include "binarytree.h"

node *newNode(char *value)
{
    node *tmp = (node *) malloc(sizeof(node));
    (*tmp).question = (char*)calloc(strlen(value)+1, sizeof(char));
    (*tmp).question = strdup(value);
    (*tmp).question[strlen(value)]='\0';
    (*tmp).left = NULL;
    (*tmp).right = NULL;
    return tmp;
}
