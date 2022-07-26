#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char str[100], substr1[100], substr2[100];

void input()
{
    printf("\nEnter the string: ");
    scanf("%[^\n]", str);
    printf("\nEnter the sub string to be found & replaced: ");
    scanf(" %[^\n]", substr1);
    printf("\nEnter the new sub string : ");
    scanf(" %[^\n]", substr2);
}

int ispresent()
{
    int i, j, k;
    char temp[20];
    int result = -1;
    int a = strlen(str);
    int b = strlen(substr1);
    for (i = 0; i <= a - b; i++)
    {
        for (j = i, k = 0; j < b + i; j++, k++)
        {
            temp[k] = str[j];
        }
        temp[k] = '\0';
        if (strcmp(temp, substr1) == 0)
        {
            result = i;
            break;
        }
    }
    return result;
}

void replace(int index)
{
    int i, j;
    for (i = index, j = 0; substr2[j] != '\0'; i++, j++)
    {
        str[i] = substr2[j];
    }
}

int main()
{
    input();
    int ispreval=-1;
    if (strlen(substr1) != strlen(substr2)) {
        printf("Length of substring to be found and to be replaced with needs to be same.\n");
        return 0;
    }
    ispreval=ispresent();
    if(ispreval==-1)
        printf("\nSubstring not present.");
    else
    {
        replace(ispreval);
        printf("\nThe new string is %s ", str);
    }

}