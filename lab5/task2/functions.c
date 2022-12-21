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
	for (int i = 0; i < length||length==100; i++)
	{
		while (scanf_s("%d", *(arr + j) + i) != 1 || *(*(arr + j) + i) < 1 || *(*(arr + j) + i) >100000 || getchar() != '\n')
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
	if (length == 100)
		printf("You are funny. Only 100 nums.");
	length++;
	*(arr + j) = (int*)realloc(*(arr + j), length * sizeof(int));
	*(*(arr + j) + length - 1) = 0;
	system("cls");
}
void deleteString(int** arr, int* string, int minOfSum)
{
	for (int i = 0; i < *string; i++)
	{
		int sum = 0;
		for (int j = 0; *(*(arr + i) + j) != 0; j++)
			sum += *(*(arr + i) + j);
		if (sum == minOfSum)
		{
			*string -= 1;
			for (int j = i; j < *string; j++)
				*(arr + j) = *(arr + j + 1);
			i--;
		}	
	}
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
void minimum(int** arr, int string, int* minOfSum)
{
	int min=0;
	for (int i = 0; *(*arr + i) != 0; i++)
	{
		min += *(*arr + i);
	}

	for (int i = 0; i < string; i++)
	{
		int sum = 0;
		for (int j = 0; *(*(arr + i) + j) != 0; j++)
			sum += *(*(arr + i) + j);
		if (sum < min)
			min = sum;
	}
	*minOfSum = min;
}

void reset(int* reset)
{
	
	while (scanf_s("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
}