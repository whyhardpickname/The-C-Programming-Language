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

    for (i = 0; i < size && getfloat(&a[i]) != EOF; i++)
    {
    }

    for (i = 0; i < size; i++)
    {
        printf("%.2f ", a[i]);
    }
    printf("\n");
    return 0;
}

int getfloat(double *pf)
{
    int c;
    int sign;
    int pow;

    /* 跳过空格 */
    while (isspace(c = getch()));

    /* 不是数字 */
    if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
    {
        c = getch();
    }

    for (*pf = 0.0; isdigit(c); c = getch())
    {
        *pf = *pf * 10 + (c - '0');
    }
   
    if (c == '.')
    {
        c = getch();
        pow = 1;
        for (; isdigit(c); c = getch())
        {
            *pf = *pf * 10 + (c - '0');
            pow *= 10;
        }
        *pf /= pow;
    }
    *pf *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}