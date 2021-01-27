#include <stdio.h>
#include "calcu.h"

#define BUFSIZE 1

char buf = 0;

/* 从缓冲区获取一个字符 */
int getch(void)
{
    int c;
    if (buf != 0)
    {
        c = buf;
        buf = 0;
    }
    else
    {
        c = getchar();
    }
    return c;
}

/* 把字符压入缓冲区 */
void ungetch(char c)
{
    /* 检查缓冲区空闲空间 */
    if (buf == 0)
    {
        buf = c;
    }
    else
    {
        printf("%s", "The buffer space is full.\n");
    }
}