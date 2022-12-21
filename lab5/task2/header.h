#ifndef Functions_H
#define Functions_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputLengthOfArray(int *length);

void reset(int *reset);

void inputString(int **arr, int j);

void printArr(int **pparr, int string);

void deleteString(int **arr, int *string, int minOfSum);

void minimum(int **arr, int string, int *minOfSum);

#endif