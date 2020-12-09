#include<stdio.h>

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];

int exptba(int pos);
int findblank(int pos);
int newpos(int pos);
void printl(int pos);

int main()
{
    int c;
    int pos;

    printf("0123456789\n");
    while((c = getchar()) != EOF)
    {
        line[pos] = c;
        if (c == '\t')
        {
            pos = exptba(pos);
        }
        else if (c == '\n')
        {
            printl(pos);
            pos = 0;
        }
        else if (++pos >= MAXCOL)
        {
            pos = findblank(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
    return 0;
}

int exptba(int pos)
{
    line[pos] = ' ';
    for (++pos; pos < MAXCOL && pos % TABINC != 0; pos++)
    {
        line[pos] = ' ';
    }

    if (pos < MAXCOL)
    {
        return pos;
    }
    printl(pos);
    return 0;
}

int findblank(int pos)
{
    while (pos >= 0 && line[pos] != ' ')
    {
        --pos;
    }

    if (pos == 0)
    {
        return MAXCOL;
    }
    return pos + 1;
}

int newpos(int pos)
{
    int i;
    int j;

    if (pos <= 0 || pos >= MAXCOL)
    {
        return 0;
    }
    else
    {
        i = 0;
        for (j = pos; j < MAXCOL; j++)
        {
            line[i++] = line[j];
        }
        return i;
    }
}
void printl(int pos)
{
    int i;
    for (i = 0; i < pos; i++)
    {
        putchar(line[i]);
    }

    if (pos > 0)
    {
        putchar('\n');
    }
}