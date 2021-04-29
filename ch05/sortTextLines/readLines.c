#include "headfiles.h"
#include<string.h>

#define MAXLINE 100 /* 每个输入行的最大长度 */

int readLines(char *linePtr[], int maxLines);
int readLine(char *str, int limit);
char *alloc(int);

/* 读取输入行 */
int readLines(char *linePtr[], int maxLines) {
    int len; /* 输入行的长度 */
    int nlines; /* 输入行行数 */
    char *p;
    char line[MAXLINE];
    // char **p = linePtr;
    nlines = 0;
    while ((len = readLine(line, MAXLINE)) > 0) {
        if (nlines >= maxLines || (p = alloc(len)) == NULL) {
            return -1;
        }
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            linePtr[nlines++] = p;
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
    while (--limit > 0 && (c = getchar()) != EOF && c != '\0') {
        *str++ = c;
    }
    if (c == '\n') {
        *str++ = c;
    }
    *str = '\0';
    return str - begin;
}