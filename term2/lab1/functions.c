//
// Created by krilop on 12.02.23.
//

#include "functions.h"
#include "sorts.h"

char *getStr()
{
    int length = 1;
    char *string = (char *) malloc(length * sizeof(char));
    for (int i = 0;; i++) {
        string[i] = (char) getchar();
        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }
        length++;
        string = (char *) realloc(string, length);
    }
    return string;
}

void parsing(t **array, FILE *f, int *sizeOfArray)
{
    int i = 0, j = 0, k = 0;
    char *buffer;
    char *buffer2;
    char *end_str;
    buffer = (char *) calloc(255, 1);
    buffer2 = (char *) calloc(255, 1);
    while (!feof(f)) {
        if (fgets(buffer, 255, f) != NULL) {
            if (strstr(buffer, ".&amp;&amp;&amp;&amp;&amp;0</span>") != NULL) {

                buffer2 = strrchr(buffer, '<') - 2;

                int num = 0;
                for (int l = 0; l < 3; ++l)
                    if (buffer2[l] <= '9' && buffer2[l] >= '0') {
                        num *= 10;
                        num = num + buffer2[l] - '0';
                    }
                (*array)[i].num = num;


            }
            if (strstr(buffer, "class=\"mw-redirect\" title=\"") != NULL) {
                /* while(strstr(buffer, "</a></span>") == NULL)
                 {
                     buffer2=buffer;
                     fgets(buffer, 15, f);
                     buffer2
                 }*/
                buffer2 = strrchr(buffer, '>') - 50;
                end_str = strchr(buffer2, '>') + 1;
                int length = (int) (strchr(end_str, '<') - end_str);
                (*array)[i].name = (char *) malloc(length * sizeof(char));
                strncpy((*array)[i].name, end_str, length);
            }

            if (strstr(buffer, "</a></td>") != NULL) {
                //fgets(buffer, 255, f);
                fgets(buffer, 10, f);
                buffer2 = strchr(buffer, '>') + 1;
                if (!strcmp("Ф</t", buffer2)) {
                    (*array)[i].pos = FORWARD;
                } else if (!strcmp("Ц</t", buffer2))
                    (*array)[i].pos = CENTER;
                else if (!strcmp("З</t", buffer2))
                    (*array)[i].pos = GUARD;
                else
                    printf("Error!");
                *sizeOfArray += 1;
                i++;
            }
            *array = (t *) realloc(*array, sizeof(t) * (*sizeOfArray));

        } else {
            perror("ERROR_GETS");
        }
    }
    *sizeOfArray -= 1;
    *array = (t *) realloc(*array, sizeof(t) * (*sizeOfArray));
}


void createArrayOfStruct(t **array, int *sizeOfArray)
{
    *array = (t *) malloc(sizeof(t) * (*sizeOfArray));
}

void printArrayOfStruct(t **array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("Index:%d\n Number of player:%d,\n Name:%s,\n Position:%s\n\n", i, (*array)[i].num, (*array)[i].name, pos[(*array)[i].pos]);
    }
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

//В стадии разработки
void initializateObjectOfStruct(t **array, int *sizeOfArray)
{
    *sizeOfArray = *sizeOfArray + 1;
    *array = (t *) realloc(*array, sizeof(t) * (*sizeOfArray));
    printf("Enter number of player:\n");

    int num;
    while (!scanf("%d", &(num)) || num < 0 || num > 99 || getchar() != '\n') {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    (*array)[(*sizeOfArray) - 1].num = num;
    printf("Enter name:\n");

    (*array)[(*sizeOfArray) - 1].name = getStr();
    //puts((*array)[*sizeOfArray - 1].name);
    char *str;
    printf("Enter position(CENTER/FORWARD/GUARD):\n");
    while (1) {
        str = getStr();
        if (!strcmp(str, pos[0]) || !strcmp(str, pos[1]) || !strcmp(str, pos[2])) {
            break;
        }
        printf("Error! try again\n");
        rewind(stdin);
    }
    if (!strcmp(str, pos[0]))
        (*array)[*sizeOfArray - 1].pos = CENTER;
    else if (!strcmp(str, pos[1]))
        (*array)[*sizeOfArray - 1].pos = FORWARD;
    else if (!strcmp(str, pos[2]))
        (*array)[*sizeOfArray - 1].pos = GUARD;
    else {
        printf("Critical error in initialization pos\n");
        exit(1);
    }
    (*array)[*sizeOfArray - 1].num = num;
    // free(str);
}

#pragma clang diagnostic pop

void deleteObjectOfStruct(t **array, int *sizeOfArray)
{
    int n;
    printf("Enter index of element.(If u don't know the index, enter -1)\n");
    while (!scanf("%d", &n) || n < -1 || n > (*sizeOfArray - 1)) {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    if (n == -1)
        return;
    for (int i = n; i <= *sizeOfArray - 1; i++)
        *(*array + i) = *(*array + i + 1);
    *sizeOfArray = *sizeOfArray - 1;
    *array = (t *) realloc(*array, sizeof(t) * (*sizeOfArray));
}

void menu(t **array, int *sizeOfArr)
{
    while (1) {
        printf("Choose operation:\n1.Print data\n2.add element\n3.delete element\n4.sort list\n5.end app\n");
        int res;
        while (!scanf("%d", &res) || res < 1 || res > 5) {
            printf("Error! Try again\n");
            rewind(stdin);
        }
        switch (res) {
            case 1:
                printArrayOfStruct(array, *sizeOfArr);
                break;
            case 2:
                initializateObjectOfStruct(array, sizeOfArr);
                break;
            case 3:
                deleteObjectOfStruct(array, sizeOfArr);
                break;
            case 4:
                sortStart(array, sizeOfArr);
                break;
            case 5:
                return;
                break;
            default:
                printf("critical error of menu\n");
                exit(1);
                break;
        }
    }
}
