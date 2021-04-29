#include <stdio.h>
#include <string.h>

void strcopy(char *s, char *t, int n);
void strcatenate(char *s, char *t, int n);
int strcompare(char *s, char *t, int n);

int main()
{
    char s[6] = {'a', 'b', 'c'};
    char *t = "ac";
    printf("%d\n", strcompare(s, t, 1));
    printf("%d\n", strcompare(s, t, 2));


}

/* 将字符串ct最多n个字符复制到字符串s中，并返回s。如果ct不足n个字符，用‘\0’补充。 */
void strcopy(char *s, char *t, int n){
    while (*t && n-- > 0) {
        *s++ = *t++;
    }
    while (n-- > 0) {
        *s++ = '\0';
    }
}

/* 将字符串ct最多n个字符复制到字符串s的尾部，并以'\0'结尾;该函数返回s。*/
void strcatenate(char *s, char *t, int n) {
    strcopy(s + strlen(s), t, n);
}

/* 将字符串cs的至多前n个字符与ct比较。当cs > ct，返回一个正数;当cs = ct，返回0;
    当cs < ct，返回一个负数。 */
int strcompare(char *s, char *t, int n){
    for (; *s == *t; s++, t++){
        if (!(*s) || --n <= 0){ 
            return 0;
        }
    }
    return *s - *t;
}