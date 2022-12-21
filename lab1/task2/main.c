#include <stdio.h>
int main()
{
	int a, b, c;
	printf("Enter three numbers on the line:");
	if (scanf_s("%d %d %d", &a, &b, &c) == 3) 
	{
		//printf("%d\t %d\t %d\t", a, b, c);
		if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
		{
			printf("There are even numbers among the entered numbers.");
		}
		else printf("There are no even numbers among the entered numbers.");
	}
	else printf("Uncorrect input");
	return 0;
}