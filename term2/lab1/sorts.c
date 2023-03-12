//
// Created by krilop on 2/24/23.
//
// попробуем сделать через компаратор.
#include "sorts.h"
void sortStart(t** array, int *sizeOfArray)
{
    printf("Hello! I'm master of sorting. Please, select criteria of sort:\n0.Return\n1.Number of player\n 2.Name\n3.Position\n");
    int select;
    while (!scanf("%d", &select) || select < 0||select > 5||getchar()!='\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    switch (select) {
        case 0:
            return;
        break;
        case 1:
            sort(array, sizeOfArray, comprNum);
            break;
        case 2:
            sort(array, sizeOfArray, comprStr);
            break;
        case 3:
            sort(array, sizeOfArray, comprEnum);
            break;
        case 4:

            break;
    }

}

void sort(t** array,int*  sizeOfArray, int (*function)(t* array, int indFirst, int indSecond))
{
    for (int i = 0; i <*sizeOfArray ; i++)
        for (int j = 0; j < *sizeOfArray; j++)
            if((*function)(array,i,j))
                swap(&array[i], &array[j]);
    printf("Are u want to inverse?(1-yes/0-no)\n");
    int select;
    while (!scanf("%d", &select) || select!=0&&select!=1||getchar()!='\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    if(select)
        inverse(array, sizeOfArray);
    printf("Please, select second criteria of sort:\n0.Return\n1.Number of player\n 2.Name\n3.Position\n");
    while (!scanf("%d", &select) || select < 0||select > 5||getchar()!='\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    switch (select) {
        case 0:
            return;
            break;
        case 1:
            secondSort(array, sizeOfArray, comprNum,(*function));
            break;
        case 2:
            secondSort(array, sizeOfArray, comprStr,(*function));
            break;
        case 3:
            secondSort(array, sizeOfArray, comprEnum,(*function));
            break;
        case 4:

            break;
    }

}
void secondSort(t** array, int* sizeOfArray,int (*function)(t* array, int indFirst, int indSecond), int (*function2)(t* array, int indFirst, int indSecond))
{
    if(*function==comprNum)
        for (int i = 0; i <*sizeOfArray ; i++)
            for (int j = 0; j < *sizeOfArray; j++){
                if((array[i].num==array[j].num)&&((*function)(array,i,j)))
                    swap(&array[i], &array[j]);}
    else if(*function==comprStr)
        for (int i = 0; i <*sizeOfArray ; i++)
            for (int j = 0; j < *sizeOfArray; j++){
                if(((*array)[i].name==(*array)[j].name)&&((*function)(array,i,j)))
                    swap(&array[i], &array[j]);}
        else if(*function==comprEnum)
            for (int i = 0; i <*sizeOfArray ; i++)
                for (int j = 0; j < *sizeOfArray; j++)
                    if(((*array)[i].pos==(*array)[j].pos)&&((*function)(array,i,j)))
                        swap(&array[i], &array[j]);
}
int comprNum(t* array, int indFirst, int indSecond)
{
    int num= (array[indFirst].num)>(array[indSecond].num)? 1:0;
    return num;
}
int comprStr(t* array, int indFirst, int indSecond)
{
    return strcmp(array[indFirst].name, array[indSecond].name);
}
int comprEnum(t* array, int indFirst, int indSecond)
{
    int num = (array[indFirst].pos)>(array[indSecond].pos)? 1:0;
    return num;
}

void inverse(t**array,int* sizeOfArray)
{
    t* tmp= array[0];
    for (int i = 0; i<*sizeOfArray-2; i++)
        swap(&array[i],&array[i+1]);
    array[*sizeOfArray-1]=tmp;
}

 void swap (t **a, t **b) {
    t* tmp = *a;
    *a = *b;
    *b = tmp;
}
/*
void insertion_sort (COMPANIES_STRUCT *mas, int n) {
    for (int k = 1; k < n; k++)
        for (int i = k; i > 0 && mas[i - 1].salary >= mas[i].salary; i--) {
            if (mas[i - 1].salary > mas[i].salary)
                swap(&mas[i], &mas[i - 1]);
            else {
                if (mas[i - 1].sex > mas[i].sex)
                    swap(&mas[i], &mas[i - 1]);
            }
        }
}
 */