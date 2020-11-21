#include <stdio.h>

#define IN 1
#define OUT 0
int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            printf("\n");
        }
        else
        {
            state = IN;
            printf("%c", c);
        }
    }
    return 0;
}
