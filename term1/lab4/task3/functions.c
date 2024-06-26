#include "header.h"

void inputLengthOfArray(int *length)
{
    printf("Enter the length of your matr:\t");
    while (scanf_s("%d", length) != 1 || *length < 1 || *length > 100 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}

int **memory(int N)
{
    int **mas;
    mas = (int **) calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++)
        mas[i] = (int *) calloc(N, sizeof(int));
    return mas;
}

void inputSquareMatr(int **mas, int *N)
{
    srand(time(NULL));
    int choiceOfInput;
    printf("1-random nums in array. 2-keyboard nums in array. Choose one\n");
    while (scanf_s("%d", &choiceOfInput) != 1 || choiceOfInput != 2 && choiceOfInput != 1 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    for (int i = 0; i < *N; i++)
        for (int j = 0; j < *N; j++)
            if (choiceOfInput == 1)
                *(*(mas + i) + j) = rand() % 201 - 100;
            else {
                system("cls");
                while (scanf_s("%d", (*(mas + i) + j)) != 1 || getchar() != '\n') {
                    printf("Error! Try again\n");
                    rewind(stdin);
                }
            }
}

void printMatr(int **mas, int *length)
{
    for (int i = 0; i < *length; i++) {
        for (int j = 0; j < *length; j++)
            printf("%d\t", *(*(mas + i) + j));
        printf("\n");
    }
}

void tryToEnd(int *check)
{
    printf("May I end the programm?(yes-1, no-0)\n");
    while (scanf_s("%d", check) != 1 || *check != 1 && *check != 0 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    if (*check == 0)
        system("cls");
}