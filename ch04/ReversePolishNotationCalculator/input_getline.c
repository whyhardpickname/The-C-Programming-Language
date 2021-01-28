#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include "calcu.h"

#define MAXLINE 100

int getLine(char s[], int maxline);
char line[MAXLINE];
int j = 0;

/* 获取下一个操作数或运算符 */
int getop(char s[])
{
    int c; /* 接受字符 */
    int i; /* 字符数组下标 */
    /* 跳过空格并接受第一个字符*/

    if (line[j] == '\0')
    {
        if (getLine(line, MAXLINE) == 0)
        {
            return EOF;
        }
        else
        {
            j = 0;
        }
    }

    while ((s[0] = c = line[j++]) == ' ' || c == '\t')
    {
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
        while(islower(s[++i] = c = line[j++]))
        {
        }
        s[i] = '\0';
        /* 回退换行符 */
        if (c != EOF)
        {
            j--;
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
        if (isdigit(c = line[j++]) || c == '.')
        {
            s[++i] = c;
        }
        else
        {
            if (c != EOF)
            {
                j--;
                return '-';
            }
        }
    }

    /* 处理整数部分 */
    if (isdigit(c))
    {
        /* ++i因为一开始已经接受了一个字符 */
        while (isdigit(s[++i] = c = line[j++]))
        {
        }
    }
    /* 处理小数部分 */
    if (c == '.')
    {
        while(isdigit(s[++i] = c = line[j++]))
        {
        }
    }
    s[i] = '\0';
    /* 由于整数需要额外一个字符确定是否完整,因此确定完之后要将字符用于下次判断 */
    if (c != EOF)
    {
        j--;
    }
    return NUMBER;
}

int getLine(char s[], int maxline)
{
    int i;
    int c;
    
    i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < maxline - 1)
    {
        s[i++] = c;
    }

    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';

    return i;
}