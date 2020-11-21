#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, nc, nw, nl, state;

    nc = nw = nl = 0;
    state = OUT;

    while ((c = getchar()) != EOF)
    {
        nc++;
        if (c == '\n')
        {
            nl++;
        }

        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }

    printf("%d\t%d\t%d", nc, nw, nl);
    return 0;
}
