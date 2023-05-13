//
// Created by krilop on 5/6/23.
//

#include "functions.h"
#define POWER 31
#define M_BIG_NUM 1000000
#define STRING 255
#define HASH_TABLE_SIZE 5
int hash(char* string)
{
    int power=0;
    int hashNum=0;
    for (int i = 0; i <(int)strlen(string) ; i++)
    {
        hashNum=(hashNum+(string[i]-'a'+1)*power)%M_BIG_NUM;
        power=(power*POWER)%M_BIG_NUM;
    }
    return hashNum;
}
void getNewObj(char* string, list** listOfData)
{
    if(doesListFull)
    {
        changeLastObj(listOfData,string);
    }
    else
    {
        list* tmp =(*listOfData);
        while((*tmp).key!=NULL)
            tmp=(*tmp).next;
        (*tmp).key=calloc(1,sizeof(char));
        for (int i = 0; string[i]!=' ' ; i++)
        {
            (*tmp).key[i] = string[i];
            (*tmp).key=realloc((*tmp).key,i+2);
        }
        string=strrchr(string, ' ');
        for (int i = 0; string[i-1]!='\0' ; i++)
        {
            (*tmp).value[i] = string[i];
            (*tmp).value=realloc((*tmp).value,i+2);
        }
        (*tmp).value=realloc((*tmp).value,(1+strlen((*tmp).value)*sizeof(char)));
    }

}
void getTable(list*** arrayOfPtr, list** listOfData, FILE* DB)
{
    char* buffer= (char*)calloc(STRING+1, sizeof(char));
    int countOfSize=0;
    while(!feof(DB)&&(countOfSize!=HASH_TABLE_SIZE))
    {
        fgets(buffer, STRING, DB);
        buffer[strlen(buffer)] = '\0';

        if (strstr(buffer, "IN A") != NULL)
        {
            countOfSize++;
            getNewObj(buffer, listOfData);

        }
    }




}

list* createElOfList(char* value, char* key)
{

}


list* createList()
{

}
