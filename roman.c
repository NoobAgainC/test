#include<stdio.h>
#include <math.h>
#include<string.h>

struct roman_num
{
    long num;
    int sym;
} roman[] = {0, ' ',
            1, 'i',
            5, 'v',
            10, 'x',
            50, 'l',
            100, 'c',
            500, 'd',
            1000, 'm',
            5000, 'V',
            10000, 'X',
            50000, 'L',
            100000, 'C',
            500000, 'D',
            1000000, 'M'
            };

char represent[100];

void find_roman(long a, int dig);

char get_roman(long a);

void assign_roman(long lb, long ub, long a);

int main(void)
{
    long in = 0;
    int count = 0;
    printf("Enter a digit to convert to Roman Number: ");
    scanf("%ld", &in);
    
    while (in != 0)
    {
        find_roman(in % 10, count);
        in /= 10;
        count++;
    }
    printf("Roman equivalent of Given digit is: %s\n", represent);
    return 0;
}

char get_roman(long a)
{
    int i = 0;
    while (i < 14)
    {
        if (roman[i].num == a) return roman[i].sym;
        i++;
    }
}


void find_roman(long a, int dig)
{
    long ub = round(pow(10, (dig + 1))), lb = round(pow(10, dig));
    a *= lb;
    float per = (a * 100)/ ub;

    if (per < 40) assign_roman(lb, 0, a);

    else if (per < 90) assign_roman(lb, ub/2, a);
    
    else assign_roman(lb, ub, a);
}

void assign_roman(long lb, long ub, long a)
{
    char temp[100];
    
    strcpy(temp, represent);

    if (a == 0) ;

    else if(a == ub)
    {
        represent[0] = get_roman(ub);
        represent[1] = '\0';
    }

    else if(a < ub)
    {
        represent[0] = get_roman(lb);
        represent[1] = get_roman(ub);
        represent[2] = '\0';
    }
    else
    {
        int i = 0, j = 0;
        if (ub != 0) represent[j++] = get_roman(ub); 
        
        for (i = 0; i < (a / lb) - (ub / lb); i++)
        {
            represent[j + i] = get_roman(lb);
        }
        represent[j + i] = '\0';
    }

    strcat(represent, temp);
}
