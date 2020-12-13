#include<stdio.h>
/*abc*/
/*"abc"*/
char *s = "/*abc*/";
void rcomment(int c);/*abc*/
void in_comment(void);//abc
void in_double_slash_comment(void);
void echo_quote(int c);
//abc
int main()
{
    int c;
    
    while ((c = getchar()) != EOF)
    {
        rcomment(c);
    }
    return 0;
}

void rcomment(int c)
{
    int d;
    
    if (c == '/')
    {
        if ((d = getchar()) == '*')
        {
            in_comment();
        }
        else if (d == '/')
        {
            in_double_slash_comment();
        }
        else
        {
            putchar(c);
            putchar(d);
        }
    }
    else if (c == '\'' || c == '"')
    {
        echo_quote(c);
    }
    else
    {
        putchar(c);
    }
}
void in_comment(void)
{
    int c;
    int d;

    c = getchar();
    d = getchar();

    while (c != '*' || d != '/')
    {
        c = d;
        d = getchar();
    }
}

void echo_quote(int c)
{
    int d;

    putchar(c);

    while ((d = getchar()) != c)
    {
        putchar(d);
        if (d == '\\')
        {
            putchar(getchar());
        }
    }
    putchar(d);
}

void in_double_slash_comment(void)
{
    int c;

    while ((c = getchar()) != '\n')
    {
    }
    putchar(c);
}