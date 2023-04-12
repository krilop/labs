//
// Created by krilop on 3/22/23.
//

#include "functionsForCompressing.h"

#define SIZE_OF_STRING 550

void pushInStack(stack **head, char *word)
{
    stack *tmp;
    tmp = (stack *) malloc(sizeof(stack));
    if (tmp == NULL) exit(EXIT_FAILURE);
    tmp->word = (char *) malloc(sizeof(char) * (strlen(word) + 1));//!!!!!!Проверить эту единицу
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

        fgets(string, SIZE_OF_STRING, *f);
        char *delim = " ";
        char *token = strtok(string, delim);
        while (token != NULL)
        {
            if (strchr(token, '\r') != NULL)
            {
                *(strchr(token, '\r')) = '\0';
            }
            if (strchr(token, '\n') != NULL)
            {
                *(strchr(token, '\n')) = '\0';
            }
            if (strcmp(token, "") != 0)
            {
                pushInStack(head, token);
            }
            token = strtok(NULL, delim);
        }

    }
    free(string);
}

void splitForReplace(FILE **f, stack **head)
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


void putWordsInArray(stack **head, words **arrayOfWords, int *size)
{

    char *buffer = (char *) malloc(SIZE_OF_STRING * sizeof(char));
    int i = 0;
    *arrayOfWords = (words *) malloc(sizeof(words));
    while (*head != NULL)
    {

        buffer = (char *) realloc(buffer, sizeof(char) * (1 + strlen((*head)->word)));
        strcpy(buffer, (*head)->word);
        // (*arrayOfWords)[i - 1].word = (char *) malloc(sizeof(char) * strlen((*arrayOfWords)[i - 1].word));

        for (int j = 0; j < i + 1; j++)
        {
            if (j == i)
            {
                i++;
                *arrayOfWords = (words *) realloc(*arrayOfWords, sizeof(words) * i);
                (*arrayOfWords)[j].word = (char *) malloc(sizeof(char) * (1 + strlen(buffer)));
                strcpy((*arrayOfWords)[j].word, buffer);
                (*arrayOfWords)[j].count = 1;
                (*arrayOfWords)[j].length = strlen(buffer);
                (*arrayOfWords)[j].markAsUsed = 0;
                break;
            }
            if (strcmp((*arrayOfWords)[j].word, buffer) == 0)
            {
                (*arrayOfWords)[j].count += 1;
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
        int flag=0;
        for (int j = 0; j < size; j++)
        {
            int profitFirstWord = (*arr)[i].length * ((*arr)[i].count);
            int profitSecondWord = (*arr)[i].length * ((*arr)[j].count);
            if (profitFirstWord < profitSecondWord)
            {
                flag=1;
                words tmp;
                tmp.word = (char *) malloc(sizeof(char) * (1 +(*arr)[i].length));
                strcpy(tmp.word, (*arr)[i].word);
                tmp.length=(*arr)[i].length;
                tmp.count = (*arr)[i].count;
                (*arr)[i].word = (char *) realloc((*arr)[i].word, sizeof(char) * (1 + (*arr)[j].length));
                strcpy((*arr)[i].word, (*arr)[j].word);
                (*arr)[i].count = (*arr)[j].count;
                (*arr)[j].word = (char *) realloc((*arr)[j].word, sizeof(char) * (1 + tmp.length));
                strcpy((*arr)[j].word, tmp.word);
                (*arr)[j].count = tmp.count;
                free(tmp.word);
            }
        }
        if(!flag)
            break;
    }
}

void pair(words **arr, int size, pairs **newArr, int *countOfPairs)
{
    int profit, max;
    *countOfPairs = 0;
    int indFirstWord = 0;
    int indSecondWord = 0;
    words tmp1, tmp2;
    tmp1.word = (char *) malloc(sizeof(char));
    tmp2.word = (char *) malloc(sizeof(char));
    (*newArr) = (pairs *) malloc(sizeof(pair));
    do
    {
        max = 0;

        for (int i = 0; i < size; i++)
        {
            if ((*arr)[i].markAsUsed == 1)
            {
                continue;
            }
            for (int j = 0; j < size; j++)
            {
                if ((*arr)[j].markAsUsed == 1)
                {
                    continue;
                }
                profit = (int) ((*arr)[i].length * (*arr)[i].count
                        + (*arr)[j].length * (*arr)[j].count
                        - (*arr)[i].length * (*arr)[j].count
                        - (*arr)[j].length * (*arr)[i].count
                        -(*arr)[i].length -(*arr)[j].length- 2);
                if (profit > max)
                {
                    max = profit;

                    tmp1.word = (char *) realloc(tmp1.word, sizeof(char) * (1 + (*arr)[i].length));
                    strcpy(tmp1.word, (*arr)[i].word);
                    tmp1.count = (*arr)[i].count;
                    indFirstWord = i;
                    tmp2.word = (char *) realloc(tmp2.word, sizeof(char) * (1 + (*arr)[j].length));
                    strcpy(tmp2.word, (*arr)[j].word);
                    tmp2.count = (*arr)[j].count;
                    indSecondWord = j;
                }
            }
        }
        if (max > 0)
        {
            (*countOfPairs)++;
            //Занести слово1 с индексом первого в пару, занести слово2 с индексом второго
            (*newArr) = (pairs *) realloc((*newArr), sizeof(pairs) * (*countOfPairs));
            (*newArr)[*countOfPairs - 1].word1 = (char *) malloc(sizeof(char) * (1 + strlen((*arr)[indFirstWord].word)));
            (*newArr)[*countOfPairs - 1].word2 = (char *) malloc(sizeof(char) * (1 + strlen((*arr)[indSecondWord].word)));
            strcpy((*newArr)[*countOfPairs - 1].word1, (*arr)[indFirstWord].word);
            strcpy((*newArr)[*countOfPairs - 1].word2, (*arr)[indSecondWord].word);
            (*arr)[indFirstWord].markAsUsed = 1;
            (*arr)[indSecondWord].markAsUsed = 1;
        }

    } while (max > 0);

}

void replace(pairs **arrayOfPairs, int countOfPairs, FILE *source, FILE *result)
{
    stack *head = NULL;
    splitForReplace(&source, &head);
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
    for (int i = 0; i < sizeOfArray; i++)
    {
        free((*arrayOfWords)[i].word);
    }
    free(*arrayOfWords);
    free(arrayOfWords);
    char *nameAfterCompressing = "";
    nameAfterCompressing = (char *) calloc(((int) strlen(name) + (int) strlen(".compressed") + 1), sizeof(char));
    strcat(strcat(nameAfterCompressing, name), ".compressed");
    f = fopen(nameAfterCompressing, "wb+");
    fseek(f, 0, SEEK_SET);
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < countOfPair; i++)
    {
        fputs(twoWords[i].word1, f);
        fputs(" ", f);
        fputs(twoWords[i].word2, f);
        fputs("\n", f);
    }
    fputs("@#$\n", f);
    fclose(f);
    FILE *file = fopen(nameAfterCompressing, "ab");
    f = fopen(name, "rb");
    if (file == NULL || f == NULL)
    {
        exit(EXIT_FAILURE);
    }
    replace(&twoWords, countOfPair, f, file);
    long int lSize = ftell(file);
    printf("Size of file after compressing:%ld\n", lSize);
    fclose(file);
    fclose(f);
}
