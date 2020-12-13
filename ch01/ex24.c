#include<stdio.h>

char* check_pair(int c);
int pair(int c);

int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        check_pair(c);
    }
    putchar('\n');
    return 0;
}

int pair(int c)
{
    if (c == '\'')
    {
        return '\'';
    }
    else if (c == '"')
    {
        return '"';
    }
    else if (c == '(')
    {
        return ')';
    }
    else if (c == '[')
    {
        return ']';
    }
    else if (c == '{')
    {
        return '}';
    }
    return ' ';
}

char* check_pair(int c)
{
    char *s;

    if (c == '\'')
    {
        int d;
        d = getchar();
        if (d == '\\')
        {
            d = getchar();
        }
        d = getchar();
        if (d != '\'')
        {
            sprintf(s, "expected: %c", pair(c));
        }
    }
    else
    {
        int d;

        d = getchar();
        while (d != pair(c) && d != ';')
        {
            d = getchar();
        }

        if (d == ';')
        {
            sprintf(s, "expected: %c", pair(c));
        }
    }
    return s;
}