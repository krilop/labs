//15.	���� �����������  �����  n.��������, ����� �� ����������� n != 1 * 2 * 3*...*n � ���� ������������ ��� ���������������� ����� �����.
#include <stdio.h>

int main()
{
    int n;
    int factorial = 1;
    int IsItPossible = 0;
    printf("Input num\t");
    while (scanf_s("%d", &n) != 1 && n > 0) {
        printf("Uncorrect input");
        rewind(stdin);
    }
    //������� ���������
    for (int i = 1; i - 1 < n; i++)
        factorial = factorial * i;
    int i;
    for (i = n; i > 0; i--)
        if (i * (i - 1) * (i - 2) == n) {
            IsItPossible++;
            break;
        }
    if (IsItPossible > 0)
        printf("N=(%d-2)(%d-1)%d", i, i, i);
    else
        printf("It isn't possible.");
    return 0;
}