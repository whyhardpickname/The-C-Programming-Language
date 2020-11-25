#include <stdio.h>

#define MAXLINE 1000
#define LOWER 7

int getline(char s[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;//current line's length

    char line[MAXLINE];//currtent line
    
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > LOWER)
        {
            printf("%d %s", len, line);
        }
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