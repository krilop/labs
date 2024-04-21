#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int arr_choice1;
    printf("enter the way to set the FIRST array (keyboard input / random)\n");
    while (scanf_s("%d", &arr_choice1) != 1 || arr_choice1 != 1 && arr_choice1 != 2)//�������� �� ����
    {
        printf("try again\n");
        rewind(stdin);
    }
    int array1[30];
    int n = 30;
    if (arr_choice1 == 1) {
        printf("Input array");
        for (int i = 0; i < n; i++) {
            printf("\n%d-th digit of the number=", i + 1);
            while (scanf_s("%d", &array1[i]) != 1)//�������� �� ����
            {
                printf("try again\n");
                rewind(stdin);
            }
        }
    } else {
        for (int i = 0; i < n; i++)
            array1[i] = rand() % 10;
    }
    int array2[30];
    int arr_choice2;
    printf("enter the way to set the SECOND array (keyboard input / random)\n");
    while (scanf_s("%d", &arr_choice2) != 1 || arr_choice2 != 1 && arr_choice2 != 2)//�������� �� ����
    {
        printf("try again\n");
        rewind(stdin);
    }
    if (arr_choice2 == 1)
        for (int i = 0; i < n; i++) {
            printf("\n%d-th digit of the number=", i + 1);
            while (scanf_s("%d", &array2[i]) != 1)//�������� �� ����
            {
                printf("try again\n");
                rewind(stdin);
            }
        }
    else
        for (int i = 0; i < n; i++)
            array2[i] = rand() % 10;
    for (int i = 0; i < n; i++)
        printf("%d", array1[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d", array2[i]);
    //�����
    for (int i = n - 1; i >= 0; i--) {
        array1[i] += array2[i];
        if (array1[i] > 9) {
            if (i == 0)
                break;
            array1[i - 1]++;
            array1[i] -= 10;
        }
    }
    printf("\nThe sum of the array elements is ...\n");
    for (int i = 0; i < n; i++)
        printf("%d", array1[i]);
    return 0;
}
