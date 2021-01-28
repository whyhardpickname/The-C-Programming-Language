#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include "calcu.h"

/* 获取下一个操作数或运算符 */
int getop(char s[])
{
    static int lastc = 0;
    int c; /* 接受字符 */
    int i; /* 字符数组下标 */
    /* 跳过空格并接受第一个字符*/

    if (lastc == 0)
    {
        c = getch();
    }
    else
    {
        c = lastc;
        lastc = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t')
    {
        c = getch();
    }
    /* 提前放置终止符,如果是操作符 */
    s[1] = '\0';

    /* 处理大写字母变量 */
    if (isupper(c))
    {
        return c;
    }
    /* 处理数学库函数 */
    i = 0;
    if (islower(c))
    {
        while(islower(s[++i] = c = getch()))
        {
        }
        s[i] = '\0';
        /* 回退换行符 */
        if (c != EOF)
        {
            lastc = c;
        }
        return NAME;
    }

    /* 处理操作符情况 */
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    /* 处理负号部分 */
    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
        {
            s[++i] = c;
        }
        else
        {
            if (c != EOF)
            {
                lastc = c;
                return '-';
            }
        }
    }

    /* 处理整数部分 */
    if (isdigit(c))
    {
        /* ++i因为一开始已经接受了一个字符 */
        while (isdigit(s[++i] = c = getch()))
        {
        }
    }
    /* 处理小数部分 */
    if (c == '.')
    {
        while(isdigit(s[++i] = c = getch()))
        {
        }
    }
    s[i] = '\0';
    /* 由于整数需要额外一个字符确定是否完整,因此确定完之后要将字符用于下次判断 */
    if (c != EOF)
    {
        lastc = c;
    }
    return NUMBER;
}
    
/* 将整个字符串压回输入中 */
/* 逆序压回,因为先进先出 */
void ungets(char s[])
{
    int len = strlen(s);
    while (len > 0)
    {
        ungetch(s[--len]);
    }
}