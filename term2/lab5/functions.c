//
// Created by krilop on 5/6/23.
//

#include "functions.h"

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Пропустить символы до новой строки или конца файла
    }
}

char *readLineFromConsole()
{
    char *buffer = NULL;
    int bufsize = 0;
    int characters;
    int maxLineLength = 100; // Максимальная длина строки

    // Выделение начальной памяти для буфера
    buffer = (char *) malloc(maxLineLength * sizeof(char));
    if (buffer == NULL)
    {
        printf("Memory error.\n");
        return NULL;
    }

    // Чтение строки с консоли
    characters = getchar();
    int i = 0;
    while (characters != EOF && characters != '\n' && characters != '\r')
    {
        if (i >= bufsize - 1)
        {
            bufsize += maxLineLength;
            buffer = (char *) realloc(buffer, bufsize * sizeof(char));
            if (buffer == NULL)
            {
                printf("Memory error.\n");
                return NULL;
            }
        }
        buffer[i] = (char) characters;
        i++;
        characters = getchar();
    }
    buffer[i] = '\0';

    // Удаление символов \n и \r, если они присутствуют
    int length = strlen(buffer);
    if (length > 0 && (buffer[length - 1] == '\n' || buffer[length - 1] == '\r'))
    {
        buffer[length - 1] = '\0';
    }
    if (length > 1 && buffer[length - 2] == '\r')
    {
        buffer[length - 2] = '\0';
    }

    return buffer;
}

char *readLineFromFile(FILE *file)
{
    char *buffer = NULL;
    int bufsize = 0;
    int characters;

    // Выделение начальной памяти для буфера
    buffer = (char *) malloc(STRING * sizeof(char));
    if (buffer == NULL)
    {
        printf("Memory error.\n");
        return NULL;
    }

    // Чтение строки из файла
    characters = fgetc(file);
    int i = 0;
    while (characters != EOF && characters != '\n' && characters != '\r')
    {
        if (i >= bufsize - 1)
        {
            bufsize += STRING;
            buffer = (char *) realloc(buffer, bufsize * sizeof(char));
            if (buffer == NULL)
            {
                printf("Memory error.\n");
                return NULL;
            }
        }
        buffer[i] = (char) characters;
        i++;
        characters = fgetc(file);
    }
    buffer[i] = '\0';

    // Удаление символов \n и \r, если они присутствуют
    int length = strlen(buffer);
    if (length > 0 && (buffer[length - 1] == '\n' || buffer[length - 1] == '\r'))
    {
        buffer[length - 1] = '\0';
    }
    if (length > 1 && buffer[length - 2] == '\r')
    {
        buffer[length - 2] = '\0';
    }

    return buffer;
}


void addToFile(FILE *out, char *string)
{
    fseek(out, 0, SEEK_END);
    fprintf(out, "%s IN ", string);
    int choice;
    printf("CNAME or A(1/0)\n");
    while (1)
    {
        if (scanf("%d", &choice) != 1 || getchar() != '\n' || choice != 1 && choice != 0)
        {
            printf("Ops!.. Try again.\n");
            clearInputBuffer();
        }
        else
        {
            break;
        }
    }
    if (choice)
    {
        char *buffer = (char *) calloc(STRING, sizeof(char));
        fgets(buffer, STRING, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        fprintf(out, "CNAME %s\n", buffer);
    }
    else
    {
        char *buffer = (char *) calloc(STRING, sizeof(char));
        fgets(buffer, STRING, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        fprintf(out, "A %s\n", buffer);
    }
}

void findDomain(FILE *in, char *ip)
{
    char *buffer;
    fseek(in, 0, SEEK_SET);
    while ((buffer = readLineFromFile(in)) != NULL)
    {
        if (strstr(buffer, ip) != NULL)
        {
            char *result = (char *)malloc((strcspn(buffer, " ") + 1) * sizeof(char));  // Выделяем память для результата
            strncpy(result, buffer, strcspn(ip, " "));  // Копируем строку до пробела
            result[strcspn(buffer, " ")] = '\0';
            int i=1;
            printf("%d.%s\n",i,result);
            fseek(in,0,SEEK_SET);
            while ((buffer = readLineFromFile(in)) != NULL&&!feof(in))
            {
                if (strstr(buffer, result) != NULL&&strstr(buffer, ip) == NULL)
                {
                    i++;
                    printf("%d.%.*s\n",i,strcspn(buffer, " "),buffer);
                }
            }
            return;
        }
    }
    printf("I don't know this ip.\n");
}


char *findIp(FILE *in, char *domain, LRUCache *cache)
{
    char *buffer;
    fseek(in, 0, SEEK_SET);
    while ((buffer = readLineFromFile(in)) != NULL)
    {
        if (strstr(buffer, domain) != NULL)
        {
            char *tmp = strdup(strrchr(buffer, ' ') + 1);

            if (strstr(buffer, INA) != NULL)
            {
                char *existingValue = get(cache, domain);
                if (existingValue != NULL)
                {
                    free(tmp);  // Освобождаем память, выделенную для нового значения
                    tmp = strdup(existingValue);  // Создаем копию существующего значения
                }
                else
                {
                    put(cache, domain, tmp);  // Добавляем новое значение в кеш
                }
                return tmp;
            }
            else
            {
                return findIp(in, tmp, cache);
            }
        }
    }
    addToFile(in, domain);
    return NULL;
}


void menu(FILE *resource)
{
    LRUCache *cache = createLRUCache(HASH_TABLE_SIZE);

    // Вывод: (null)
    while (1)
    {
        int operation;
        printf("1.Domain to ip\n2.Ip to domain\n3.Print cache\n4.Add new domain to file\n5.Exit\n");
        while (1)
        {
            if (scanf("%d", &operation) != 1 || getchar() != '\n' || operation < 1 || operation > 5)
            {
                printf("Ops!.. Try again.\n");
                clearInputBuffer();
            }
            else
            {
                break;
            }
        }
        switch (operation)
        {
            case 1:
            {
                printf("Input domain name:\n");
                char *buffer = readLineFromConsole();
                char *tmp = get(cache, buffer);
                if (tmp == NULL)
                {
                    tmp = findIp(resource, buffer, cache);
                }
                printf("Domain: %s\tIp: %s\n", buffer, tmp);
                break;
            }
            case 2:
            {
                printf("Input ip:\n");
                char *buffer = readLineFromConsole();
                findDomain(resource,buffer);
                break;
            }
            case 3:
            {
                printLRUCache(cache);
                break;
            }
            case 4:
            {
                printf("Input domain name:\n");
                char *buffer = readLineFromConsole();
                addToFile(resource, buffer);
                break;
            }
            case 5:
                return;
        }
    }
    destroyLRUCache(cache);
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