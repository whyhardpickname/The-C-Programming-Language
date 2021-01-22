/* TODO 测试 */

#include<stdio.h>
#include<ctype.h>

#define NUMBER '0'     /* 标识找到一个数 */

int getch(void); /* 从缓冲区获取一个字符 */
void ungetch(int); /* 将当前字符退回缓冲区 */

/* 
    获取下一个操作数或运算符 
*/
int getop(char s[])
{
    int c; /* 接受字符 */
    int i; /* 字符数组下标 */
    /* 跳过空格并接受第一个字符*/
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
    }
    /* 提前放置终止符,如果是操作符 */
    s[1] = '\0';
    /* 处理操作符情况 */
    if (!isdigit(c) && c != '.')
    {
        return c;
    }
    /* 处理整数部分 */
    i = 0;
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
        ungetch(c);
    }
    return NUMBER;
}