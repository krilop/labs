//��������� �������� ������� ����������� ax^2+bx+c<0.
#include <stdio.h>
#include <math.h>

float min(float a, float b);

float max(float a, float b);

//float root(float a);
float tmp(float a);

int main()
{
    float aCoefficient;
    float bCoefficient;
    float cCoefficient;
    float discriminant;
    float solution1;
    float solution2;
    printf("enter the coefficients aCoefficient, bCoefficient, cCoefficient for an inequality of the form ax^2+bx+c<0.\n");
    while (scanf_s("%f %f %f", &aCoefficient, &bCoefficient, &cCoefficient) != 3 || getchar() != '\n') {
        printf("Uncorrect input");
        rewind(stdin);
    }
    if (aCoefficient == 0 && bCoefficient == 0 && cCoefficient == 0)
        //0<0
        printf("Inequality has no solution");
    if (aCoefficient == 0 && bCoefficient != 0 && cCoefficient == 0) {
        //bx<0
        if (bCoefficient > 0)
            printf("The solution is a range from 0 to infinity.");
        else
            printf("The solution is a range from negative infinity to 0.");
    }
    if (aCoefficient == 0 && bCoefficient == 0 && cCoefficient != 0) {
        //c<0
        if (cCoefficient < 0)
            printf("The solution is any number.");
        else
            printf("Inequality has no solution");
    }
    if (aCoefficient == 0 && bCoefficient != 0 && cCoefficient != 0) {
        //bx+c<0
        if (bCoefficient > 0) {
            solution1 = -cCoefficient / bCoefficient;
            printf("The solution is a range from infinity to %f (not including).", solution1);
        } else if (bCoefficient < 0) {
            solution1 = -cCoefficient / bCoefficient;
            printf("The solution is a range from %f (not including) to infinity.", solution1);
        }
    }
    if (aCoefficient != 0 && bCoefficient == 0 && cCoefficient == 0) {
        //ax^2<0
        if (aCoefficient < 0)
            printf("The solution is a range from negative infinity to 0 and from 0 to infinity.");
        else
            printf("Inequality has no solution");
    }
    if (aCoefficient != 0 && bCoefficient != 0 && cCoefficient == 0) {
        //ax^2+bx<0
        solution1 = 0;
        solution2 = -bCoefficient / aCoefficient;
        if (aCoefficient < 0)
            printf("The solution is a range from negative infinity to %f and from %f to infinity.", min(solution1, solution2), max(solution1, solution2));
        else
            printf("The solution is a range from %f to %f.", min(solution1, solution2), max(solution1, solution2));
    }
    if (aCoefficient != 0 && bCoefficient == 0 && cCoefficient != 0) {
        //ax^2+c<0
        if (aCoefficient > 0 && cCoefficient > 0)
            printf("Inequality has no solution");
        else if (aCoefficient > 0 && cCoefficient < 0) {

            tmp(solution1 = (float) sqrt(-cCoefficient / aCoefficient));
            solution2 = -solution1;
            printf("The solution is a range from %f to %f.(Values may be rounded)", min(solution1, solution2), max(solution1, solution2));
        } else if (aCoefficient < 0 && cCoefficient > 0) {
            tmp(solution1 = (float) sqrt(-cCoefficient / aCoefficient));
            solution2 = -solution1;
            printf("The solution is a range from negative infinity to %f and from %f to infinity.(Values may be rounded)", min(solution1, solution2), max(solution1, solution2));
        } else if (aCoefficient < 0 && cCoefficient < 0)
            printf("The solution is any number.");
    }
    if (aCoefficient != 0 && bCoefficient != 0 && cCoefficient != 0) {
        //ax^2+bx+c<0
        discriminant = bCoefficient * bCoefficient - 4 * aCoefficient * cCoefficient;
        if (discriminant < 0)
            printf("Inequality has no solution");
        else {
            solution1 = tmp((-bCoefficient + sqrt(discriminant)) / (2 * aCoefficient));
            solution2 = tmp((-bCoefficient - sqrt(discriminant)) / (2 * aCoefficient));
            if (aCoefficient > 0)
                printf("The solution is a range from %f to %f.(Values may be rounded)", min(solution1, solution2), max(solution1, solution2));
            else
                printf("The solution is a range from negative infinity to %f and from %f to infinity.(Values may be rounded)", min(solution1, solution2), max(solution1, solution2));
        }

    }
    return 0;
}

float min(float a, float b)// ������� �������� �� ����
{
    if (a < b)
        return a;
    else
        return b;
}

float max(float a, float b)// ������� �������� �� ����
{
    if (a > b)
        return a;
    else
        return b;
}

float tmp(float a) // ���������� �� 2-� ������ ����� �������
{
    a *= 100;
    int tmp = a;
    a = tmp;
    a /= 100;
    return a;
}

