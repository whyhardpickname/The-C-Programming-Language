#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;//current line's length
    int max;//specified line

    char line[MAXLINE];//currtent line
    char longest[MAXLINE];// longest line
    
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("%d %s", max, longest);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c;
    int i;
    int j = 0;

    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
        j++;
    }
    s[j++] = '\n';
    s[j] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}