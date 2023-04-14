//
// Created by krilop on 12.02.23.
//

#include "functions.h"
#define END_OF_PROGRAMM 5
int checkBitCount(infoHeaderBitMap header, int *lessThanEight)
{
    if (header.biBitCount == 24 || header.biBitCount == 16)
    {
        return 0;
    }
    else if (header.biBitCount == 4 || header.biBitCount == 2 || header.biBitCount == 1)
    {
        *lessThanEight = 1;
        return 0;
    }
    else
    {return 1;}
}


















































void menu(infoHeaderBitMap header)
{
    int choice=1;
    while(choice!=END_OF_PROGRAMM)
    {
        printf("Choose the operation:\n1.%s2.%s3.%s4.%s5.%s",operations[NEGATIVE],operations[WNB],operations[MEDIAN],operations[GAMMA],operations[EXIT]);
        while(scanf("%d",&choice)!=1||choice<1||choice>5||getchar()!='\n')
        {
            printf("Error. Don't worry. Try again\n");
            rewind(stdin);
        }
    }
}