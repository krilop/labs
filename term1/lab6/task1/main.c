/*1.	� ���������� ������� ��������� ���������� ��������� ������������� ����� ������� �������������� ������� �����
��� 1-� ������ ���������� �������� ����� ���������� ���������� � �������� �/��� ������������� (��������� ����� �� ������� �������� ������� � 1000, 10000). 
� �������� ��������� ������� ���������� � ������ �������� �� ��� �����, ��������, ���������. ����� ����������� ������� ������ (������ ������������ � �������� �������).*/
#include "header.h"

int main()
{
    int restart = 1;
    int *parr;
    parr = (int *) malloc(sizeof(int));
    int *parr2 = (int *) malloc(sizeof(int));
    while (restart) {
        clock_t start, end;
        printf("How many numbers do u want to have?\n");
        int length;
        inputLength(&length);
        parr = (int *) realloc(parr, length * sizeof(int));
        printf("Do u want the worse variant?(1-yes,no-0)\n");
        int choice;
        reset(&choice);
        if (choice)
            randWorse(parr, length);
        else
            inputArr(parr, length);
        parr2 = (int *) realloc(parr2, length * sizeof(int));
        copyArr(parr2, parr, length);
        //printArr(parr, length);
        //printArr(parr2, length);
        int indFirstPositive = -1;
        findInd(parr, length, &indFirstPositive);
        if (indFirstPositive == -1)
            printf("There is no positive nums");
        else {
            start = clock();
            sortShell(parr, length, indFirstPositive);
            end = clock();
            float result1 = (float) (end - start) / CLOCKS_PER_SEC;
            printf("\n");
            start = clock();
            sortBubble(parr2, length, indFirstPositive);
            end = clock();
            float result2 = (float) (end - start) / CLOCKS_PER_SEC;
            //printArr(parr, length);
            //printArr(parr2, length);
            printf("time of sort first:%f\ntime of sort Bubble:%f\n", result1, result2);/*time of sort first:%f\n*/
        }
        printf("Do u want to run app again?(yes-1, no-0)");
        reset(&restart);
    }
    free(parr);
    free(parr2);
    return 0;
}