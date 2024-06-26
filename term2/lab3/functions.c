#include "functions.h"

#define END_OF_PROGRAMM 5
#define BYTE_PIXEL 3

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


pixelBitMap getPixel(pixelBitMap *arrayOfPix, int height, int width, int y, int x)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        return arrayOfPix[y * width + x];
    }
    else
    {
        pixelBitMap nullPix = {0, 0, 0};
        return nullPix;
    }
}

void gammaCorrection(FILE **in, headerFileBitMap header, infoHeaderBitMap info, char *resultName)
{

    FILE *result = fopen(resultName, "wb");
    fwrite(&header, sizeof(headerFileBitMap), 1, result);
    fwrite(&info, sizeof(infoHeaderBitMap), 1, result);

    float gamma = 0;
    printf("Enter gamma koeff for gamma correction: \n");
    while (scanf("%fl", &gamma) != 1.0 || gamma < 0.1 || gamma > 5.0 || gamma == 1.0 || getchar() != '\n')
    {
        printf("Error! try again\n");
        rewind(stdin);
    }
    int padding = (4 - (info.biWidth * BYTE_PIXEL) % 4) % 4;
    unsigned char *string = (unsigned char *) calloc((info.biWidth * BYTE_PIXEL + padding), sizeof(unsigned char));
    for (int i = 0; i < info.biHeight; i++)
    {
        fread(string, sizeof(unsigned char), BYTE_PIXEL * info.biWidth, *in);
        for (int j = 0; j < info.biWidth * BYTE_PIXEL; j++)
        {
            int byte1 = string[j];
            double tmp1 = pow(byte1 / 255.0, gamma) * 255.0;
            string[j] = (unsigned char) tmp1;
        }
        fwrite(string, sizeof(unsigned char), info.biWidth * BYTE_PIXEL, result);
        fwrite(&string[info.biWidth * BYTE_PIXEL], padding * sizeof(unsigned char), 1, result);
    }
    fclose(result);
    free(string);
}

void medianFilter(FILE **in, headerFileBitMap header, infoHeaderBitMap info, char *resultName)
{

    FILE *result = fopen(resultName, "wb");
    fwrite(&header, sizeof(headerFileBitMap), 1, result);
    fwrite(&info, sizeof(infoHeaderBitMap), 1, result);
    pixelBitMap *arrayOfPixels = (pixelBitMap *) malloc(info.biWidth * info.biHeight * sizeof(pixelBitMap));
    fread(arrayOfPixels, sizeof(pixelBitMap), info.biWidth * info.biHeight, *in);


    pixelBitMap *newArrayOfPixels = (pixelBitMap *) malloc(info.biWidth * info.biHeight * sizeof(pixelBitMap));

    int kernelSize = 0;
    printf("Enter size of kernel for median filter: \n");
    while (scanf("%d", &kernelSize) != 1 || kernelSize < 2 || kernelSize > 20 || getchar() != '\n')
    {
        printf("Error! try again");
        rewind(stdin);
    }
    int offset = kernelSize / 2;
    pixelBitMap *kernel = malloc(kernelSize * kernelSize * sizeof(pixelBitMap));
    for (int i = 0; i < info.biHeight; i++)
    {
        for (int j = 0; j < info.biWidth; j++)
        {
            int indOfPixel = 0;
            for (int k = -offset; k <= offset; k++)
            {
                for (int l = -offset; l <= offset; l++)
                {
                    pixelBitMap tmp = getPixel(arrayOfPixels, info.biHeight, info.biWidth, i + k, j + l);
                    kernel[indOfPixel] = tmp;
                    indOfPixel++;
                }
            }
            for (int k = 0; k < kernelSize * kernelSize; k++)
            {
                for (int l = k + 1; l < kernelSize * kernelSize; l++)
                {
                    if (kernel[k].red + kernel[k].blue + kernel[k].green > kernel[l].red + kernel[l].blue + kernel[l].green)
                    {
                        pixelBitMap tmp = kernel[k];
                        kernel[k] = kernel[l];
                        kernel[l] = tmp;
                    }
                }
            }
            newArrayOfPixels[i * info.biWidth + j] = kernel[(int) (kernelSize * kernelSize / 2)];
        }
    }
    fwrite(newArrayOfPixels, sizeof(pixelBitMap), info.biHeight * info.biWidth, result);
    fclose(result);
    free(arrayOfPixels);
    free(newArrayOfPixels);
}

void wnb(FILE **in, headerFileBitMap header, infoHeaderBitMap info, char *resultName)
{
    FILE *result = fopen(resultName, "wb");
    fwrite(&header, sizeof(headerFileBitMap), 1, result);
    fwrite(&info, sizeof(infoHeaderBitMap), 1, result);
    pixelBitMap pixel;
    for (int y = 0; y < info.biHeight; y++)
    {
        for (int x = 0; x < info.biWidth; x++)
        {
            fread(&pixel, sizeof(pixelBitMap), 1, *in);
            unsigned char average = (unsigned char) ((pixel.green + pixel.blue + pixel.red) / 3);
            pixel.red = average;
            pixel.green = average;
            pixel.blue = average;
            fwrite(&pixel, sizeof(pixelBitMap), 1, result);
        }
    }
    fclose(result);

}

void negative(FILE **in, headerFileBitMap header, infoHeaderBitMap info, char *resultName)
{
    FILE *result = fopen(resultName, "wb");
    fwrite(&header, sizeof(headerFileBitMap), 1, result);
    fwrite(&info, sizeof(infoHeaderBitMap), 1, result);
    pixelBitMap pixel;
    for (int y = 0; y < info.biHeight; y++)
    {
        for (int x = 0; x < info.biWidth; x++)
        {
            fread(&pixel, sizeof(pixelBitMap), 1, *in);
            pixel.red = 255 - pixel.red;
            pixel.green = 255 - pixel.green;
            pixel.blue = 255 - pixel.blue;
            fwrite(&pixel, sizeof(pixelBitMap), 1, result);
        }
    }

    fclose(result);
}

char *formName(char *nameOfFile, char *add)
{

    char *result = (char *) calloc(strlen(nameOfFile) + strlen(add) + 1, sizeof(char));
    nameOfFile = strrchr(nameOfFile, '/') + 1;
    result = strcpy(result, "../term2/lab3/");
    result = strcat(result, add);
    result = strcat(result, nameOfFile);
    result[strlen(result)] = '\0';
    return result;
}

void menu(char *nameOfFile, headerFileBitMap header, infoHeaderBitMap info, FILE **in)
{
    char *result = (char *) calloc(strlen(nameOfFile) + 1, sizeof(char));
    result = strcpy(result, nameOfFile);
    result[strlen(nameOfFile)] = '\0';
    int choice = 1;
    while (choice != END_OF_PROGRAMM)
    {
        fseek(*in,sizeof(headerFileBitMap)+sizeof(infoHeaderBitMap),SEEK_SET);
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
                negative(in, header, info, formName(result, "negative_"));
                break;
            }
            case 2:
            {
                wnb(in, header, info, formName(result, "WnB_"));
                //черно-белый
                break;
            }
            case 3:
            {
                medianFilter(in, header, info, formName(result, "median_filter_"));
                break;
            }
            case 4:
            {
                gammaCorrection(in, header, info, formName(result, "gamma_correction_"));
                break;
            }
            case 5:
            {
                break;
            }
        }
    }
    free(result);
}