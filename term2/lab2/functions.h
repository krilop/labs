//
// Created by krilop on 3/22/23.
//

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

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

void putWordsInArray(stack **head, words **arrayOfWords, int *size);

void popOutOfStack(stack **head);

void sortWords(words **arr, int size);

void pair(words **arr, int size, pairs **newArr, int *newSize);

void split(FILE **f, stack **head);

void replace(pairs ** arrayOfPairs, int countOfPairs, FILE *source, FILE *result);

void compress(char *name);

void decompress(char *name);

#endif //_FUNCTIONS_H_
