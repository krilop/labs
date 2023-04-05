//
// Created by krilop on 3/22/23.
//

#include "functions.h"

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


void pushInStack(stack **head, char *word, int cnt)
{
    stack *tmp;
    tmp = (stack *) malloc(sizeof(stack));
    tmp->word = word;
    tmp->length = strlen(word);
    tmp->count = cnt;
    tmp->flagOfUsing = 0;
    tmp->next = NULL;
    if (*head == NULL)
    {
        *head = tmp;
        return;
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
        *head = tmp->next;
        free(tmp->word);
        free(tmp);
    }
}

void split(char *buffer, char *delimiter, words *arrayOfWords)
{
    char *token = strtok(buffer, delimiter);
    while (token != NULL)
    {
        arrayOfWords->word = (char **) realloc(arrayOfWords->word, (arrayOfWords->length + 1) * sizeof(char *));
        *(arrayOfWords->word + arrayOfWords->length) = (char *) malloc(strlen(token) + 1);
        arrayOfWords->word[arrayOfWords->length] = token;
        arrayOfWords->length++;
        token = strtok(NULL, delimiter);
    }
}

int doesItExist(stack *head, char *string)
{
    while (head)
    {
        if (strcmp(head->word, string) == 0) return 1;
        head = head->next;
    }
    return 0;
}

void putWordsInTheStack(stack **head, words *arrayOfWords)
{
    for (int i = 0; i < arrayOfWords->length; i++)
    {
        if (doesItExist(*head, arrayOfWords->word[i]))
        {
            continue;
        }
        if (strstr(arrayOfWords->word[i], "\n") != NULL)
        {
            continue;
        }
        int count = 0;
        for (int j = 0; j < arrayOfWords->length; j++)
        {
            if (strcmp(arrayOfWords->word[j], arrayOfWords->word[i]) == 0)
            {
                count++;
            }
        }
        pushInStack(&(*head), arrayOfWords->word[i], count);
    }
    //bubbleSort(*head);
}

/*
stack* FindNext(stack* head,stack* next)
{
    stack* p=head;
    while(p->next!=next) p=p->next;
    return p;
}
void bubbleSort(stack* head)
{
    stack *p1;
    stack *p2;
    int v;
    if(!head) return;
    for(p1=head; p1->next; p1=p1->next)
        for(p2=FindNext(p1,NULL); p2!=p1; p2=FindNext(p1,p2))
            if(p1->count*p1->length>p2->count*p2->length)
            {
                stack* tmp=p1;
                p1=p2;
                p2=tmp;
            }

}*/

int calculateTheProfit(stack *word1, stack *word2)
{
    if (word1->count <= word2->count)
    {return 0;}
    else if (word1->flagOfUsing || word2->flagOfUsing)
    {return -1;}
    else
    {
        return (int) ((word1->count * word1->length + word2->count * word2->length) -
                (word1->count * word2->length + word2->count * word1->length) -
                (word1->length + word2->length + 2));
    }
}

void markWord(stack *head, char *word)
{
    while (head != NULL)
    {
        if (strcmp(head->word, word) == 0)
        {
            head->flagOfUsing = 1;
            return;
        }
        head = head->next;
    }
}

void swap(words *arrayOfWords, char *a, char *b)
{
    for (int i = 0; i < arrayOfWords->length; ++i)
    {

        if (strcmp(arrayOfWords->word[i], a) == 0)
        {

            arrayOfWords->word[i] = b;
        }
        else if (strcmp(arrayOfWords->word[i], b) == 0)
        {
            arrayOfWords->word[i] = a;

        }

    }
}

void replace(stack *head, words *arrayOfWords, char *name)
{
    fclose(fopen(name, "w"));
    FILE *f = fopen(name, "ab");
    if (f == NULL) exit(EXIT_FAILURE);

    stack *word1 = head;
    int i = 1;

    char *word;
    while (word1)
    {
        int max = 0;
        stack *word2 = head;

        while (word2)
        {

            int profit = calculateTheProfit(word1, word2);
            if (profit > max)
            {
                max = profit;
                word = word2->word;
            }
            word2 = word2->next;

        }
        if (max > 0)
        {

            markWord(head, word);
            markWord(head, word1->word);
            if (strlen(word) == 0 || strlen(word1->word) == 0) continue;
            swap(arrayOfWords, word1->word, word);

            fputs(word1->word, f);
            fputs(" ", f);
            fputs(word, f);
            fputs("\n", f);

        }
        word1 = word1->next;
        i++;
        float progr = (float) i;
        progr /= (float) arrayOfWords->length;
        progr *= 100;
        int bar = (int) progr;
        printf("[");
        for (int k = 0; k < 100; k++)
        {
            if (k <= bar)
            {
                printf("=");
            }
            else
            {printf(" ");}
        }
        printf("] %d%%\n", bar);
    }

    fputs("$#@\n", f);
    fclose(f);

}


