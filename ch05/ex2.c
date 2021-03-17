#include<stdio.h>
#include<ctype.h>

int getch(void);
int ungetch(char c);
int getfloat(double *pf);

int main()
{
    int size = 3;
    int i;
    double a[size];

    for (i = 0; i < size; i++) {
        a[i] = -1;
    }

    for (i = 0; i < size && getfloat(&a[i]) != EOF; i++) {
        ;
    }

    for (i = 0; i < size; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
    return 0;
}

int getfloat(double *pf)
{
    int c;
    int sign;
    double pow;
    int temp;

    /* 跳过空格 */
    while (isspace(c = getch())) {
        ;
    }

    /* 不是数字 */
    if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') {
        temp = c;
        if (!isdigit(c = getch())) {
            if (c != EOF) {
                ungetch(c);
            }
            ungetch(temp);
            return c;
        }
    }

    for (*pf = 0.0; isdigit(c); c = getch())
    {
        *pf = *pf * 10 + (c - '0');
    }
   
    if (c == '.') {
        c = getch();
    }
    
    for (pow = 1.0; isdigit(c); c = getch())
    {
        *pf = *pf * 10.0 + (c - '0');
        pow *= 10.0;
    }    
    *pf *= sign / pow;

    if (c != EOF) {
        ungetch(c);
    }
    return c;
}