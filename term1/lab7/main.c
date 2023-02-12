/*1.	���� ������. ����� ����� ����� � ������ 
2.	���� ������ S, S0 � ����� k, m. �������� c k-�� ������� ������ S ������ m �������� �� ������ S0
*/
#include "header.h"

int main()
{
    void (*fptr)() = NULL;
    int restart = 1, task;
    while (restart) {
        chooseTask(&task);
        if (task == 1)
            fptr = main1;
        else
            fptr = main2;
        fptr();
        reset(&restart);
    }
    return 0;
}

