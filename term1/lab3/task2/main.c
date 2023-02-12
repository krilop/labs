/*
15.	В массиве из n элементов циклически сдвинуть все четные элементы на k влево. Нечетные оставить на своих местах
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int MinusOrPlus();
int main()
{
	srand(time(NULL));
	int arr_choice;
	int rd;
	printf("enter the way to set the array (1-input from the keyboard / 2-random) ");
	while (scanf_s("%d", &arr_choice) != 1 || arr_choice != 1 && arr_choice != 2||getchar()!='\n')//Проверка на ввод
	{
		printf("try again\n");
		rewind(stdin);
	}
	int array[100];
	int n;
	int sign;
	printf("Enter the dimension of the array (from 2 to 100) ");
	while (scanf_s("%d", &n) != 1 || n > 100||n<2||getchar()!='\n')//Проверка на ввод
	{
		printf("try again\n");
		rewind(stdin);
	}
	for (int i = 0; i < n; i++)
		if (arr_choice == 2)
		{
			sign = MinusOrPlus();
			rd = sign * rand() % 1000000;
			array[i] = rd;
		}
		else
			while (scanf_s("%d", &array[i]) != 1)//Проверка на ввод
			{
				printf("try again\n");
				rewind(stdin);
			}
	for (int i = 0; i < n; i++)
		printf("%d\t", array[i]);
	//Сдвиг четных элементов
	/*
	1) найдем первый четный элемент done
	2) надем следующий четный элемент и запишем его в первое четное значение после найденного. Так до конца массива done
	3) последний элемент приравняем к записанному в первом пункте done
	4) добавим цикл на кол-во повторений done
	*/
	printf("enter shift ");
	int k;
	while (scanf_s("%d", &k) != 1||k<0)//Проверка на ввод
	{
		printf("try again\n");
		rewind(stdin);
	}
	for (; k > 0; k--)
	{
		int first_element = array[0];
		int ind_el = 0;
		for (int i = 0; i < n; i++)
			if (array[i] % 2 == 0)
			{
				first_element = array[i];
				ind_el = i;
				break;
			}
		for (int i = 0; i < n; i++)
		{
			if (i == ind_el)
				continue;
			if (array[i] % 2 == 0)
			{
				array[ind_el] = array[i];
				ind_el = i;
			}
		}
		array[ind_el] = first_element;
	}
	printf("result:\n");
	for (int i = 0; i < n; i++)
		printf("%d\t", array[i]);
}
int MinusOrPlus()
{
	int sign = rand() % 2;
	if (sign == 0)
		return 1;
	return -1;
}