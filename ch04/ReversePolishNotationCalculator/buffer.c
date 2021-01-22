/* TODO 测试 */

#include<stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* 缓冲区 */
int bufp = 0; /* 缓冲区下一个空闲位置 */

/* 从缓冲区获取一个字符 */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();

}

/* 把字符压入缓冲区 */
void ungetch(char c)
{
    /* 检查缓冲区空闲空间 */
    if (bufp < BUFSIZE)
    {
        buf[bufp++] = c;
    }
    else
    {
        printf("%s", "The buffer space is full.\n");
    }
}