/*1.	Заполнить массив случайными числами. Удалить из массива все элементы с чётным значением.*/
#include "header.h"

int main()
{

    int reset = 1;
    while (reset)
    {
        int length;
        int *plength = &length;
        inputLengthOfArray(plength);
        int *parr = (int *) calloc(length, sizeof(int));
        randomArray(parr, length);
        printArray(parr, length);
        deleteEven(parr, plength);
        parr = (int *) realloc(parr, length * sizeof(int));
        printArray(parr, length);
        free(parr);
        resetApp(&reset);
    }

    return 0;
}