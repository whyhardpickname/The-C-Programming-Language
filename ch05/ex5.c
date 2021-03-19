#include <stdio.h>

char *strcopy(char *s, const char *ct, size_t n);
char *strcatenate(char *s, const char *ct, size_t n);
int strcompare(const char *cs, const char *ct, size_t n);

int main()
{
    int size = 100;
    char s[size];
    const char *cs = "def";
    const char *ct = "de";
    int n;
    int chars = 5;

    for (n = 0; n < chars; n++) {
        s[0] = 'a';
        s[1] = 'b';
        s[2] = 'c';
        printf("strcopy(%s, %s, %d) = ", s, ct, n);
        printf("%s\n", strcopy(s, ct, n));
    }

    for (n = 0; n < chars; n++) {
        s[0] = 'a';
        s[1] = 'b';
        s[2] = 'c';
        s[3] = '\0';
        s[4] = '\0';
        printf("strcatenate(%s, %s, %d) = ", s, ct, n);
        printf("%s\n", strcatenate(s, ct, n));
    }

    for (n = 0; n < chars; n++) {
        printf("strcompare(%s, %s, %d) = ", cs, ct, n);
        printf("%d\n", strcompare(cs, ct, n));
    }
}

/* 将字符串ct最多n个字符复制到字符串s中，并返回s。如果ct不足n个字符，用‘\\0’补充。 */
char *strcopy(char *s, const char *ct, size_t n)
{
    char *bs = s;
    while (n-- > 0 && (*s++ = *ct++)) {
        ;
    }
    return bs;
}

/* 将字符串ct最多n个字符复制到字符串s的尾部，并以'\\0'结尾;该函数返回s。*/
char *strcatenate(char *s, const char *ct, size_t n)
{
    char *bs = s;
    
    while (*s) {
        s++;
    }
    
    while (n-- > 0 && (*s++ = *ct++)) {
        ;
    }
    return bs;
}

/* 将字符串cs的至多前n个字符与ct比较。当cs > ct，返回一个正数;当cs = ct，返回0;
    当cs < ct，返回一个负数。 */
int strcompare(const char *cs, const char *ct, size_t n)
{
    /* TODO 测试全错，需要修改代码。 */
    int i;
    for (i = 0; *cs && *ct && *cs == *ct && i < n; cs++, ct++) {
        ;
    }
    return *cs - *ct;
}