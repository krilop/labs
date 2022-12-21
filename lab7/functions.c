#include "header.h"

void reset(int *reset)
{
    printf("Do u want to run app again?(yes-1, no-0)");
    while (scanf_s("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}

void chooseTask(int *choice)
{
    printf("Hello! I am consist of two task:\n 1. Given a string. Find the sum of numbers in a string\n2. Given strings S, S0 and numbers k, m. Insert from the k-th position of the string S the first m characters from the string S0\nPlease, enter your choice\n");
    while (scanf_s("%d", choice) != 1 || *choice != 1 && *choice != 2 || getchar() != '\n')
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
    // system("CLS");
    printf("task %d:\n", *choice);
}

void getStr(char **string, int length)
{
    printf("Input string:\n");
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        *(*string + i) = c;
        i++;
        length++;
        *string = (char *) realloc(*string, length);

    }
    *(*string + i) = '\0';
}


void printString(char **str)
{
    for (int i = 0; *(*str + i) != '\0'; i++)
        printf("%c", *(*str + i));
    printf("\n");
}

/*int charToInt(char *s)
{ 
  int n, i=0, znak;
  while(s[i]!='\0' &&  s[i]==' �)
		i++;

  if (s[i]=='\0') return 0;   
  i--;
  znak =(s[i]=='-') ? -1 : 1;
  if (s[i]=='+' || s[i]=='-')�
     i++;

  for(n=0; s[i]>='0' && ss[i]<='9';i++)
     n = 10*n + (s[i]-'0');
  return znak*n;    
*/
int ifNum(char s)
{
    if (s >= '0' && s <= '9')
        return 1;
    return 0;
}

void findCountOfNum(char *s, int *cnt)
{
    int i = 0;
    *cnt = 0;
    while (s[i] != '\0')
    {
        if ((i == 0 && ifNum(s[i]) == 1) || (ifNum(s[i - 1]) == 0 && ifNum(s[i]) == 1))
            *cnt += 1;
        i++;
    }
}

void findKNum(char *s, int k, int *ind)
{
    int i = 0, cnt = 0;

    while (s[i] != '\0')
    {
        if ((i == 0 && ifNum(s[i]) == 1) || (ifNum(s[i - 1]) == 0 && ifNum(s[i]) == 1))
            cnt++;
        if (cnt == k)
        {
            *ind = i;
            break;
        }
        i++;
    }
    if (cnt == 0)
        *ind = -1;
}

int charToInt(const char *s, int posOfStart)
{
    int n;
    int i;
    int znak;
    i = posOfStart - 1;
    znak = (s[i] == '-') ? -1 : 1;
    i++;
    for (n = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return znak * n;
}

int getNumOfStr(char **str, int posOfNum)
{
    int indOfNum;
    findKNum(*str, posOfNum, &indOfNum);
    return charToInt(*str, indOfNum);
}

void main1()
{//1.	���� ������. ����� ����� ����� � ������

    char **pstr = (char **) malloc(sizeof(char *));
    *pstr = (char *) malloc(sizeof(char));
    int length = 1;
    getStr(pstr, length);
    int countOfNum;
    findCountOfNum(*pstr, &countOfNum);
    int *parr = (int *) malloc(countOfNum * sizeof(int));
    for (int i = 1; i <= countOfNum; i++)
        *(parr + i - 1) = getNumOfStr(pstr, i);
    int sum = 0;
    for (int i = 0; i < countOfNum; i++)
        sum += parr[i];
    printf("sum of nums: %d\n", sum);
}

void move(char **str, int length, int k)
{
    for (int i = length; i >= k; i--)
        *(*str + i + 1) = *(*str + i);
    printString(str);
}

void getLength(char **s, int *length)
{
    int cnt = 0, i = 0;
    while (*(*s + i) != '\0')
    {
        cnt++;
        i++;
    }
    *length = cnt + 1;
}

void inputNum(int *num, int border)
{
    while (scanf_s("%d", num) != 1 || getchar() != '\n' || *num > border - 1)
    {
        printf("Error! Try again\n");
        rewind(stdin);
    }
}

void main2()
{
    //2.	���� ������ S, S0 � ����� k, m. �������� c k-�� ������� ������ S ������ m �������� �� ������ S0
    char **pstr1 = (char **) malloc(sizeof(char *));
    *pstr1 = (char *) malloc(sizeof(char));
    int length1 = 1;
    getStr(pstr1, length1);
    char **pstr2 = (char **) malloc(sizeof(char *));
    *pstr2 = (char *) malloc(sizeof(char));
    int length2 = 1;
    getStr(pstr2, length2);
    getLength(pstr1, &length1);
    getLength(pstr2, &length2);
    int k, m;
    printf("input how many symbols i may copy\n");
    inputNum(&m, length2);
    pstr1 = (char **) realloc(pstr1, length1 + m);
    printf("input pos of insert\n");
    inputNum(&k, length1);
    for (int i = 0; i < m; i++)
        move(pstr1, length1 + m, k);
    for (int i = 0; i < m; i++)
        *(*pstr1 + i + k) = *(*pstr2 + i);
    printString(pstr1);
}