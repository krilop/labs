#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binarytree.h"


int getAnswer(char* question);
void startGame(node* root);
node* loadDB(FILE *DB);
void saveDB(node* nd, FILE * DB);

#endif //_FUNCTIONS_H_
