//
// Created by krilop on 12.02.23.
//

#include "functions.h"

#define END_OF_PROGRAMM 5

int checkBitCount(infoHeaderBitMap info, int *lessThanEight)
{
    if (info.biBitCount == 24 || info.biBitCount == 16)
    {
        return 0;
    }
    else if (info.biBitCount == 4 || info.biBitCount == 2 || info.biBitCount == 1)
    {
        *lessThanEight = 1;
        return 0;
    }
    else
    {return 1;}
}
void negative(FILE** in, headerFileBitMap header, infoHeaderBitMap info, char* resultName)
{
    FILE* result=fopen(resultName,"wb");
    fwrite(&header,sizeof(headerFileBitMap),1,result);
    fwrite(&info,sizeof(infoHeaderBitMap),1,result);
    pixelBitMap pixel;
    for (int y = 0; y <info.biHeight ; y++)
    {
        for (int x = 0; x <info.biWidth ; x++)
        {
            fread(&pixel, sizeof(pixelBitMap),1, *in);
            pixel.red=255-pixel.red;
            pixel.green=255-pixel.green;
            pixel.blue=255-pixel.blue;
            fwrite(&pixel, sizeof(pixelBitMap),1,result);
        }
    }

}
char* formName(char* nameOfFile, char* add)
{

    char* result=(char*)calloc(strlen(nameOfFile)+strlen(add)+1,sizeof(char));
    nameOfFile=strrchr(nameOfFile,'/')+1;
    result=strcpy(result,"../term2/lab3/");
    result=strcat(result,add);
    result=strcat(result,nameOfFile);
    result[strlen(result)]='\0';
    return result;
}
void menu(char* nameOfFile, headerFileBitMap header, infoHeaderBitMap info, FILE** in)
{
    char* result=(char*)calloc(strlen(nameOfFile)+1,sizeof(char));
    result=strcpy(result, nameOfFile);
    result[strlen(nameOfFile)]='\0';
    int choice = 1;
    while (choice != END_OF_PROGRAMM)
    {
        printf("Choose the operation:\n1.%s2.%s3.%s4.%s5.%s", operations[NEGATIVE], operations[WNB], operations[MEDIAN], operations[GAMMA], operations[EXIT]);
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5 || getchar() != '\n')
        {
            printf("Error. Don't worry. Try again\n");
            rewind(stdin);
        }
        switch (choice)
        {
            case 1:
            {//негатив
                negative(in, header, info, formName(result,"negative_"));

                break;
            }
            case 2:
            {
             //черно-белый
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
        }
    }

}