//
// Created by krilop on 3/22/23.
//

#include "functionsForDecompressing.h"

#define SIZE_OF_STRING 500

void pushInStack(stack **head, char *word)
{
    stack *tmp;
    tmp = (stack *) malloc(sizeof(stack));
    if (tmp == NULL) exit(EXIT_FAILURE);
    tmp->word=(char*)malloc(sizeof(char)*(strlen(word)+1));//!!!!!!Проверить эту единицу
    strcpy(tmp->word, word);
    tmp->next = NULL;
    if (*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        tmp->next = *head;
        *head = tmp;
    }
}

void popOutOfStack(stack **head)
{
    if (*head == NULL)
    {
        printf("Ops! Stack is already empty :(\n");
        return;
    }
    else
    {
        stack *tmp;
        tmp = *head;
        *head = (*head)->next;
        free(tmp->word);
        free(tmp);
    }
}

void split(FILE **f, stack **head)
{
    char *string = (char *) malloc(sizeof(char) * (SIZE_OF_STRING));
    while (!feof(*f))
    {
        if (fgets(string, SIZE_OF_STRING, *f) == NULL)
        {
            return;
        }
        char *delim = " ";
        char *token = strtok(string, delim);
        while (token != NULL)
        {
            pushInStack(head, token);
            token = strtok(NULL, delim);
        }

    }
    free(string);
}

