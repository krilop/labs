/*1.	Дана строка. Найти сумму чисел в строке 
2.	Даны строки S, S0 и числа k, m. Вставить c k-ой позиции строки S первые m символов из строки S0
*/
#include "header.h"
#include <stdlib.h>

int main() {

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

