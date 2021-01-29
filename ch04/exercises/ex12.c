#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char s[]);

int main()
{
    char s[100];
    itoa(-2147483647-1, s);
    printf("%s\n", s);
    return 0;
}

/* 递归版: 整数转为字符串 */
void itoa(int n, char s[])
{
    static int i;

    if (n / 10)
    {
        itoa(n / 10, s);
    }
    else
    {
        i = 0;
        s[i++] = '-';
    }
    s[i++] = abs(n % 10) + '0';
    s[i] = '\0';
}