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
void clearInputBuffer();
char *readLineFromFile(FILE* file);
char *readLineFromConsole();
void menu(FILE* in, char* name);


#endif //_FUNCTIONS_H_
