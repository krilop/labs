//
// Created by krilop on 5/6/23.
//

#include "functions.h"

int cntBeforeSpace(char* string)
{
    int cnt=1;
    while(string[cnt-1]!=' ')
        cnt++;
    return cnt;

}
char* findIp(FILE* in, char* domain)
{
    char* buffer = (char*)calloc(STRING, sizeof(char));
    while(!feof(in))
    {
        fgets(buffer, STRING, in);
        if(strstr(buffer, domain)!=NULL)
            if(strstr(buffer,INA)!=NULL)
                return strdup(strrchr(domain,' '));
            else
                return findIp(in, strrchr(buffer,' '));
    }
    return NULL;
}

void ipInCache(char*domain, node**hashTable, node** cache)
{
    hashTable[hash(domain)];
    if(strcmp(domain,(*(hashTable[hash(domain)])).key)==0)
    {
        printf("%s",(*(hashTable[hash(domain)])).value);
        earlier((hashTable[hash(domain)]),cache);
        return;
    }
    dnode* tmp=(*(hashTable[hash(domain)])).deep;
    while(tmp!=NULL)
    {
        if(strcmp(domain,(*tmp).key)==0)
        {
            printf("%s",(*(hashTable[hash(domain)])).value);
            earlier((hashTable[hash(domain)]),cache);//левее в списке
            upper((hashTable[hash(domain)]),tmp);//выше в списке
            return;
        }
        tmp=(*tmp).deep;
    }
}
int checkInCache(char* buffer, node** hashTable, node* head)
{
    if(hashTable[hash(buffer)]!=NULL&&((*hashTable[hash(buffer)]).key&&checkNextValues((*hashTable[hash(buffer)]).key,buffer)))
        return 0;
    return 1
}
void menu(FILE* resource)
{
    node** hashtable=(node**)calloc(HASH_TABLE_SIZE, sizeof(node*));
    int retry=1;
    while(retry)
    {
        int operation;
        printf("Domain to ip?(1-y/0-n)\n");
        while(scanf("%d",&operation)!=1||getchar()!='\n'||operation!=0&&operation!=1)
        {
            printf("Ops!.. Try again.\n");
            rewind(stdin);
        }
        if(operation)
        {
            printf("Input domain name:\n");
            char *buffer = (char *) calloc(STRING, sizeof(char));
            fgets(buffer, STRING, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            if(checkInCache(buffer,hashtable,head))
            {
                ipInCache(buffer,hashtable,head);
            }
            else
            {
                char *ip = findIp(resource, buffer);
                if (ip == NULL)
                    addDomain(resource, buffer);
                else
                    yes;
            }
        }
        else
        {}
        printf("Again?(1-y/0-n)\n");
        while(!scanf("%d",&retry)||getchar()!='\n'||retry!=0&&retry!=1)
        {
            printf("Ops!.. Try again.\n");
            rewind(stdin);
        }
    }
}











































/*
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
        buffer[strlen(buffer)] = '\0';//Стр лен -1 Чтобы не было \н
        int checkHash=hash(buffer);
        if (strstr(buffer, "IN A") != NULL&&checkHash==countOfSize)
        {
            countOfSize++;
            getNewObj(buffer, listOfData,arrayOfPtr);
            fseek(DB,0, SEEK_SET);
        }
    }

}
*/