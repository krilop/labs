/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>*/
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
        mas[i] = (int *) calloc(N, sizeof(int)); //*(mas + i)
    return mas;
}

void inputSquareMatr(int **mas, int N)
{
    srand(time(NULL));
    int choiceOfInput;
    printf("1-random nums in array. 2-keyboard nums in array. Choose one\n");
    while (scanf_s("%d", &choiceOfInput) != 1 || choiceOfInput != 2 && choiceOfInput != 1 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
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

void printMatr(int **mas, int length)
{
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++)
            printf("%d\t", *(*(mas + i) + j));
        printf("\n");
    }
}


void partOneOfTask(int **mas, int N)
{
    int flagForNegative = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (*(*(mas + j) + i) < 0) {
                flagForNegative = 1;
                break;
            }
        if (flagForNegative == 1) {
            flagForNegative = 0;
            continue;
        }
        for (int j = 0; j < N; j++) {
            sum += *(*(mas + j) + i);
            if (j == N - 1) {
                printf("sum of column %d = %d\n", i + 1, sum);
                sum = 0;
            }
        }
    }
}

void partTwoOfTask(int **mas, int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (*(*(mas + i) + j) < 0)
                *(*(mas + i) + j) *= -1;
    int num;
    int arrayOfSum[100];
    for (int i = 0; i < 100; ++i)
        arrayOfSum[i] = 0;
    for (int i = 0; i < N * 2 - 1; i++)
        arrayOfSum[i] = 0;
    for (int j = 0; j < N - 1; j++) {
        num = j;
        for (int i = 0; num - i >= 0; i++)
            arrayOfSum[j] += mas[num - i][i];
    }
    num = N - 1;
    for (int i = 0; num - i >= 0; i++)
        arrayOfSum[N - 1] += mas[num - i][i];

    for (int j = N - 1; j > 0; j--) {
        num = N - j;
        for (int i = 0; num + i < N; i++)
            arrayOfSum[N * 2 - j - 1] += mas[num + i][N - i - 1];
    }
    int min = arrayOfSum[0];
    for (int i = 0; i < N * 2 - 1; i++)
        if (arrayOfSum[i] < min)
            min = arrayOfSum[i];
    printf("minimum of diagonals : %d\n", min);

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
