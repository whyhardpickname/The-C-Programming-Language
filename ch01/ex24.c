#include<stdio.h>

int parentheses = 0;
int brackets = 0;
int braces = 0;
void in_comment();
void echo_quote(int c);
void search(int c);

int main()
{
    int c;
    extern int parentheses;
    extern int brackets;
    extern int braces;
    while ((c = getchar()) != EOF) 
    {
        int d;
        if (c == '/')
        {
            if ((c = getchar()) == '*')
            {
                in_comment();
            }
            else
            {
                search(c);
            }
        }
        else if (c == '"' || c == '\'')
        {
            echo_quote(c);
        }
        else
        {
            search(c);
        }
        
        if (parentheses < 0)
        {
            printf("parentheses aren't match.");
            parentheses = 0;
            }
            else if (brackets < 0)
            {
            printf("brackets aren't match");
            brackets = 0;
            }
            else if (braces < 0)
            {
            printf("braces aren't match");
            braces = 0;
        }
    }

    if (parentheses > 0)
    {
        printf("parentheses aren't match.");
    }
    else if (brackets > 0)
    {
        printf("brackets aren't match");
    }
    else if (braces > 0)
    {
        printf("braces aren't match");
    }

    putchar('\n');
    return 0;
}

void in_comment(int c)
{
    int d = getchar();
    int e = getchar();

    while (d != '*' && e != '/')
    {
        d = e;
        e = getchar();
    }
}

void echo_quote(int c)
{
    int d;
    while ((d = getchar()) != c)
    {
        if (d == '\\')
        {
            getchar();
        }
    }
}

void search(int c)
{
    extern int parentheses;
    extern int brackets;
    extern int braces;
    if (c == '(')
    {
        parentheses++;
    }
    else if (c == '[')
    {
        brackets++;
    }
    else if (c == '{')
    {
        braces++;
    }
    else if (c == ')')
    {
        parentheses--;
    }
    else if (c == ']')
    {
        brackets--;
    }
    else if (c == '}')
    {
        braces--;
    }
}