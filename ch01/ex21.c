#include<stdio.h>

#define BLANKS 8

int main()
{
    int c;
    int tabs;
    int blanks;
    int count = 0;

    printf("1234567812345678\n");
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            count++;
        }
        else
        {
            tabs = count / BLANKS;
            blanks = count % BLANKS;
            for (int i = 0; i < tabs; i++)
            {
                putchar('\t');
            }
            for (int i = 0; i < blanks; i++)
            {
                putchar(' ');
            }
            count = 0;
            putchar(c);
        }
    }
    printf("\n");
    return 0;
}