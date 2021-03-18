#include <stdio.h>

void strcat_p(char *s, char *t);

int main()
{
    int size = 100;
    char s[size];
    s[0] = 'a';
    s[1] = 'b';
    s[2] = 'c';
    s[3] = '\0';
    char t[] = "efg";

    strcat_p(s, t);
    printf("%s\n", s);
    return 0;
}

/* strcat(s,t):将t指向的字符串连接到字符串s的尾部*/
void strcat_p(char *s, char *t)
{
    while (*s) {
        s++;
    }
    while ((*s++ = *t++)) {
        ;
    }
}