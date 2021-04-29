#include <stdio.h>
#include <ctype.h>

int getLine(char *s, int limit);
int atoi(char *s);

int main() {
    char *s = "-123";
    printf("%d\n", atoi(s));
}

/* getLine 读取一行输入到s，并返回该行字符长度。*/
int getLine(char *s, int limit) {
    int c;
    char *bs = s;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return s - bs;
}

/* atoi 将字符串转换成整数 */
int atoi(char *s) {
    int sigh;
    int i;
    while (isspace(*s)) {
        s++;
    }

    if (!isdigit(*s) && *s != EOF && *s != '-' && *s != '+') {
        return 0;
    }

    sigh = (*s == '-') ? -1 : 1;

    if (*s == '-' || *s == '+') {
        if (!isdigit(*(s + 1))) {
            return *s;
        }
        s++;
    }

    for (i = 0; isdigit(*s); s++) {
        i = i * 10 + (*s - '0');
    }
    i *= sigh;
    if (*s != EOF) {
        s--;
    }
    return i;
}