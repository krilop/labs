#ifndef Functions_H
#define Functions_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputLengthOfArray(int *length);

void inputMatr(int **mas, int *row, int *col);

int **memory(int n);

void printMatr(int **mas, int *row, int *col);

void tryToEnd(int *check);

#endif