void compress(char *name)
{
    long int lSizeBefore;
    char *buffer = readFile(name);
    FILE *f = fopen(name, "rb");
    fseek(f, 0, SEEK_END);
    lSizeBefore = ftell(f);
    fseek(f, 0, SEEK_SET);
    printf("Size of file before compressing: %ld\n", lSizeBefore);

    // char *buffer = (char *) calloc(255, sizeof(char));
    freopen(name, "r", f);
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }
    words arrayOfWords;
    arrayOfWords.length = 0;
    arrayOfWords.word = (char **) malloc(0);
    split(buffer, " ", &arrayOfWords);
    stack *head = NULL;


    putWordsInTheStack(&head, &arrayOfWords);

    char *nameAfterCompressing = (char *) malloc((strlen(name) + strlen(".compressed")) * sizeof(char));
    strcat(strcat(nameAfterCompressing, name), ".compressed");
    replace(head, &arrayOfWords, nameAfterCompressing);
    f = fopen(nameAfterCompressing, "a");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < arrayOfWords.length; i++)
    {
        fputs(arrayOfWords.word[i], f);
        if (i != arrayOfWords.length - 1) fputs(" ", f);
    }
    freopen(nameAfterCompressing, "rb", f);
    fseek(f, 0, SEEK_END);
    long int lSizeAfter = ftell(f);
    printf("Length of file after compressing: %ld\n", lSizeAfter);
    printf("Size of file before compressing: %ld\n", lSizeBefore);
    free(buffer);
}

void decompress(char *name)
{
    char* nameTmp=name;

    strcat(name, ".compressed");
    char *bufferCompr = readFile(name);
    if (bufferCompr == NULL) exit(EXIT_FAILURE);
    char *pos = bufferCompr;
    bufferCompr = strstr(bufferCompr, "$#@")+sizeof ("$#@");

    long int length =0;
    length+=strlen(pos);
    length-=strlen(bufferCompr);
    length-=strlen("$#@\n");
    pos = (char *) realloc(pos, sizeof(char) * (length));
    //pos= strncpy(pos,pos,sizeof(char) * (length));
    words arrayOfCompr;
    arrayOfCompr.length = 0;
    arrayOfCompr.word = (char **) malloc(0);


    //возможно, здесь много ем
    words arrayOfDictionary;
    arrayOfDictionary.length = 0;
    arrayOfDictionary.word = (char **) malloc(0);
    split(pos, "\n", &arrayOfDictionary);
    split(bufferCompr, " ", &arrayOfCompr);
    for (int i = 0; i<arrayOfDictionary.length; i++)
    {
       // if( arrayOfDictionary.word[i]=="$#@\n")
        //    break;
        words words;
        words.length = 0;
        words.word = (char **) malloc(0);
        split(arrayOfDictionary.word[i], " ", &words);
        if (words.length != 2) continue;
        swap(&arrayOfCompr, words.word[0], words.word[1]);
    }
    char *nameAfterDecompressing = (char *) malloc((strlen(nameTmp) + strlen(".decompressed")) * sizeof(char));
    strcat(strcat(nameAfterDecompressing, nameTmp), ".decompressed");

    FILE *f = fopen(nameAfterDecompressing, "w");
    if (f == NULL) exit(EXIT_FAILURE);
    freopen(nameAfterDecompressing, "ab", f);
    if (f == NULL) exit(EXIT_FAILURE);

    for (int i = 0; i < arrayOfCompr.length; i++)
    {
        fputs(arrayOfCompr.word[i], f);
        if (i != arrayOfCompr.length - 1) fputs(" ", f);
    }
    fseek(f, 0, SEEK_END);
    long int lSizeDecompress = ftell(f);
    fclose(f);

    printf("New size: %d\n", lSizeDecompress);
    printf("File decompressed!\n");
}