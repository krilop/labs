#include "header.h"

void inputLength(int *length)
{
    while (scanf("%d", length) != 1 || *length < 1 || *length > 100 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}

void inputArr(int **parr, int str, int col)
{
    srand(time(NULL));
    printf("Choose the way of input(1-keyboard,2-random)\n");
    int way;
    while (scanf("%d", &way) != 1 || way != 1 && way != 2 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    if (way == 1)
        for (int i = 0; i < str; i++)
            for (int j = 0; j < col; j++) {
                printf("The element which placed on string %d, column %d equals ...\t", i + 1, j + 1);
                while (scanf("%d", *(parr + i) + j) != 1 || getchar() != '\n') {
                    printf("Error! Try again\n");
                    rewind(stdin);
                }
                printf("\n");
            }
    else
        for (int i = 0; i < str; i++)
            for (int j = 0; j < col; j++)
                *(*(parr + i) + j) = rand() % 20 - 10;
}

void printArr(int **parr, int str, int col)
{
    for (int i = 0; i < str; i++)
        for (int j = 0; j < col; j++) {
            if (j % 10 == 0)
                printf("\n");
            printf("%d\t", *(*(parr + i) + j));
        }
    printf("\n");
}

/*строк по возрастанию произведения отрицательных элементов*/
int productOfNegativeElements(int *arr, int lengthOfString)
{
    int flag = 0;
    int prod = 1;
    for (int i = 0; i < lengthOfString; i++)
        if (*(arr + i) < 0) {
            flag = 1;
            prod *= *(arr + i);
        }
    if (flag == 0)
        return 0;
    return prod;
}

void mergeSort(int** a, int l, int r, int lengthOfStr)  //Сортирока слиянием без доп массива
{
    int m = (l + r) / 2;
    if (l == r)
        return;
    mergeSort(a, l, m, lengthOfStr);
    mergeSort(a, m + 1, r, lengthOfStr);
    int i = l, j = m + 1, k;
    int* el;
    while (i <= m && j <= r)
    {
        if (productOfNegativeElements(a[j],lengthOfStr) < productOfNegativeElements(a[i], lengthOfStr))
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


void printProductOfStr(int **arr, int str, int col)
{
    for (int i = 0; i < str; i++)
        printf("prod of str %d equals %d\n", i + 1, productOfNegativeElements(*(arr+i), col));
}

void reset(int *reset)
{
    while (scanf("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}
