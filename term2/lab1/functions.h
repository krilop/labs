//
// Created by krilop on 12.02.23.
//

#ifndef _FUNCTIONSFORDECOMPRESSING_H_
#define _FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
static char* pos[]={

    "CENTER",
    "FORWARD",
    "GUARD",
    "NONE"
};

typedef enum position{
    CENTER, FORWARD, GUARD, NONE
} position;
typedef struct s {
    int num;
    char* name;
    enum position pos;
} t;

char* get_str();
void createArrayOfStruct(t** array, int *sizeOfArray);
void parsing(t **array, FILE *f, int* sizeOfArray);
void printArrayOfStruct(t** array, int size);
void initializateObjectOfStruct(t** array, int *sizeOfArray);
void deleteObjectOfStruct(t** array, int* sizeOfArray);
void menu(t **array, int *sizeOfArr);
#endif //_FUNCTIONSFORDECOMPRESSING_H_
