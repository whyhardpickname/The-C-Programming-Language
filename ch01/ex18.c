#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;//current line's length

    char line[MAXLINE];//currtent line
    
    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("%d %s", len, line);
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c;
    int i, j;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    j = i - 1;
    while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
    {
        j--;
    }
    s[++j] = '\n';
    s[++j] = '\0';

    return j;
}