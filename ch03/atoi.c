#include<stdio.h>
#include<ctype.h>

int atoi(char s[]);

int main()
{
    
    return 0;
}

/*
    遇到空白符跳过
    遇到符号,读取符号,-1表示'-'
    遇到数字,执行转换.
*/
int atoi(char s[])
{
    int i;
    int sign;
    int n;

    for (i = 0; isspace(s[i]); i++)
    {
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '-' || s[i] == '+')
    {
        i++;
    }

    for (n = 0; isdigit(s[i]); i++)
    {
        n = n * 10 + s[i] - '0';
    }
    return sign * n;
}