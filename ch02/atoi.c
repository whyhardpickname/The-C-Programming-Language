#include<stdio.h>

int atoi(char s[]);

int main()
{
    char s[2] = {'4', '9'};
    printf("%d", atoi(s));
    return 0;
}

int atoi(char s[])
{
    int n;
    int i;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}