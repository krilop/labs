/*
Дана целочисленная квадратная матрица. Определить: сумму элементов в тех столбцах, которые не содержат отрицательных элементов; минимум среди сумм модулей элементов диагоналей,
параллельных побочной диагонали матрицы
Замечание: нужно разбить на функции через header.h
*/
#include "header.h"


int main()
{
	int end = 0;
	while (end==0)
	{
		srand(time(NULL));
		int length;
		int* plength = &length;
		int** arr;
		inputLengthOfArray(plength);
		arr = memory(100);
		inputSquareMatr(arr, plength);
		printMatr(arr, plength);
		//решение задачи

		partOneOfTask(arr, plength);
		//вторая часть задачи
		partTwoOfTask(arr, plength);
		tryToEnd(&end);
	}
	return 0;
	
}