#include "header.h"

void inputLengthOfArray(int *length)
{
    printf("Enter the length of your array:\t");
    while (scanf_s("%d", length) != 1 || *length < 1 || *length > 100 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}

void randomArray(int *arr, int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        *(arr + i) = rand() % 201;
        if (*(arr + i) % 2 == 1)
            i--;
    }

}

void deleteEven(int *arr, int *length)
{
    for (int i = 0; i < *length; i++)
        if (*(arr + i) % 2 == 0) {
            shiftArray(arr, length, i);
            i--;
        }
}

void shiftArray(int *arr, int *length, int j)
{
    for (int i = j; i < *length - 1; i++)
        *(arr + i) = *(arr + i + 1);
    *length -= 1;
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d\t", *(arr + i));
    printf("\n");
}

void resetApp(int *reset)
{
    printf("Do you want to use programm again?(yes - 1, no - 0)\t");
    while (scanf_s("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}