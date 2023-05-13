//
// Created by krilop on 5/6/23.
//

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list
{
    char* key;
    char* value;
    struct list* prev;
    struct list* next;
}list;
#endif //_FUNCTIONS_H_
