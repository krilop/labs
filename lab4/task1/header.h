#ifndef Functions_H
#define Functions_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputLengthOfArray(int *length);

void inputSquareMatr(int **mas, int N);

int **memory(int n);

void printMatr(int **mas, int length);

void partOneOfTask(int **mas, int length);

void partTwoOfTask(int **arr, int length);

void tryToEnd(int *check);

#endif