void pair(words **arr, int size, pairs **newArr, int *countOfPairs)
{
    int profit, max;
    *countOfPairs = 0;
    int indFirstWord = 0;
    int indSecondWord = 0;
    words tmp1,tmp2;
    tmp1.word =(char*)malloc(sizeof(char));
    tmp2.word =(char*)malloc(sizeof(char));
    (*newArr) = (pairs *) malloc(sizeof(pairs));
    do
    {
        max = 0;

        for (int i = 0; i < size; i++)
        {
            if((*arr)[i].markAsUsed==1)
                continue;
            for (int j = 0; j < size; j++)
            {
                if((*arr)[j].markAsUsed==1)
                    continue;
                profit = (int) (strlen((*arr)[i].word) * (*arr)[i].count
                        + (strlen((*arr)[j].word) * (*arr)[j].count
                        - strlen((*arr)[i].word) * (*arr)[j].count
                        - strlen((*arr)[j].word) * (*arr)[i].count - 2));
                if (profit > max)
                {
                    max = profit;

                    tmp1.word =(char*)realloc(tmp1.word,sizeof(char)*(1+strlen((*arr)[i].word)));
                    strcpy(tmp1.word,(*arr)[i].word);
                    tmp1.count=(*arr)[i].count;
                    indFirstWord=i;
                    tmp2.word =(char*)realloc(tmp2.word,sizeof(char)*(1+strlen((*arr)[j].word)));
                    strcpy(tmp2.word,(*arr)[j].word);
                    tmp2.count=(*arr)[j].count;
                    indSecondWord = j;
                }
            }
        }
        if (max > 0)
        {
            (*countOfPairs)++;
            //Занести слово1 с индексом первого в пару, занести слово2 с индексом второго
            (*newArr) = (pairs *) realloc((*newArr), sizeof(pairs) * (*countOfPairs));
            (*newArr)[*countOfPairs - 1].word1 = (char *) malloc(sizeof(char) * (1+strlen((*arr)[indFirstWord].word)));
            (*newArr)[*countOfPairs - 1].word2 = (char *) malloc(sizeof(char) * (1+strlen((*arr)[indSecondWord].word)));
            strcpy((*newArr)[*countOfPairs-1].word1,(*arr)[indFirstWord].word);
            strcpy((*newArr)[*countOfPairs-1].word2,(*arr)[indSecondWord].word);
            (*arr)[indFirstWord].markAsUsed=1;
            (*arr)[indSecondWord].markAsUsed=1;
        }

    } while (max > 0);

}
void replace(pairs ** arrayOfPairs, int countOfPairs, FILE *source, FILE *result)
{
    stack *head = NULL;
    split(&source, &head);
    stack *newHead = NULL;
    while (head != NULL)
    {
        pushInStack(&newHead, head->word);
        popOutOfStack(&head);
    }
    stack *tmp = newHead;
    char *buffer = (char *) malloc(SIZE_OF_STRING * sizeof(char));
    while (tmp != NULL)
    {
        buffer = (char *) realloc(buffer, sizeof(char) * (strlen(tmp->word) + 1));
        strcpy(buffer, tmp->word);
        strtok(buffer, "\r\n");
        int flag=0;
        for (int i = 0; i < countOfPairs; i++)
        {
            if (strcmp(buffer, (*arrayOfPairs)[i].word1) == 0)
            {
                flag=1;
                fputs((*arrayOfPairs)[i].word2, result);
            }
            else if (strcmp(buffer, (*arrayOfPairs)[i].word2) == 0)
            {
                flag=1;
                fputs((*arrayOfPairs)[i].word1, result);
            }
            if(flag)
            {
                if (strchr(tmp->word,'\r') != 0)
                    fputs("\r\n\0",result);
                else if (strchr(tmp->word,'\n') != 0)
                {
                    fputs("\n\0",result);
                }
                else
                    fputs(" ",result);
                break;
            }
        }
        if(flag)
        {
            popOutOfStack(&tmp);
            continue;
        }
        fputs(tmp->word,result);
        if (strchr(tmp->word,'\r') != NULL||strchr(tmp->word, '\n') != NULL)
        {
            fputs("\0",result);
        }else
            fputs(" ", result);
        popOutOfStack(&tmp);
    }
    free(buffer);
    for (int i = 0; i < countOfPairs; ++i)
    {
        free((*arrayOfPairs)[i].word1);
        free((*arrayOfPairs)[i].word2);
    }

    free(head);

}
void decompress(char *name)
{
    FILE *f = fopen(name, "rb");
    if (f == NULL) exit(EXIT_FAILURE);
    fseek(f, 0, SEEK_END);
    printf("Size of file before compressing:%ld\n", ftell(f));
    fclose(f);
    char* nameAfterCompressing="";
    nameAfterCompressing= (char*)calloc(((int)strlen(name) + (int)strlen(".compressed")+1), sizeof(char));
    strcat(strcat(nameAfterCompressing, name), ".compressed");
    f = fopen(nameAfterCompressing, "rb");
    if (f == NULL) exit(EXIT_FAILURE);
    fseek(f, 0, SEEK_END);
    printf("Size of file after compressing:%ld\n", ftell(f));
    fseek(f,0,SEEK_SET);
    stack* head=NULL;
    char *string = (char *) malloc(sizeof(char) * (SIZE_OF_STRING));
    while (!feof(f))
    {
        if (fgets(string, SIZE_OF_STRING, f) == NULL)
        {
            exit(EXIT_FAILURE);
        }
        if(strcmp(string,"@#$\n\0")==0)
            break;

        char *delim = " ";
        char *token = strtok(string, delim);
        while (token != NULL)
        {
            if(strchr(token, '\n')!=NULL)
                *(strchr(token,'\n'))='\0';
            pushInStack(&head, token);
            token = strtok(NULL, delim);
        }
    }
    free(string);
    int countOfPair = 0;
    pairs *twoWords=calloc(1,1);
    while(head!=NULL)
    {
        twoWords = (pairs *) realloc(twoWords, sizeof(pairs) * (countOfPair+1));
        twoWords[countOfPair].word1 = (char *) malloc(sizeof(char) * (1+strlen(head->word)));
        strcpy(twoWords[countOfPair].word1,head->word);
        popOutOfStack(&head);
        twoWords[countOfPair].word2 = (char *) malloc(sizeof(char) * (1+strlen(head->word)));
        strcpy(twoWords[countOfPair].word2, head->word);
        popOutOfStack(&head);
        countOfPair++;
    }
    char* nameAfterDecompressing="";
    nameAfterDecompressing= (char*)calloc(((int)strlen(name) + (int)strlen(".decompressed")+1), sizeof(char));
    strcat(strcat(nameAfterDecompressing, name), ".decompressed");
    FILE* result = fopen(nameAfterDecompressing, "wb");
    fclose(result);
    result=fopen(nameAfterDecompressing,"ab");
    if(result==NULL) exit(EXIT_FAILURE);
    replace(&twoWords,countOfPair,f,result);
    printf("Size of file after decompressing:%ld", ftell(result));
    free(twoWords);
    free(nameAfterCompressing);
    free(nameAfterDecompressing);
    fclose(result);
    fclose(f);
}