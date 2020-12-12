#include<stdio.h>

int main()
{
    int cur;
    int last = ' ';

    while ((cur = getchar()) != EOF)
    {
        if (cur == '"')
        {
            putchar(cur);
            last = cur;
            while ((cur = getchar()) != last)
            {
                putchar(cur);
            }
            putchar(cur);
        }
        else if (cur == '/')
        {
            last = cur;
            if ((cur = getchar()) != '*')
            {
                putchar(last);
                putchar(cur);
            }
            else
            {
                last = ' ';
                while (last != '*' || (cur = getchar()) != '/')
                {
                    last = cur;
                }
            }
        }
        else
        {
            putchar(cur);
        }
    }
    putchar('\n');
    return 0;
}