/*
���� ������������� ���������� �������. ����������: ����� ��������� � ��� ��������, ������� �� �������� ������������� ���������; ������� ����� ���� ������� ��������� ����������,
������������ �������� ��������� �������
���������: ����� ������� �� ������� ����� header.h
*/
#include "header.h"


int main()
{
	int end = 0;
	while (end==0)
	{
		srand(time(NULL));
		int length;
		int* plength = &length;
		int** arr;
		inputLengthOfArray(plength);
		arr = memory(100);
		inputSquareMatr(arr, plength);
		printMatr(arr, plength);
		//������� ������

		partOneOfTask(arr, plength);
		//������ ����� ������
		partTwoOfTask(arr, plength);
		tryToEnd(&end);
	}
	return 0;
	
}