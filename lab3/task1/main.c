/*
15.	В одномерном массиве, состоящем из n вещественных элементов, вычислить:
- количество элементов массива, равных 0;
- сумму элементов массива, расположённых после минимального элемента.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int powerTen();
int main()
{
    srand(time(NULL));
    int choice_of_input;
    float rd;
    float ten;
    printf("chose the way of inputting for array 1: 1 for random input and 2 for keyboard input  ");
    while (scanf_s("%d", &choice_of_input) != 1 || choice_of_input != 1 && choice_of_input != 2)
    {
        printf("try again\n");
        rewind(stdin);
    }
    float array1[100];
    int n = 100;
    printf("input the size of array  ");
    while (scanf_s("%d", &n) != 1||n<2||n>100)
    {
        printf("try again\n");
        rewind(stdin);
    }

    for (int i = 0; i < n; i++)
        if (choice_of_input == 1)
        {
            rd = rand() % 201-100;
            ten = powerTen();
            array1[i] = rd / ten;
            printf("%f\t",array1[i]);
        }
        else
            while (scanf_s("%f", &array1[i]) != 1)
            {
                printf("try again\n");
                rewind(stdin);
            }
    int choice;
    printf("What do I need to do?\n1) Calculate the number of array elements that are 0;\n2) Calculate the sum of the array elements after the minimum element.");
    while (scanf_s("%d", &choice) != 1 || choice != 1 && choice != 2)
    {
        printf("try again\n");
        rewind(stdin);
    }
    if (choice==1)
    {
        int count=0;
        for (int i = 0; i < n; i++)
            if (array1[i] == 0)
                count++;
        printf("number of array elements equal to 0: %d",count);
    }
    else
    {
        int ind_min = 0;
        float min = array1[0];
        float sum = 0;
        for (int i = 0; i < n; i++)
            if (array1[i]<min)
            {
                min = array1[i];
                ind_min = i;
            }
        for (int i = ind_min+1; i < n; i++)
            sum += array1[i];
        printf("the sum of the array elements after the minimum element: %f", sum);
    }
    return 0;
}
int powerTen()
{
    int a = rand() % 7;
    int num = 10;
    for (int i = 1; i < a; i++)
        num *= 10;
    return num;
}