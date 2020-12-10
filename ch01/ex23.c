#include<stdio.h>

/* "comment */
#define TEST "/* string */" /* "comment" */ 
#define LEN 4

int main()
{
    int double_quote = '"';
    int single_quote = '\'';
    int slash = '/';
    int star = '*';
    int c = ' ';
    char stack[LEN];
    int count;
    while ((c = getchar()) != EOF)
    {
        if (count == 0)
        {
            if (c == '"' || c == '\'')
            {
                stack[count++] = c;
                putchar(c);
            }
            else if (c == '/')
            {
                stack[count++] = c;
            }
        }
        else
        {
            if (stack[0] == '"' || stack[0] == '\'')
            {
                count = 0;
                putchar(c);
            }
        }
    }
    putchar('\n');
    return 0;
}