#ifndef Functions_H
#define Functions_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copyArray(char **resouce, char **result, int howManyStrings);

void printArray(char **arr, int howManyStrings);

void deleteFirstString(char **arr,
                       int howManyStrings);//����� ������� ����� �������, �������� ��������� ���� ����������� � ������, � �� �� �����
int getLength(char *s);

void mergeSort(char **arr, int first, int last);

#endif
