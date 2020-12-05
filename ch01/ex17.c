#include <stdio.h>

#define MAXLINE 1000
#define LOWER 4

int getLine(char s[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;//current line's length

    char line[MAXLINE];//currtent line
    
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > LOWER)
        {
            printf("%d %s", len, line);
        }
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