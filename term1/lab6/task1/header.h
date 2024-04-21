#ifndef Functions_H
#define Functions_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reset(int *reset);

void inputLength(int *length);

void randWorse(int *parr, int length);

void inputArr(int *parr, int length);

void printArr(int *parr, int length);

void swap(int *a, int *b);

void power(int *multiple, int a, int b);

void findInd(int *parr, int length, int *ind);

void sortShell(int *parr, int length, int indFirstPositive);

void sortBubble(int *parr, int length, int indFirstPositive);

void copyArr(int *adress, int *letter, int length);

#endif