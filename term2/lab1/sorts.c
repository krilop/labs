#include "sorts.h"
void sortStart(t *array, int sizeOfArray)
{
    printf("Hello! I'm master of sorting. Please, select criteria of sort:\n0.Return\n1.Number of player\n 2.Name\n3.Position\n");
    int select;
    while (!scanf("%d", &select) || select < 0 || select > 5 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    switch (select) {
        case 0:
            return;
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

void sort(t *array, int sizeOfArray, int (*function)(t *array, int indFirst, int indSecond))
{

    for (int i = 0; i < sizeOfArray; i++) {
        for (int j = 0; j < sizeOfArray; j++) {
            if (!(*function)(array, i, j))
                swap(array, i,j);
        }
    }
    printf("Are u want to inverse?(1-yes/0-no)\n");
    int select;
    while (!scanf("%d", &select) || select != 0 && select != 1 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    if (select)
        inverse(array, sizeOfArray);
    printf("Please, select second criteria of sort:\n0.Return\n1.Number of player\n 2.Name\n3.Position\n");
    while (!scanf("%d", &select) || select < 0 || select > 5 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    switch (select) {
        case 0:
            return;
        case 1:
            secondSort(array, sizeOfArray, (*function),comprNum );
            break;
        case 2:
            secondSort(array, sizeOfArray, (*function),comprStr );
            break;
        case 3:
            secondSort(array, sizeOfArray, (*function),comprEnum );
            break;
        case 4:

            break;
    }

}

void
secondSort(t *array, int sizeOfArray, int (*function)(t *array, int indFirst, int indSecond), int (*function2)(t *array, int indFirst, int indSecond))
{

    if (*function == comprNum)
        for (int i = 0; i < sizeOfArray; i++) {
            for (int j = 0; j < sizeOfArray; j++) {
                if (((array)[i].num == (array)[j].num) &&!(*function2)(array, i, j))
                    swap(array, i,j);
            }
        }
    else if (*function == comprStr)
        for (int i = 0; i < sizeOfArray; i++) {
            for (int j = 0; j < sizeOfArray; j++) {
                if (((array)[i].name == (array)[j].name) &&!(*function2)(array, i, j))
                    swap(array, i,j);
            }
        }
    else if (*function == comprEnum)
        for (int i = 0; i < sizeOfArray; i++) {
            for (int j = 0; j < sizeOfArray; j++) {
                if (((array)[i].pos == (array)[j].pos) &&!(*function2)(array, i, j))
                    swap(array, i,j);
            }
        }
}

int comprNum(t *array, int indFirst, int indSecond)
{
    int num = (array[indFirst].num) > (array[indSecond].num) ? 1 : 0;
    return num;
}

int comprStr(t *array, int indFirst, int indSecond)
{
    int num = strcmp(array[indFirst].name, array[indSecond].name);
    if(num>0)
        num=1;
    else
        num=0;
    return num;
}

int comprEnum(t *array, int indFirst, int indSecond)
{
    int num = (array[indFirst].pos) > (array[indSecond].pos) ? 1 : 0;
    return num;
}

void inverse(t *array, int sizeOfArray)
{

    for (int i = 0; sizeOfArray/2-i>0; i++)
        swap(array,i,sizeOfArray-i-1);
}

void swap(t *array, int a,int b)
{
    t tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}
