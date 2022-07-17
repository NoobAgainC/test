#include<stdio.h>
#include<ctype.h>

int main()
{
    int c, i = 0, j = 0;
    int al[26];

    while (i < 26) al[i++] = 0;
   
    printf("Enter a string to get the histogram of frequency of characters in it:\n");

    while ((c = getchar()) != '\n')
    {
        c = toupper(c);
        if(c > 64 && c < 91) al[c - 65] += 1;
    }
    i = 0;
    while (i < 26)
        if(j < al[i++]) j = al[i - 1];
    i = 0;

    while (j != 0) {
        printf("\t\t\t\t");
        while (i < 26) {
            if(al[i++] >= j) putchar(254u);
            else putchar(32);
            putchar(32);
        }
        i = 0;
        putchar('\n');
        j--;
    }
    printf("\t\t\t\t");
    while (i < 51)
    {
        
        putchar('_');
        i++;
    }
    printf("\n\t\t\t\t");
    i = -1;
    while (i++ < 51)
    {
        if(i % 2 == 0) putchar(65 + (i / 2));
        else putchar(32);
    }

    
    
}