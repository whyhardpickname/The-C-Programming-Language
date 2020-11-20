#include<stdio.h>

int main(int args, char *argv[])
{
    int c, spaces, tabs, newlines;

    spaces = 0;
    tabs = 0;
    newlines = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            spaces++;
        }

        if (c == '\t')
        {
            tabs++;
        }

        if (c == '\n')
        {
            newlines++;
        }
    }

    printf("%d\t%d\t%d", spaces, tabs, newlines);
    return 0;
}