#include<stdio.h>

#define BLANKS 8

int main()
{
    int c;
    int blanks;
    int count = 0;

    printf("1234567812345678\n");
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            blanks = BLANKS - count % BLANKS;
            while(blanks > 0)
            {
                putchar(' ');
                blanks--;
            }
            count = 0;
        }
        else if (c == '\n')
        {
            putchar(c);
            count = 0;
        }
        else
        {
            putchar(c);
            count++;
        }
    }
    printf("\n");
    return 0;
}