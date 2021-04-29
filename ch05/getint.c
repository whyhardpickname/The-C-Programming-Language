#include<stdio.h>
#include<ctype.h>

int getch(void);
int ungetch(char c);

int getint(int *pn)
{
    int c;
    int sign;
    int temp;

    while (isspace(c = getch())) { /* 跳过空白符 */
        ;
    }

    /* 不是数字 */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    /* 正负号 */
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        temp = c;
        if (!isdigit(c = getch())) {
            if (c != EOF) {
                ungetch(c);
            }
            ungetch(temp);
            return temp;
        }
    }

    /* 数字 */
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + (c - '0');
    }
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }
    return c;
}



int main()
{
    int size = 3;
    int i;
    int a[size];

    for (i = 0; i < size; i++) {
        a[i] = -1;
    }

    int result = getint(&a[0]); //使用result防止a[0]先于getint计算之前
    printf("%c %d\n", result, a[0]); //正常数字
    return 0;
}