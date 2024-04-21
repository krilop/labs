#include "header.h"

void copyArray(char **resouce, char **result, int howManyStrings)
{
    for (int i = 0; i < howManyStrings; i++)
        for (int j = 0; j < getLength(resouce[i]); j++)
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

int getLength(char *s)
{
    int cnt = 0, i = 0;
    while (*(s + i) != '\0') {
        cnt++;
        i++;
    }
    return cnt + 1;
}

void mergeSort(char** a, int l, int r)  //Сортирока слиянием без доп массива
{
    int m = (l + r) / 2;
    if (l == r)
        return;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    int i = l, j = m + 1, k;
    char* el;
    while (i <= m && j <= r)
    {
        if (getLength(a[j]) > getLength(a[i]))
        {
            el = a[j];
            for (k = j; k > i; k--)
                a[k] = a[k - 1];
            a[i] = el;
            m++;
            i++;
            j++;
            continue;
        }
        i++;
    }
}
