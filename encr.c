#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char upper_key[30];
    char lower_key[30];

    int i, j;

    char upcase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowcase[26];

    char plain[100];

    strlwr(strcpy(lowcase, upcase));
    do{
        printf("Enter 26 character key:\n");
        gets(upper_key);
    }
    while (strlen(upper_key) != 26);
    
    strlwr(strcpy(lower_key, upper_key));
    strupr(upper_key);
    
    for (i = 0 ; i < 26 ; i++)
    {
        for (j = i + 1 ; j < 26 ; j++)
        {
            if (upper_key[i] == upper_key[j])
            {
                printf("Enter valid key.\n");
                return 1 ;
            }

        }
        if (upper_key[i]<'A' || upper_key[i]>'Z')
        {
                printf("Enter valid key.\n");
                return 1 ;
        }
    }
    printf("Enter plaintext: ");
    gets(plain);

    for (int i = 0 ; i < strlen(plain) ; i++)
    {
        for (int j = 0 ; j < 26 ; j++)
        {
            if (plain[i] == upcase[j])
            {
                plain[i] = upper_key[j] ;
                break;
            }
            if (plain[i] == lowcase[j])
            {
                plain[i] = lower_key[j] ;
                break;
            }
            
        }
    }

    printf("ciphertext: %s\n", plain);
    return 0;
}
