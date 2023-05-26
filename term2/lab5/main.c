//
// Created by krilop on 5/6/23.
//
#include "functions.h"

int main() {
    FILE* DB = fopen("../term2/lab5/DataBase.txt","r");
    if(DB==NULL)
    {
        printf("Error of opening DB\n");
        return 1;
    }
    menu(DB);
    return 0;
}