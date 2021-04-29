#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char *s = "abcdef";
    char *t = "def";
    printf("%d\n", strend(s, t));
}

/* 如果字符串t出现在字符串s的尾部，返回1。否则返回0。*/
int strend(char *s, char *t)
{
    char *bs = s; /* 字符串s的开头 */
    char *bt = t; /* 字符串t的开头 */

    while (*s) {
        s++;
    }

    while (*t) {
        t++;
    }

    for (; *s == *t; s--, t--) { 
        if (s == bs || t == bt) { /* 保证指针不越界 */
            break;
        }
    }

    if (*s == *t && t == bt && *s != '\0')
    {
        return 1;
    }
    return 0;
}