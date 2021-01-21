#include<stdio.h>
#include<ctype.h>

double atof(char s[]);

int main()
{
    /* 有效数和指数按正负有四种要测试 */
    /* 正正 */
    printf("%s %f\n", "atof(\"123.456e2\")", atof("123.456e2"));
    /* 正负 */
    printf("%s %f\n", "atof(\"123.456e-2\")", atof("123.456e-2"));
    /* 负正 */
    printf("%s %f\n", "atof(\"-123.456e2\")", atof("-123.456e2"));
    /* 负负 */
    printf("%s %f\n", "atof(\"-123.456e-2\")", atof("-123.456e-2"));
    return 0;
}

/* 
    将表示数字的字符s转换成双精度浮点数.

    思路:去掉小数点,将整体作为整数利用atoi处理,
    此时得到的值是原数10的n幂次倍,n是小数位数.
    再除以10的n幂次,n是小数位,得到所求值.

    扩展使其可以处理科学记数,例如
    123.4e-7,12.4E2

*/
double atof(char s[])
{
    double val;/* 字符串对应浮点数 */
    int i;/* 字符串下标变量 */
    int power;/* 幂 */
    int exponent;/* 指数 */
    int sign;/* 小数符号 */
    
    /* 跳过空格 */    
    i = 0;
    while (isspace(s[i]))
    {
        i++;
    }
    /* 处理可选负号 */
    sign = (s[i] == '-') ? -1 : 1;
    /* 跳过负号,如果有 */
    if (s[i] == '-' || s[i] == '+')
    {
        i++;
    }
    /* 处理整数部分 */
    for (; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    /* 处理小数点 */
    if (s[i] == '.')
    {
        i++;
    }
    /* 小数点后每多一位,指数fraction_exp减1*/
    power = 1;
    for (;isdigit(s[i]); i++)
    {
        val = 10.0 * val + s[i] - '0';
        power *= 10;
    }

    val = sign * val / power;
    /* 处理幂符号 */
    if (s[i] == 'e' || s[i] == 'E')
    {
        /* 跳过幂符号 */
        /* 处理指数正负号 */
        sign = (s[++i] == '-') ? -1 : 1;
        /* 跳过负号,如果有 */
        if (s[i] == '-' || s[i] == '+')
        {
            i++;
        }
        /* 处理指数 */
        for (exponent = 0; isdigit(s[i]); i++)
        {
            exponent = 10 * exponent + (s[i] - '0');
        }

        /* 求指数对应的幂*/
        power = 1;
        while (exponent-- > 0)
        {
            power *= 10;
        }
        
        /* 处理负指数情况 */
        if (sign == -1)
        {
            val /= power;
        }
        else
        {
            val *= power;
        }
    }
    return val;
}