/*2.	В матрице размером NxM выполнить сортировку строк по возрастанию произведения отрицательных элементов  методом слияния*/

#include "header.h"
int main()
{
	int restart = 1;
	int** parr;
	parr = (int**)malloc(sizeof(int*));
	while (restart)
	{
		printf("How many strings do u want to have?\n");
		int str,col;
		inputLength(&str);
		printf("How many columns do u want to have?\n");
		inputLength(&col);
		parr = (int**)realloc(parr, str * sizeof(int*));
		for (int i = 0; i < str; i++)
		{
			*(parr + i) = (int*)malloc( col * sizeof(int));
		}
		inputArr(parr, str,col);
		printArr(parr, str, col);
		printf("sorted arr:\n");
		printProductOfStr( parr,  str,  col);
		mergeSort(parr, 0, str-1, col);
		printArr(parr, str, col);
		printProductOfStr(parr, str, col);
		printf("Do u want to run app again?(yes-1, no-0)");
		reset(&restart);
	}
	
	
	

	free(parr);
	
	return 0;
}