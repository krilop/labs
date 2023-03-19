//
// Created by krilop on 2/24/23.
//

#ifndef _SORTS_H_
#define _SORTS_H_
#include "functions.h"
void sortStart(t* array, int sizeOfArray);
void sort(t* array, int sizeOfArray, int (*function)(t* array, int indFirst, int indSecond));
void secondSort(t* array, int sizeOfArray, int (*function)(t* array, int indFirst, int indSecond),int (*function2)(t* array, int indFirst, int indSecond));
int comprNum(t* array, int indFirst, int indSecond);
int comprStr(t* array, int indFirst, int indSecond);
int comprEnum(t* array, int indFirst, int indSecond);
void swap (t* array, int a, int b);
void inverse(t*array,int sizeOfArray);

#endif //_SORTS_H_
