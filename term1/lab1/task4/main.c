//��� ������������ ����� � ���������� ����� "�� ����� � ������ � ����", ���������� ��������� ����� "����" � ������ �.
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int k;
    printf("������� ����� ��������� ������");
    while (scanf_s("%d", &k) != 1 || k < 0 || getchar() != '\n') {
        rewind(stdin);
        printf("Uncorrect input");
    }
    if (k % 10 == 1 && k % 100 != 11)
        printf("�� ����� %d ���� � ����", k);
    else if (k % 10 == 2 && k % 100 != 12 || k % 10 == 3 && k % 100 != 13 || k % 10 == 4 && k % 100 != 14)
        printf("�� ����� %d ����� � ����", k);
    else
        printf("�� ����� %d ������ � ����", k);
    return 0;
}