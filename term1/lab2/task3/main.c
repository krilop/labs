//15.	Дано число Х в градусах. Найти значение sin X используя разложение в ряд Тейлора
#include <stdio.h>
#include <math.h>

double degtorad(double);

double deg(double num, double deg);

double factorial(double a);

int main()
{
    double X;
    int sign = 1;
    printf("Enter angle in degrees\n");
    while (scanf_s("%lf", &X) != 1 || getchar() != '\n')
    {
        printf("Uncorrect input");
        rewind(stdin);
    }
    X = degtorad(X);
    double sinx = 0;
    for (int i = 0; i < 10; i++)
    {
        sinx = sinx + sign * deg(X, 2 * i + 1) / factorial(2 * i + 1);
        sign = -sign;
    }
    printf("sin=%lf(approximately)", sinx);
    return 0;
}
double factorial(double a)
{
    double factorial = 1;
    for (int i = 1; i - 1 < a; i++)
        factorial = factorial * i;
    return factorial;
}
double deg(double num, double deg)
{
    double arg = num;
    for (int i = 1; i < deg; i++)
        num = num * arg;
    return num;
}

double degtorad(double deg)
{
    while (deg > 360)
        deg = deg - 360;
    while (deg < 0)
        deg = deg + 360;
    double rad;
    const double pi = 3.14;
    rad = deg * pi / 180;
    return rad;
}
