#include<stdio.h>

#define MAX 10 //字符上限

int main()
{
    char line[MAX + 1];
    int c;
    int i = 0;

    while (i < MAX && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';

    i--;
    while (i >= 0)
    {
        printf("%c", line[i--]);
    }
    return 0;
}