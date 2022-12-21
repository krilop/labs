#ifndef Functions_H
#define Functions_H
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reset(int *reset);

void inputLength(int *length);

void inputArr(int **parr, int str, int col);

void printArr(int **parr, int str, int col);

void printProductOfStr(int **arr, int str, int col);

int productOfNegativeElements(int **arr, int numOfString, int lengthOfString);

void mergeSort(int **arr, int left, int right, int lengthOfString);

#endif Functions_H