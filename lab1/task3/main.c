//Составьте алгоритм решения неравенства ax^2+bx+c<0.
#include <stdio.h>
#include <math.h>
float min(float a, float b);
float max(float a, float b);
//float root(float a);
float tmp(float a);
int main()
{
	float a, b, c, D, x1, x2;
	printf("enter the coefficients a, b, c for an inequality of the form ax^2+bx+c<0.\n");
	if (scanf_s("%f %f %f",&a,&b,&c) != 3)
	{
		printf("Uncorrect input");
		return 0;
	}
	if (a == 0 && b == 0 && c == 0)
	{
		//0<0
		printf("Inequality has no solution");
	}
	if (a == 0 && b != 0 && c == 0)
	{	
		//bx<0
		if (b > 0) 
		{
			printf("The solution is a range from 0 to infinity.");
		}
		else 
		{
			printf("The solution is a range from negative infinity to 0.");
		}
	}
	if (a == 0 && b == 0 && c != 0)
	{
		//c<0
		if (c < 0)
		{
			printf("The solution is any number.");
		}
		else
		{
			printf("Inequality has no solution");
		}
	}
	if (a == 0 && b != 0 && c != 0)
	{
		//bx+c<0
		if (b > 0)
		{
			x1 = -c/b;
			printf("The solution is a range from infinity to %f (not including).", x1);
		}
		else if (b < 0)
		{
			x1 = -c/b;
			printf("The solution is a range from %f (not including) to infinity.", x1);
		}
	}
	if (a != 0 && b == 0 && c == 0)
	{
		//ax^2<0
		if (a < 0)
		{
			printf("The solution is a range from negaive infinity to 0 and from 0 to infinity.");
		}
		else
		{
			printf("Inequality has no solution");
		}
	}
	if (a != 0 && b != 0 && c == 0)
	{
		//ax^2+bx<0
		x1 = 0;
		x2 = -b / a;
		if (a < 0)
		{
			printf("The solution is a range from negaive infinity to %f and from %f to infinity.", min(x1,x2), max(x1,x2));
		}
		else
		{
			printf("The solution is a range from %f to %f.", min(x1, x2), max(x1, x2));
		}
	}
	if (a != 0 && b == 0 && c != 0)
	{
		//ax^2+c<0
		if (a > 0 && c > 0)
		{
			printf("Inequality has no solution");
		}
		else if (a > 0 && c < 0)
		{
			
			tmp(x1 = sqrt(-c / a));
			x2 = -x1;
			printf("The solution is a range from %f to %f.(Values may be rounded)", min(x1, x2), max(x1, x2));
		}
		else if (a < 0 && c>0)
		{
			tmp(x1 = sqrt(-c / a));
			x2 = -x1;
			printf("The solution is a range from negaive infinity to %f and from %f to infinity.(Values may be rounded)", min(x1, x2), max(x1, x2));
		}
		else if (a < 0 && c < 0)
		{
			printf("The solution is any number.");
		}
	}
	if (a != 0 && b != 0 && c != 0)
	{
		//ax^2+bx+c<0
		D = b * b - 4 * a * c;
		if (D < 0) 
		{
			printf("Inequality has no solution");
		}
		else
		{
			x1 = tmp((-b + sqrt(D)) / (2 * a));
			x2 = tmp((-b - sqrt(D)) / (2 * a));
			if (a > 0)
			{
				printf("The solution is a range from %f to %f.(Values may be rounded)", min(x1, x2), max(x1, x2));
			}
			else
			{
				printf("The solution is a range from negaive infinity to %f and from %f to infinity.(Values may be rounded)", min(x1, x2), max(x1, x2));
			}
		}
		
	}
	return 0;
}
float min(float a, float b)// меньшее значение из пары
{
	if (a < b) 
	{
		return a;
	}
	else
	{
		return b;
	}
}
float max(float a, float b)// большее значение из пары
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
float tmp(float a) // округление до 2-х знаков после запятой
{
	a *= 100;
	int tmp = a;
	a = tmp;
	a /= 100;
	return a;
}

