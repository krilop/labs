#include "header.h"
void inputLength(int* length)
{

	while (scanf_s("%d", length) != 1 || *length < 1 || *length > 100000 || getchar() != '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
}
void inputArr(int* parr, int length)
{
	srand(time(NULL));
	printf("Choose the way of input(1-keyboard,2-random)\n");
	int way;
	while (scanf_s("%d", &way) != 1 || way !=1 && way!=2 || getchar() != '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
	if (way==1)
		for (int i = 0; i < length; i++)
		{
			printf("Input %d-th element:\n", i + 1);
			while (scanf_s("%d", parr + i) != 1 || getchar() != '\n')
			{
				printf("Error! Try again\n");
				rewind(stdin);
			}
		}
	else
	{
		for (int i = 0; i < length; i++)

			*(parr+i)=rand()%20000-10000;
	}
}
void randWorse(int* parr, int length)
{
	parr[length] = 0;
	for (int i = length-1; i >=0; i--)
	{
		parr[i] = parr[i + 1] + 1;
	}
}
void printArr(int* parr, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%d\t", *(parr + i));
		
	}
	printf("\n");
}
	
void findInd(int* parr, int length, int* ind)
{
	for (int i = 0; i < length; i++)
	{
		if (*(parr + i) > -1)
		{
			*ind = i;
			break;
		}
	}
}
void power(int* multiple,int a, int b)
{
	int tmp = a;
	if (a == 0)
	{
		*multiple = 1;
		return;
	}
	for (int i = 0; i < b-1; i++)
		a *= tmp;
	*multiple = a;
}
//void stepOfShell(int* step, int length, int* count)
//{
//	int multiple1, multiple2;
//	if (*count % 2 == 0)
//	{
//		power(&multiple1, 2, *count);
//		power(&multiple2, 2, * count / 2);
//		*step = 9 * multiple1 - 9 * multiple2+1;
//	}
//	else
//	{	
//		power(&multiple1, 2, *count);
//		power(&multiple2, 2, (*count + 1) / 2);
//		*step = 8 * multiple1 - 6 * multiple2 + 1;
//	}
//	
//	*count-=1;
//	if (*count < 0)
//		*step = -1;
//	if (*step > length / 2)
//		stepOfShell(step, length, count);
//}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void copyArr(int* adress, int* letter,int length)
{
	for (int i = 0; i < length; i++)
	{
		*(adress + i) = *(letter + i);
	}
}
void sortShell(int* parr, int length, int indFirstPositive)
{
	
	int count = length / 3;
	int i, j, step;
	int tmp;
		for (step = (length-indFirstPositive) / 2; step > 0; step /= 2)
		for (i =indFirstPositive+1+ step; i < length; i++)
		{
			tmp = parr[i];
			for (j = i; j >= step+1+indFirstPositive; j -= step)
			{
				if (tmp < parr[j - step])
					parr[j] = parr[j - step];
				else
					break;
			}
			parr[j] = tmp; 
		}

	
	
}
void sortBubble(int* parr, int length, int indFirstPositive)
{
	int tmp, noSwap;
	for (int i = length - 1; i > indFirstPositive; i--)
	{
		noSwap = 1;
		for (int j = indFirstPositive+1; j < i; j++)
		{
			if (parr[j] > parr[j + 1])
			{
				tmp = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = tmp;
				noSwap = 0;
			}
		}
		if (noSwap == 1)
			break;
	}
}

void reset(int* reset)
{

	while (scanf_s("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n')
	{
		printf("Error! Try again\n");
		rewind(stdin);
	}
}