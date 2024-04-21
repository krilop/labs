#include "header.h"


int main()
{
    int end = 0;
    while (end == 0) {
        srand(time(NULL));
        int length;
        int **arr;
        inputLengthOfArray(&length);
        arr = memory(100);
        inputSquareMatr(arr, length);
        printMatr(arr, length);
        partOneOfTask(arr, length);
        partTwoOfTask(arr, length);
        tryToEnd(&end);
    }
    return 0;

}