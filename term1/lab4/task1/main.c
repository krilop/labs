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
		int** arr;
		inputLengthOfArray(&length);
		arr = memory(100);
		inputSquareMatr(arr, length);
		printMatr(arr, length);
		//решение задачи
		partOneOfTask(arr, length);
		//вторая часть задачи
		partTwoOfTask(arr, length);
		tryToEnd(&end);
	}
	return 0;
	
}