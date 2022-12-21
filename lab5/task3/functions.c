#include "header.h"
void inputLengthOfArray(int* length)
{

	while (scanf_s("%d", length) != 1 || *length < 1 || *length > 100 || getchar() != '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
}
void inputString(int** arr, int j)
{
	int length = 1;
	int restart;
	printf("Okey. Input next string\n");
	for (int i = 0; i < length; i++)
	{
		while (scanf_s("%d", *(arr + j) + i) != 1 || *(*(arr + j) + i) ==0 || getchar() != '\n')
		{
			printf("Error! Try again\n");
			rewind(stdin);
		}
		printf("Do you want to input another one num?(yes-1, no-0)\t");
		reset(&restart);
		if (restart)
			length += 1;
		*(arr + j) = (int*)realloc(*(arr + j), length * sizeof(int));
	}
	length++;
	*(arr + j) = (int*)realloc(*(arr + j), length * sizeof(int));
	*(*(arr + j) + length - 1) = 0;
	system("cls");
}

void printArr(int** arr, int string)
{
	for (int i = 0; i < string; i++)
	{
		for (int j = 0; *(*(arr + i) + j) != 0; j++)
		{
			printf("%d\t", *(*(arr + i) + j));
		}
		printf("\n");
	}
}
void countOfPositiveNum(int**arr, int* count,int string)
{
	int maxCount = 0;
	*count = 0;
	for (int i = 0; i < string; i++)
	{
		for (int j = 0; *(*(arr + i) + j) != 0; j++)
		{
			if (*(*(arr + i) + j) > 0)
				*count+=1;
			
			if (*(*(arr + i) + j) < 0||(*(*(arr + string - 1) + j + 1) == 0 && i==string-1)) {
				if (maxCount < *count)
					maxCount = *count;
				*count = 0;
			}
		}
	}
	*count = maxCount;
}

void reset(int* reset)
{

	while (scanf_s("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
}