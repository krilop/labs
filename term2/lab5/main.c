#include "functions.h"

int main() {
    FILE* DB = fopen("../term2/lab5/DataBase.txt","r");
    if(DB==NULL)
    {
        printf("Error of opening DB\n");
        return 1;
    }


    char* fileName="../term2/lab5/DataBase.txt";
    menu(DB, fileName);
    fclose(DB);
    return 0;
}