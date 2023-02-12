/*2.	В двумерном массиве натуральных чисел (количество чисел в строке может быть различным, последнее число - 0) удалить строку с минимальной суммой элементов (порядок остальных строк не менять).*/
#include "header.h"

int main()
{
    int restart = 1;
    while (restart)
    {
        int **pparr;
        printf("How many strings do you want to have?\t");
        int string;
        int *pstring = &string;
        inputLengthOfArray(pstring);
        pparr = (int **) malloc(string * sizeof(int *));
        for (int i = 0; i < string; i++)
            *(pparr + i) = (int *) malloc(sizeof(int));
        for (int i = 0; i < string; i++)
            inputString(pparr, i);
        int minOfSum;
        printArr(pparr, string);
        minimum(pparr, string, &minOfSum);
        deleteString(pparr, pstring, minOfSum);
        pparr = (int **) realloc(pparr, string * sizeof(int *));
        printArr(pparr, string);
        for (int i = 0; i < string; i++)
            free(*(pparr + i));
        free(pparr);
        printf("Do you want to use programm again?(yes - 1, no - 0)\t");
        reset(&restart);
    }
    return 0;
}