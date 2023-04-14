//
// Created by krilop on 12.02.23.
//

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

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
};

typedef struct {
    unsigned short int bfType;
    unsigned int bfSize;
    unsigned int bfReserved;
    unsigned int bfOffBits;
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short int biPlanes;
    unsigned short int biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} infoHeaderBitMap;
typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixelBitMap;
typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char reserved;
} paletteBitMap;

int checkBitCount(infoHeaderBitMap header, int *lessThanEight);

void menu(infoHeaderBitMap header);


#endif //_FUNCTIONS_H_
