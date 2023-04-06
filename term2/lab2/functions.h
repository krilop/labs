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
} words;
typedef struct p {
    char *word1;
    char *word2;
} pairs;

char *readFile(char *nameOfFile);

//stack* FindNext(stack* head,stack* next);
//void bubbleSort(stack *head);
void pushInStack(stack **head, char *word);

void putWordsInArray(stack **head, words **arrayOfWords, int *size);

void popOutOfStack(stack **head);

void sortWords(words **arr, int size);

void pair(words **arr, int size, pairs **newArr, int *newSize);
//void split(char *buffer, char *delimiter, words* arrayOfWords);
void split(FILE **f, stack **head);

//void putWordsInTheStack(stack **head, words* arrayOfWords);

int doesItExist(stack *head, char *string);

int calculateTheProfit(stack *word1, stack *word2);

void markWord(stack *head, char *word);

//void swap(words * arrayOfWords, char *a, char *b);

//void replace(stack *head, words* arrayOfWords, char *name);


void compress(char *name);

void decompress(char *name);

#endif //_FUNCTIONS_H_
