/*3.	ƒан двумерный массив ненулевых целых чисел. ќпределить максимально длинную последовательность положительных чисел. ћассив просматриваетс€ построчно сверху вниз, а в каждой строке - слева направо.
—охранение знака при переходе на новую строку также учитывать.*/
#include "header.h"
int main()
{
	int restart = 1;
	while (restart)
	{
		int** pparr;
		printf("How many strings do you want to have?\t");
		int string;
		int* pstring = &string;
		inputLengthOfArray(pstring);
		pparr = (int**)malloc(string * sizeof(int*));
		for (int i = 0; i < string; i++)
			*(pparr + i) = (int*)malloc(sizeof(int));
		for (int i = 0; i < string; i++)
			inputString(pparr, i);
		int minOfSum;
		printArr(pparr, string);
		countOfPositiveNum(pparr, &minOfSum, string);
		printf("The longest sequence of positive numbers in your case is %d\n",minOfSum);
		for (int i = 0; i < string; i++)
			free(*(pparr + i));
		free(pparr);
		printf("Do you want to use programm again?(yes - 1, no - 0)\t");
		reset(&restart);
	}
}