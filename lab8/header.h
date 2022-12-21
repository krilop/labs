#ifndef Functions_H
#define Functions_H

void copyArray(char **resouce, char **result, int howManyStrings);

void printArray(char **arr, int howManyStrings);

void deleteFirstString(char **arr,
                       int howManyStrings);//����� ������� ����� �������, �������� ��������� ���� ����������� � ������, � �� �� �����
int getLength(char **s, int posOfString);

void merge(char **arr, int first, int last);

void mergeSort(char **arr, int first, int last);

#endif