#ifndef _FUNCTIONSFORDECOMPRESSING_H_
#define _FUNCTIONSFORDECOMPRESSING_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct LIFO {
    char *word;
    struct LIFO *next;
} stack;

typedef struct w {
    char *word;
    int count;
    int markAsUsed;
} words;
typedef struct p {
    char *word1;
    char *word2;
} pairs;

void pushInStack(stack **head, char *word);

void popOutOfStack(stack **head);

void pair(words **arr, int size, pairs **newArr, int *newSize);

void split(FILE **f, stack **head);

void replace(pairs ** arrayOfPairs, int countOfPairs, FILE *source, FILE *result);

void decompress(char *name);

#endif //_FUNCTIONSFORDECOMPRESSING_H_
