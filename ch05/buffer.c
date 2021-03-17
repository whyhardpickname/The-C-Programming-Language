#include <stdio.h>

#define BUFSIZE 100

static int buf[BUFSIZE]; /* 缓冲区 使用int防止char转换成int时不是-1*/
static int bufp = 0; /* 缓冲区下一个空闲位置 */

/* 从缓冲区获取一个字符 */
int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* 把字符压入缓冲区 */
void ungetch(char c) 
{
    if (bufp < BUFSIZE) { /* 检查缓冲区空闲空间 */
        buf[bufp++] = c;
    }
    else {
        printf("%s", "The buffer space is full.\n");
    }
}