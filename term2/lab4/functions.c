#include "functions.h"

#define SIZE_OF_STRING 256

int getAnswer(char *question)
{
    char tmp;
    if (strchr(question, '?') == NULL)
        printf("Is your character %s? (y/n)\n", question);
    else
        printf("%s (y/n)\n", question);

    while (scanf(" %c", &tmp) != 1 || (tmp != 'y' && tmp != 'n') || getchar() != '\n')
    {
        printf("Error! Try again..\n");
        while (getchar() != '\n');
    }

    if (tmp == 'y')
        return 1;
    else
        return 0;
}
void ask(node *question)
{
    int answer = getAnswer((*question).question);
    if(answer&&question->left==NULL)
        printf("EEEEEEEEE, BOOOOOODYYYYYY! Light game!\n");
    else if(answer)
        ask(question->left);
    else if(!answer&&question->right==NULL)
    {
        printf("OKEY, MAN. I'm lose! Are u glad? Tell me, what is ur character?\n");
        char* buffer=(char*)calloc(SIZE_OF_STRING,sizeof(char));
        fgets(buffer,SIZE_OF_STRING,stdin);
        (*question).left= newNode((*question).question);
        (*question).right= newNode(buffer);
        printf("Special characteristic of my variant?\n");
        fgets(buffer,SIZE_OF_STRING,stdin);
        (*question).question=(char*)realloc((*question).question, sizeof(char)*(2+strlen(buffer)));
        (*question).question= strdup(buffer);
        (*question).question[strlen(buffer)-1]='?';
        (*question).question[strlen(buffer)]='\0';
        free(buffer);
    }
    else
        ask(question->right);

}

void startGame(node *root)
{
    if (root == NULL)
    {
        printf("My base is clear\n");
    }
    ask(root);
}


node* loadDB(FILE *DB)
{
    if (feof(DB))
        return NULL;
    char *buffer = (char *) calloc(SIZE_OF_STRING + 1, sizeof(char));
    fgets(buffer, SIZE_OF_STRING, DB);

    if(strcmp("None\n", buffer)==0)
    {
        free(buffer);
        return NULL;
    }
    else
    {
        node *nw = newNode(buffer);
        free(buffer);
        updateHeight(nw);
        balance(nw);
        (*nw).left = loadDB(DB);
        (*nw).right = loadDB(DB);
        return nw;
    }

}
void saveDB(node* nd, FILE * DB)
{
    if(nd==NULL)
    fprintf(DB,"None\n");
    else
    {

        fprintf(DB, (*nd).question);
        if(strchr((*nd).question,'\n')==NULL)
            fprintf(DB, "\n");
        saveDB((*nd).left,DB);
        saveDB((*nd).right,DB);
    }
}
