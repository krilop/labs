//
// Created by krilop on 5/6/23.
//

#include "functions.h"
#define POWER 31
#define M_BIG_NUM 1000000
#define STRING 255
#define HASH_TABLE_SIZE 5



int cntBeforeSpace(char* string)
{
    int cnt=1;
    while(string[cnt-1]!=' ')
        cnt++;
    return cnt;

}
int hash(char* string)
{
    int hashNum=0;
    for (int i = 0; i <cntBeforeSpace(string) ; i++)
    {
        if(string[i]=='.')
            continue;
        hashNum=hashNum+string[i]-'a';
    }
    return hashNum%HASH_TABLE_SIZE;
}
int doesListFull(list** listOfData)
{
    int count =HASH_TABLE_SIZE;
    list* tmp=(*listOfData);
    while((*tmp).key!=NULL&&(*tmp).next!=NULL)
    {
        count--;
        tmp=tmp->next;
    }
    return count==0? 1:0;
}

void changeLastObj(list** listOfData, char* string, list*** arrayOfPtr)
{
    int count =HASH_TABLE_SIZE;
    list* tmp=(*listOfData);
    while(count!=1||(*tmp).next!=NULL)
    {
        count--;
        *tmp=*tmp->next;
    }
    int beforeSpace=cntBeforeSpace(string);
    (*tmp).key=realloc((*tmp).key,sizeof(char)*beforeSpace);
    (*tmp).key= strncpy((*tmp).key,string,beforeSpace);
    (*tmp).key[beforeSpace-1]='\0';
    char* ip=strrchr(string, ' ');
    (*tmp).value=realloc((*tmp).value, sizeof(char)*(strlen(ip)+1));
    (*tmp).value= strncpy((*tmp).value,ip,(strlen(ip)+1));
    (*tmp).value[strlen(ip)]='\0';
    free(ip);
    (*arrayOfPtr)[hash(string)]=tmp;
}
void getNewObj(char* string, list** listOfData, list*** arrayOfPtr)
{
    if(doesListFull(listOfData))
    {
        changeLastObj(listOfData,string, arrayOfPtr);
    }
    else
    {

        //while((*tmp).key!=NULL&&(*tmp).next!=NULL)
          //  *tmp=*tmp->next;
          list* tmp;
          if((*listOfData)==NULL)
              tmp=(*listOfData);
          else
          {
              tmp = (list *) malloc(sizeof(list));
              list *toFindSpace = (*listOfData);
              int cnt=0;
              while((*toFindSpace).next!=NULL&&cnt!=(HASH_TABLE_SIZE-1))
              {
                  toFindSpace=(*toFindSpace).next;
                  cnt++;
              }
              (*toFindSpace).next=tmp;
              (*tmp).prev=toFindSpace;
          }
        int beforeSpace=cntBeforeSpace(string);
        (*tmp).key=(char*)malloc(sizeof(char)*beforeSpace);
        (*tmp).key= strncpy((*tmp).key,string,beforeSpace);
        (*tmp).key[beforeSpace-1]='\0';
        char* ip=strrchr(string, ' ');
        (*tmp).value=(char*)malloc( sizeof(char)*(strlen(ip)+1));
        (*tmp).value= strncpy((*tmp).value,ip,(strlen(ip)+1));
        (*tmp).value[strlen(ip)]='\0';
        (*arrayOfPtr)[hash(string)]=tmp;
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
        int checkHash=hash(buffer);
        if (strstr(buffer, "IN A") != NULL&&checkHash==countOfSize)
        {
            countOfSize++;
            getNewObj(buffer, listOfData,arrayOfPtr);
            fseek(DB,0, SEEK_SET);
        }
    }




}

list* createElOfList(char* value, char* key)
{

}


list* createList()
{

}
