//
// Created by krilop on 3/22/23.
//

#include "functions.h"

#define SIZE_OF_STRING 255

char *readFile(char *nameOfFile)
{
    FILE *f = fopen(nameOfFile, "rb");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }
    fseek(f, 0, SEEK_END);
    long int length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *text = (char *) malloc(length);
    fread(text, 1, length, f);
    fclose(f);
    text[length - 1] = '\0';
    return text;
}


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
            exit(EXIT_FAILURE);
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


void putWordsInArray(stack **head, words **arrayOfWords, int *size)
{

    char* buffer=(char*)malloc(SIZE_OF_STRING*sizeof(char));
    int i = 0;
    *arrayOfWords = (words *) malloc( sizeof(words));
    while (*head != NULL)
    {

        buffer = (char *) realloc(buffer,sizeof(char) * (1+strlen((*head)->word)));
        strcpy(buffer,(*head)->word);
       // (*arrayOfWords)[i - 1].word = (char *) malloc(sizeof(char) * strlen((*arrayOfWords)[i - 1].word));

        for (int j = 0; j < i+1; j++)
        {
            if (j == i)
            {
                i++;
                *arrayOfWords = (words *) realloc(*arrayOfWords, sizeof(words)*i);
                (*arrayOfWords)[j].word = (char *) malloc(sizeof(char) * (1+strlen(buffer)));
                strcpy((*arrayOfWords)[j].word,buffer);
                (*arrayOfWords)[j].count = 1;
                (*arrayOfWords)[j].markAsUsed=0;
                break;
            }
            if (strcmp((*arrayOfWords)[j].word, buffer) == 0)
            {
                (*arrayOfWords)[j].count+=1;
                break;
            }
        }
        popOutOfStack(head);
    }
    free(buffer);
    *size = i;
}

void sortWords(words **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int countFirst=((*arr)[i].count);
            int countSecond=((*arr)[j].count);
            int lengthFirst=(int)strlen(((*arr)[i].word));
            int lengthSecond=(int)strlen(((*arr)[j].word));
            int profitFirstWord=lengthFirst *countFirst ;
            int profitSecondWord=lengthSecond * countSecond;
            if (profitFirstWord < profitSecondWord )
            {
                words tmp;
                tmp.word =(char*)malloc(sizeof(char)*(1+strlen((*arr)[i].word)));
                strcpy(tmp.word,(*arr)[i].word);
                tmp.count=(*arr)[i].count;
                (*arr)[i].word =(char*)realloc((*arr)[i].word,sizeof(char)*(1+strlen((*arr)[j].word)));
                strcpy((*arr)[i].word,(*arr)[j].word);
                (*arr)[i].count=(*arr)[j].count;
                (*arr)[j].word =(char*)realloc((*arr)[j].word,sizeof(char)*(1+strlen(tmp.word)));
                strcpy((*arr)[j].word,tmp.word);
                (*arr)[j].count=tmp.count;
                free(tmp.word);
            }
        }
    }
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
    (*newArr) = (pairs *) malloc(sizeof(pair));
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
    stack* head=NULL;
    split(&source, &head);
    stack* tmp=head;
    while(tmp!=NULL)
    {
        for(int i =0; i<countOfPairs;i++)
        {
            if(strcmp(tmp->word,(*arrayOfPairs)[i].word1)==0)
            {
                tmp->word=(char*)realloc(tmp->word,sizeof(char)*(strlen((*arrayOfPairs)[i].word2)+1));
                strcpy(tmp->word,(*arrayOfPairs)[i].word2);
            } else if(strcmp(tmp->word,(*arrayOfPairs)[i].word2)==0)
            {
                tmp->word=(char*)realloc(tmp->word,sizeof(char)*(strlen((*arrayOfPairs)[i].word1)+1));
                strcpy(tmp->word,(*arrayOfPairs)[i].word1);
            }
        }
        tmp=tmp->next;
    }
    for (int i = 0; i <countOfPairs; ++i)
    {
        free((*arrayOfPairs)[i].word1);
        free((*arrayOfPairs)[i].word2);
    }
    stack* newHead=NULL;
    while(head!=NULL)
    {
        pushInStack(&newHead, head->word);
        popOutOfStack(&head);
    }
    while(newHead!=NULL)
    {
        fputs(newHead->word,result);
        fputs(" ",result);
        popOutOfStack(&newHead);
    }
    free(head);
    free(newHead);

}

void compress(char *name)
{
    FILE *f = fopen(name, "rb");
    if (f == NULL) exit(EXIT_FAILURE);
    fseek(f, 0, SEEK_END);
    printf("Size of file before compressing:%ld\n", ftell(f));
    stack *head = NULL;
    fseek(f, 0, SEEK_SET);
    split(&f, &head);
    fclose(f);
    words **arrayOfWords = (words **) malloc(sizeof(words *));
    int sizeOfArray = 0;
    putWordsInArray(&head, arrayOfWords, &sizeOfArray);
    int countOfPair = 0;
    sortWords(arrayOfWords, sizeOfArray);
    pairs *twoWords;
    pair(arrayOfWords, sizeOfArray, &twoWords, &countOfPair);
    for (int i = 0; i <sizeOfArray; i++)
        free((*arrayOfWords)[i].word);
    free(*arrayOfWords);
    free(arrayOfWords);
    char* nameAfterCompressing="";
    nameAfterCompressing= (char*)calloc(((int)strlen(name) + (int)strlen(".compressed")+1), sizeof(char));
    strcat(strcat(nameAfterCompressing, name), ".compressed");
    f = fopen(nameAfterCompressing, "wb+");
    fseek(f,0,SEEK_SET);
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < countOfPair; i++)
    {
        fputs(twoWords[i].word1,f);
        fputs(" ",f);
        fputs(twoWords[i].word2,f);
        fputs("\n",f);
    }
    fputs("@#$\n",f);
    fclose(f);
    FILE* file= fopen(nameAfterCompressing,"ab");
    f= fopen(name,"rb");
    if(file==NULL||f==NULL)
        exit(EXIT_FAILURE);
    replace(&twoWords,countOfPair,f,file);
    long int lSize=ftell(file);
    printf("Size of file after compressing:%ld\n", lSize);
    fclose(file);
    fclose(f);
}

void decompress(char *name)
{
    FILE *f = fopen(name, "rb");
    if (f == NULL) exit(EXIT_FAILURE);
    fseek(f, 0, SEEK_END);
    printf("Size of file before compressing:%ld", ftell(f));
    fclose(f);
    char* nameAfterCompressing="";
    nameAfterCompressing= (char*)calloc(((int)strlen(name) + (int)strlen(".compressed")+1), sizeof(char));
    strcat(strcat(nameAfterCompressing, name), ".compressed");
    f = fopen(nameAfterCompressing, "rb");
    if (f == NULL) exit(EXIT_FAILURE);
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
            pushInStack(&head, token);
            token = strtok(NULL, delim);
        }
    }
    free(string);
    int countOfPair = 0;
    pairs *twoWords=calloc(1,1);
    while(head!=NULL||head->next!=NULL)
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
    FILE* result = fopen(nameAfterDecompressing, "rb");
    replace(&twoWords,countOfPair,result,f);
    printf("Size of file after decompressing:%ld", ftell(result));
}