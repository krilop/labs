#include "header.h"

void inputLength(int *length)
{
    while (scanf_s("%d", length) != 1 || *length < 1 || *length > 100 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}

void inputArr(int **parr, int str, int col)
{
    srand(time(NULL));
    printf("Choose the way of input(1-keyboard,2-random)\n");
    int way;
    while (scanf_s("%d", &way) != 1 || way != 1 && way != 2 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    if (way == 1)
        for (int i = 0; i < str; i++)
            for (int j = 0; j < col; j++)
            {
                printf("The element which placed on string %d, column %d equals ...\t", i + 1, j + 1);
                while (scanf_s("%d", *(parr + i) + j) != 1 || getchar() != '\n')
                {
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
        for (int j = 0; j < col; j++)
        {
            if (j % 10 == 0)
                printf("\n");
            printf("%d\t", *(*(parr + i) + j));
        }
    printf("\n");
}

/*строк по возрастанию произведения отрицательных элементов*/
int productOfNegativeElements(int **arr, int numOfString, int lengthOfString)
{
    int flag = 0;
    int prod = 1;
    for (int i = 0; i < lengthOfString; i++)
        if (*(*(arr + numOfString) + i) < 0)
        {
            flag = 1;
            prod *= *(*(arr + numOfString) + i);
        }
    if (flag == 0)
        return 0;
    return prod;
}

void mergeSort(int **arr, int left, int right, int lengthOfString)
{
    if (left == right) return; // границы сомкнулись
    int mid = (left + right) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    mergeSort(arr, left, mid, lengthOfString);
    mergeSort(arr, mid + 1, right, lengthOfString);
    int i = left;  // начало первого пути
    int j = mid + 1; // начало второго пути
    int **tmp = (int **) malloc(right * sizeof(int *)); // дополнительный массив
    for (int step = 0; step < right - left + 1; step++) // для всех элементов дополнительного массива
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if ((j > right) || ((i <= mid) && (productOfNegativeElements(arr, i, lengthOfString) <
                                           productOfNegativeElements(arr, j, lengthOfString))))
        {
            *(tmp + step) = *(arr + i);
            i++;
        } else
        {
            *(tmp + step) = *(arr + j);
            j++;
        }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < right - left + 1; step++)
        *(arr + left + step) = *(tmp + step);
}

void printProductOfStr(int **arr, int str, int col)
{
    for (int i = 0; i < str; i++)
        printf("prod of str %d equals %d\n", i + 1, productOfNegativeElements(arr, i, col));
}

void reset(int *reset)
{
    while (scanf_s("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}