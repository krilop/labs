#include "functions.h"
#include "sorts.h"
int main(void)
{
    setlocale(LC_ALL, "Rus");
    char name[]={"/home/krilop/Документы/university/foaap/labs/term2/lab1/basket.txt"};
    FILE *in;
    if ((in = fopen(name, "r")) == NULL)
    {
        printf("Открыть файл не удалось\n");
        exit(1);
    }

    t* arr;
    int sizeOfArray=1;
    createArrayOfStruct(&arr, &sizeOfArray);
    parsing(&arr, in, &sizeOfArray);

    menu(&arr, &sizeOfArray);
    //free(arr);
    return 0;

}


