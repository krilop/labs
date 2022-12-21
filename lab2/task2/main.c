/*15.	Дана последовательность ai = i3, номера её первого и  последнего  членов  1 и n.Найдите сумму S и произведение P тех её членов, номера  которых являются :
а) нечетными
б) четными
*/
#include <stdio.h>
int main() 
{
	int n, sum=0, prod=1, choice;
	printf("Input num\n");
	if (scanf_s("%d", &n) != 1|| n<=0)
	{
		printf("Uncorrect input");
		return 0;
	}
	printf("Odd(2) or even(1)?\n");
	scanf_s("%d",&choice);
	switch (choice)
	{
	case 1: 
	{
		for (int i = 1; i - 1 < n; i++) 
		{
			if (i%2==1)
			{
				sum = sum + i * i * i;
				prod = prod * i * i * i;
			}	
		}
		break;
	}
	case 2:
	{
		for (int i = 1; i - 1 < n; i++)
		{
			if (i % 2 == 0)
			{
				sum = sum + i * i * i;
				prod = prod * i * i * i;
			}
		}

		break;
	}
	default:
		printf("Uncorrect input");
		return 0;
	}
	printf("Sum = %d, product=%d", sum, prod);
	return 0;
}