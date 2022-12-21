//15.	ƒано натуральное  число  n.¬ы€снить, можно ли представить n != 1 * 2 * 3*...*n в виде произведени€ трЄх последовательных целых чисел.
#include <stdio.h>

int main()
{
	int n, factorial=1;
	int IsItPossible=0;

	printf("Input num\t");
	if(scanf_s("%d",&n) == 1&& n>0)
	{
		//считает факториал
		for (int i = 1; i-1 < n; i++)
		{
			factorial = factorial * i;
		}
		int i;
		for ( i = n; i>0; i--)
		{
			if (i*(i-1)*(i-2) == n)
			{
				IsItPossible++;
				break;
			}
		}
		if (IsItPossible > 0)
		{
			printf("N=(%d-2)(%d-1)%d", i, i, i);
		}
		else
		{
			printf("It isn't possible.");
		}
		 
	}
	else
	{
		printf("Uncorrect input");
	}
	
	return 0;
}