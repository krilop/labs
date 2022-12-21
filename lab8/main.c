//3.	������������� ������� ������� ������ ����� �� �������� ����� ������
#include "header.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("No arguments, restart");
        return 0;
    }
    char **parr = (char **) malloc(argc * (sizeof(char *)));
    for (int i = 0; i < argc; i++)
        *(parr + i) = (char *) malloc(getLength(argv, i) * sizeof(char));
    copyArray(argv, parr, argc);
    deleteFirstString(parr, argc);
    argc--;
    parr = (char **) realloc(parr, argc * (sizeof(char *)));
    printf("array before:\n");
    printArray(parr, argc);
    mergeSort(parr, 0, argc - 1);
    printf("\narray after:\n");
    printArray(parr, argc);

}