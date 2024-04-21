#include "header.h"

int main()
{
    int end = 0;
    while (end == 0) {
        srand(time(NULL));
        int length;
        int **array1;
        inputLengthOfArray(&length);
        array1 = memory(100);
        inputSquareMatr(array1, &length);
        printMatr(array1, &length);
        //������� ������
        int border;
        if (length % 2 == 1)
            border = (length - 1) / 2;
        else
            border = length / 2;
        int min = array1[border][0];
        for (int i = border; i < length; i++)
            for (int j = 0; j < border + 1; j++)
                if (array1[i][j] % 2 == 0)
                    min = array1[i][j];
        int flag = 0;
        for (int i = border; i < length; i++)
            for (int j = 0; j < border + 1; j++)
                if (array1[i][j] % 2 == 0 && array1[i][j] <= min) {
                    min = array1[i][j];
                    flag++;
                }
        if (flag > 0)
            printf("min of array: %d\n", min);
        else
            printf("The matr in the third area haven't odd nums\n");
        tryToEnd(&end);
    }
    return 0;
}