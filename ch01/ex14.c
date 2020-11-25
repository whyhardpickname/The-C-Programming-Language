#include<stdio.h>
#include<ctype.h>

#define MAXHIST 15
#define MXACHARS 128

int main()
{
    int chars_count[MXACHARS];
    int i;
    int c;
    int maxvalue;
    int len;

    for (i = 0; i < MXACHARS; i++)
    {
        chars_count[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c < MXACHARS)
        {
            chars_count[c]++;
        }
    }

    maxvalue = 0;
    for (i = 0; i < MXACHARS; i++)
    {
        if (chars_count[i] > maxvalue)
        {
            maxvalue = chars_count[i];
        }
    }

    for (i = 0; i < MXACHARS; i++)
    {
        if (isprint(i))
        {
            printf("%5d - %c - %5d|", i, i, chars_count[i]);
        }
        else
        {
            printf("%5d -   - %5d|", i, chars_count[i]);
        }

        len = MAXHIST * chars_count[i] / maxvalue;

        while (len > 0)
        {
            printf("*");
            len--;
        }
        printf("\n");
    }
        return 0;
}
