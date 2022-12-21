#include "header.h"

void copyArray(char **resouce, char **result, int howManyStrings)
{
    for (int i = 0; i < howManyStrings; i++)
        for (int j = 0; j < getLength(resouce, i); j++)
            *(*(result + i) + j) = *(*(resouce + i) + j);
}

void printArray(char **arr, int howManyStrings)
{
    for (int i = 0; i < howManyStrings; i++)
        printf("%s\n", *(arr + i));
}

void deleteFirstString(char **arr, int howManyStrings)
{
    for (int i = 0; i < howManyStrings - 1; i++)
        *(arr + i) = *(arr + i + 1);
}

int getLength(char **s, int posOfString)
{
    int cnt = 0, i = 0;
    while (*(*(s + posOfString) + i) != '\0')
    {
        cnt++;
        i++;
    }
    return cnt + 1;
}

void merge(char **arr, int first, int last)
{
    int middle, start, end, j;
    //int* mas = new int[100];
    char **tmp = (char **) malloc((last) * sizeof(char *));
    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    end = middle + 1; //начало правой части
    for (j = first; j <= last; j++) //выполнять от начала до конца
        if ((start <= middle) && ((end > last) || (getLength(arr, start) > getLength(arr, end))))
        {
            *(tmp + j) = *(arr + start);
            start++;
        } else
        {
            *(tmp + j) = *(arr + end);
            end++;
        }
    //возвращение результата в список
    for (j = first; j <= last; j++)
        *(arr + j) = *(tmp + j);
};

//рекурсивная процедура сортировки
void mergeSort(char **arr, int first, int last)
{
    if (first < last)
    {
        mergeSort(arr, first, (first + last) / 2); //сортировка левой части
        mergeSort(arr, (first + last) / 2 + 1, last); //сортировка правой части
        merge(arr, first, last); //слияние двух частей
    }
};
