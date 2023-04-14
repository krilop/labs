//
// Created by krilop on 12.02.23.
//

#include "functions.h"

int checkBitCount(infoHeaderBitMap header, int* lessThanEight)
{
    if(header.biBitCount==24||header.biBitCount==16)
        return 0;
    else if(header.biBitCount==4||header.biBitCount==2||header.biBitCount==1)
    {
        *lessThanEight=1;
        return 0;
    }
    else return 1;

}