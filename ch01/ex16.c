#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;//current line's length
    int max;//specified line

    char line[MAXLINE];//currtent line
    char longest[MAXLINE];// longest line
    
    max = 0;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("%d %s",len, line);
        if (len > max)
        {
            max = len;
        }
        copy(longest, line);
    }
    
    if (max > 0)
    {
        printf("%d %s", amax, longest);
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c;
    int i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}