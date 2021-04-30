#include <stdio.h>
#include <string.h>
#define MAXLINE 100 /* 每个输入行的最大长度 */
#define MAXSTORE 1000 /* 可用空间大小 */

int readLines(char *linePtr[], int maxLines);
int readLine(char *str, int limit);
// char *alloc(int);

/* 读取输入行 */
int readLines(char *linePtr[], int maxLines) {
    extern char lineStore[];
    char *p = lineStore; /* 指向下一个空闲位置的指针 */
    char *storeStop = lineStore + MAXSTORE;
    int len; /* 输入行的长度 */
    int nlines; /* 输入行行数 */
    // char *p;
    char line[MAXLINE];
    // char **p = linePtr;
    nlines = 0;
    while ((len = readLine(line, MAXLINE)) > 0) {
        //使用alloc
        /* 
        if (nlines >= maxLines || (p = alloc(len)) == NULL) {
            return -1;
        }
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            linePtr[nlines++] = p;
        } 
        */

       //使用本地存储
       if (nlines >= maxLines || p + len > storeStop) {
           return -1;
       }
       else {
           line[len - 1] = '\0';
           strcpy(p, line);
           linePtr[nlines++] = p;
           p += len;
       }
    }
    return nlines;
    // while (maxLines-- > 0 && readLine(*p, MAXLINE) != 0) {
    //     p++;
    // }
    // return p - linePtr;
}

int readLine(char *str, int limit) {
    int c;
    char *begin = str;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n') { //这里'\n'写错成'\0'.导致直到eof都算一行，所以还需要多一个eof
        *str++ = c;
    }
    if (c == '\n') {
        *str++ = c;
    }
    *str = '\0';
    return str - begin;
}