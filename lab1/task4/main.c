//Для натурального числа К напечатать фразу "мы нашли К грибов в лесу", согласовав окончание слова "гриб" с числом К.
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	printf("Введите число найденных грибов");
	if (scanf_s("%d", &k) != 1|| k<0)
	{
		printf("Uncorrect input");
	}
	else if (k % 10 == 1 && k % 100 != 11) 
	{
		printf("Мы нашли %d гриб в лесу", k);
	}
	else if (k % 10 == 2 && k % 100 != 12 || k % 10 == 3 && k % 100 != 13 || k % 10 == 4 && k % 100 != 14)
	{
		printf("Мы нашли %d гриба в лесу", k);
	}
	else
	{
		printf("Мы нашли %d грибов в лесу", k);
	}
	

	return 0;
}