#include<stdio.h>
#include<ctype.h>

double atof(char s[]);

int main()
{
    printf("%f %s\n", atof("1.23"), "atof(\"1.23\")");
    printf("%f %s\n", atof("-1.23"), "atof(\"1.23\")");
    return 0;
}

/* 
    将表示数字的字符s转换成双精度浮点数.

    思路:去掉小数点,将整体作为整数利用atoi处理,
    此时得到的值是原数10的n幂次倍,n是小数位数.
    再除以10的n幂次,n是小数位,得到所求值.

*/
double atof(char s[])
{
    double val;
    int i;
    int power;
    int sign;

    /* 处理可选负号 */
    i = 0;
    sign = (s[i] == '-') ? -1 : 1;
    /* 跳过负号,如果有 */
    if (s[i] == '-' || s[i] == '+')
    {
        i++;
    }
    /* 处理整数部分 */
    for (; isdigit(s[i]); i++)
    {
        val = 10.0 * val + s[i] - '0';
    }
    /* 处理小数点 */
    if (s[i] == '.')
    {
        i++;
    }
    /* 小数点后每多一位,10的幂次加1*/
    power = 1;
    for (;isdigit(s[i]); i++)
    {
        val = 10.0 * val + s[i] - '0';
        power *= 10;
    }
    return sign * val / power;
}