//
// Created by krilop on 5/6/23.
//

#include "functions.h"


int checkInFile(char *name, char *buffer)
{
    FILE *in = fopen(name, "r");
    fseek(in, 0, SEEK_SET);
    char *text;
    while (!feof(in))
    {
        text = readLineFromFile(in);
        if (strstr(text, buffer) != NULL)
        {
            return 0;
        }
        free(text);
    }
    return 1;
}

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

char *readLineFromFile(FILE *in)
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
    characters = fgetc(in);
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
        characters = fgetc(in);
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

int checkIp(char *ip)
{
    int n = 0;
    int j = 0;
    while (j < strlen(ip))
    {
        if (ip[j] == '.')
        {
            n++;
        }
        j++;
    }
    if (n != 3)
    {
        return 1;
    }
    j = 0;
    n = 0;
    for (int i = 0; i < 4 && j < (int) strlen(ip); i++)
    {

        n = 0;
        while (ip[j] != '.' && ip[j] != '\0')
        {
            n = 10 * n + ip[j] - '0';
            j++;
        }
        if (n < 0 || n > 255)
        {
            return 1;
        }
    }
    return 0;
}

void addToFile(FILE *out, char *name, char *string)
{
    freopen(name, "a+", out);
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
        char *buffer;
        printf("Please, entry main domain name\n");
        while (1)
        {
            buffer = readLineFromConsole();
            if (checkIp(buffer))
            {
                break;
            }

            free(buffer);
        }
        fprintf(out, "CNAME %s\n", buffer);
        if (checkInFile(name, buffer))
        {
            fprintf(out, "%s IN ", buffer);
            printf("Please, entry the ip of those domains\n");
            char *ip;
            while (1)
            {
                ip = readLineFromConsole();
                if (!checkIp(ip))
                {
                    fprintf(out, "A %s\n", ip);
                    break;
                }
                free(ip);
            }
            free(ip);
        }
        free(buffer);
    }
    else
    {
        printf("Please, entry the ip of this domain\n");
        char *ip;
        while (1)
        {
            ip = readLineFromConsole();
            if (!checkIp(ip))
            {
                fprintf(out, "A %s\n", ip);
                break;
            }
            free(ip);
        }
    }
    freopen(name, "r", out);
}

void findDomain(FILE *in, char *ip)
{
    char *buffer;
    char *answer;
    int flag = 0;
    fseek(in, 0, SEEK_SET);
    while (!feof(in))
    {
        buffer = readLineFromFile(in);
        if (strstr(buffer, ip) != NULL && flag == 0)
        {
            printf("domain: ");
            int i = 0;
            while (buffer[i] != ' ')
            {
                printf("%c", buffer[i]);
                i++;
            }
            answer = (char *) malloc(i * sizeof(char));
            i = 0;
            while (buffer[i] != ' ')
            {
                answer[i] = buffer[i];
                i++;
            }
            answer[i] = '\0';
            flag = 1;
            fseek(in, 0, SEEK_SET);
        }
        if (flag == 1 && (strstr(buffer, answer) != NULL) && (strstr(buffer, INA) == NULL))
        {
            printf("\ndomain: ");
            int i = 0;
            while (buffer[i] != ' ')
            {
                printf("%c", buffer[i]);
                i++;
            }
        }
        free(buffer);
    }
    if (flag == 0)
    {
        printf("I don't know this ip\n");
    }
}

char *findIp(FILE *in, char *domain, Cache *cache)
{
    char *answer = get(cache, domain);
    if (!answer)
    {
        findInFile(cache, domain, in);
        answer = get(cache, domain);
    }
    if (!answer) return NULL;
    if (!checkIp(answer))
    {return answer;}
    else
    {findIp(in, answer, cache);}
    return answer;
}


void menu(FILE *resource, char *name)
{
    Cache *cache = createCache(HASH_TABLE_SIZE);

    while (1)
    {
        int operation;
        printf("\n1.Domain to ip\n2.Ip to domain\n3.Print cache\n4.Add new domain to file\n5.Exit\n");
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
                char *buffer;
                while (1)
                {
                    printf("Input domain name:\n");
                    buffer = readLineFromConsole();
                    if (!checkIp(buffer))
                    {
                        continue;
                    }
                    break;
                }
                char *answ = findIp(resource, buffer, cache);
                free(buffer);
                if (answ == NULL)
                {
                    printf("I don't know this domain\n");
                }
                else
                {
                    printf("Ip:%s\n", answ);
                }
                break;
            }
            case 2:
            {

                char *buffer;
                while (1)
                {
                    printf("Input ip:\n");
                    buffer = readLineFromConsole();
                    if (checkIp(buffer))
                    {
                        continue;
                    }
                    break;
                }
                findDomain(resource, buffer);
                free(buffer);
                break;
            }
            case 3:
            {
                printCache(cache);
                break;
            }
            case 4:
            {
                char *buffer;
                while (1)
                {
                    printf("Input domain name:\n");
                    buffer = readLineFromConsole();
                    if (checkInFile(name, buffer) && checkIp(buffer))
                    {
                        break;
                    }
                    free(buffer);
                }
                addToFile(resource, name, buffer);
                free(buffer);
                break;
            }
            case 5:
                destroyCache(cache);
                return;
        }
    }

}
