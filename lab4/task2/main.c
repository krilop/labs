/*Найти в матрице первый столбец, все элементы которого равны нулю. Знаки элементов строки с таким же номером изменить на противоположные.*/
#include "header.h"
int main()
{
	int end = 0;
	while (end==0)
	{
		srand(time(NULL));
		int col, row;
		int** array1;
		array1 = memory(100);
		printf("Hello. Input a size of rows\n");
		inputLengthOfArray(&row);
		printf("Input a size of colums\n");
		inputLengthOfArray(&col);
		inputMatr(array1, &row, &col);
		printMatr(array1, &row, &col);
		//Решение задачи 
		int indOfColZero = -1;
		int flagForZero = 0;
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
				if (array1[j][i] != 0)
				{
					flagForZero = 1;
					break;
				}
			if (flagForZero == 0)
				indOfColZero = i;
			flagForZero = 0;
		}
		if (indOfColZero > -1)
			for (int i = 0; i < col; i++)
				array1[indOfColZero][i] *= -1;
		printf("result:\n");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				if (indOfColZero == i)
					printf("\x1B[31m%d\t\033[0m", array1[i][j]);
				else
					printf("%d\t", array1[i][j]);
			printf("\n");
		}
		tryToEnd(&end);
	}
	return 0;
}