#ifndef Functions_H
#define Functions_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputLengthOfArray(int *length);

void randomArray(int *arr, int length);

void deleteEven(int *arr, int *length);

void shiftArray(int *arr, int *length, int i);

void printArray(int *arr, int length);

void resetApp(int *reset);

#endif