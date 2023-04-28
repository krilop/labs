//
// Created by krilop on 12.02.23.
//

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>


#pragma pack(push, 1)
static char* operations[]={
        "Negative\n",
        "White&Black\n",
        "Median filter\n",
        "Gamma correction\n",
        "Exit\n"
};
typedef enum oper{
    NEGATIVE,
    WNB,
    MEDIAN,
    GAMMA,
    EXIT
}operation;

typedef struct{
    unsigned short int bfType;//Отметка для отличия формата от других (сигнатура формата)
    unsigned int bfSize;//Размер файла в байтах.
    unsigned short int reserved1;//Зарезервированы и должны содержать ноль.
    unsigned short int reserved2;//
    unsigned int bfOffBits;//Положение пиксельных данных относительно начала данной структуры (в байтах).
}headerFileBitMap;
typedef struct {
    unsigned int biSize;//Размер данной структуры в байтах, указывающий также на версию структуры
    int biWidth;//Ширина растра в пикселях.
    int biHeight;//высота растра в пикселях (абсолютное значение числа) и порядок следования строк в двумерных массивах (знак числа).
    unsigned short int biPlanes;//В BMP допустимо только значение 1. Это поле используется в значках и курсорах Windows.
    unsigned short int biBitCount;//Количество бит на пиксель
    unsigned int biCompression;//Указывает на способ хранения пикселей
    unsigned int biSizeImage;//Размер пиксельных данных в байтах. Может быть обнулено если хранение осуществляется двумерным массивом.
    int biXPelsPerMeter;//Количество пикселей на метр по горизонтали и вертикали
    int biYPelsPerMeter;//
    unsigned int biClrUsed;//Размер таблицы цветов ячеек
    unsigned int biClrImportant;//Количество ячеек от начала таблицы цветов до последней используемой (включая её саму).
} infoHeaderBitMap;
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixelBitMap;
/*
typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char reserved;
} paletteBitMap;
 */
#pragma pack(pop)
int checkBitCount(infoHeaderBitMap info, int *lessThanEight);

void menu(char* nameOfFile, headerFileBitMap header, infoHeaderBitMap info, FILE** in);

pixelBitMap getPixel(pixelBitMap *arrayOfPix, int height, int width, int y, int x);
void gammaCorrection(FILE **in, headerFileBitMap header, infoHeaderBitMap info, char *resultName);
void medianFilter(FILE **in, headerFileBitMap header, infoHeaderBitMap info, char *resultName);
void wnb(FILE **in, headerFileBitMap header, infoHeaderBitMap info, char *resultName);
void negative(FILE **in, headerFileBitMap header, infoHeaderBitMap info, char *resultName);
char *formName(char *nameOfFile, char *add);
//void wnb(FILE** in, headerFileBitMap header, infoHeaderBitMap info, char* resultName);

#endif //_FUNCTIONS_H_
