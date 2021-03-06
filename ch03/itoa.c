#include<stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int n = -123456;
    int len = 100;
    char s[len];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

/* 将数字转为字符串 */
void itoa(int n, char s[])
{
    char c;
    int i;
    int sign = n;

    if ((sign = n) < 0)
    {
        n = -n;
    }
    //转换数字

    i = 0;
    do 
    {
        c = (n % 10) + '0';
        s[i++] = c;
    } 
    while ((n /= 10) > 0);

    //处理正负号
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

/* 反转字符串 */
void reverse(char s[])
{
    int i;
    int j;
    char temp;

    for (j = 0; s[j] != '\0'; j++)
    {
    }

    for (i = 0, j--; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}