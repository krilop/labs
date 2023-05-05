//
// Created by krilop on 4/28/23.
//
#include "functions.h"

int main()
{
    FILE* DB=fopen("../term2/lab4/DataBase.txt","r");
    if(DB==NULL)
        return 1;
    fseek(DB,0,SEEK_SET);
    node* root = loadDB(DB);
    fclose(DB);
    int restart=getAnswer("Hello, ready to start?");
    while(restart)
    {
        startGame(root);
        restart=getAnswer("Do you want to play the game again?");
    }
    DB=fopen("../term2/lab4/DataBase.txt","w");
    saveDB(root,DB);
    fclose(DB);
    return 0;
}