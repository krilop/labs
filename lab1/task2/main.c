#include <stdio.h>
int main()
{
	int num1;
    int num2;
    int num3;
	printf("Enter three numbers on the line:");
	while(scanf_s("%d %d %d", &num1, &num2, &num3) == 3||getchar()!='\n')
	{
		//printf("%d\t %d\t %d\t", a, b, num3);
        printf("Uncorrect input");
        rewind(stdin);
	}
    if (num1 % 2 == 0 || num2 % 2 == 0 || num3 % 2 == 0)
        printf("There are even numbers among the entered numbers.");
    else printf("There are no even numbers among the entered numbers.");
	return 0;
}