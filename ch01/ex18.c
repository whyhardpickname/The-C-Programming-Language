#include <stdio.h>

#define MAXLINE 1000

int trim(char s[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;//current line's length

    char line[MAXLINE];//currtent line
    
    while ((len = trim(line, MAXLINE)) > 0)
    {
        printf("%d %s", len, line);
    }

    return 0;
}

int trim(char s[], int lim)
{
    int c;
    int i;
    int j = 0;

    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }

    s[i++] = '\n';
    s[i] = '\0';

    j = i - 2;
    while (s[j] == ' ' || s[j] == '\t')
    {
        j--;
    }
    s[++j] = '\n';
    s[++j] = '\0';

    return j - 1;
}