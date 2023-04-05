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
    size_t length;
    int count;
    int flagOfUsing;
    struct LIFO *next;
} stack;
typedef struct w {
    char **word;
    int length;
} words;

char *readFile(char *nameOfFile);
//stack* FindNext(stack* head,stack* next);
//void bubbleSort(stack *head);
void pushInStack(stack **head, char* word, int cnt);

void popOutOfStack(stack **head);

void split(char *buffer, char *delimiter, words* arrayOfWords);

void putWordsInTheStack(stack **head, words* arrayOfWords);

int doesItExist(stack *head, char *string);

int calculateTheProfit(stack *word1, stack *word2);

void markWord(stack *head, char *word);

void swap(words * arrayOfWords, char *a, char *b);

void replace(stack *head, words* arrayOfWords, char *name);


void compress(char *name);

void decompress(char *name);

#endif //_FUNCTIONS_H_
