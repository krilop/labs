//
// Created by krilop on 5/6/23.
//

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#define STRING 255
#define HASH_TABLE_SIZE 5
#define INA "IN A"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cache.h"
typedef struct  file{
    FILE * file;
    char* fileName;
} file;
void clearInputBuffer();
char *readLineFromFile(file file);
char *readLineFromConsole();
char* findIp(file in, char* domain, Cache* cache);
void menu(file in);


#endif //_FUNCTIONS_H_
