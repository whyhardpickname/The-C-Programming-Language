#include<stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    int n = -2147483648;
    int len = 100;
    char s[len];
    //最小字段宽度小于字符本身长度2
    itoa(n, s, 9);
    printf("%s\n", s);

    //最小字段宽度小于字符本身长度
    itoa(n, s, 10);
    printf("%s\n", s);

    //最小字段宽度等于字符本身长度
    itoa(n, s, 11);
    printf("%s\n", s);
    
    //最小字段宽度大于字符本身长度
    itoa(n, s, 12);
    printf("%s\n", s);

    //最小字段宽度大于字符本身长度
    itoa(n, s, 13);
    printf("%s\n", s);
    
    return 0;
}

/* 
    将数字转具有最小字段宽度的字符串
    
    加入处理n为最大负数情况
    由于被模数是负数,模数是整数,所以结果为负,
    不过与被模数为正时是相反数,所以求模后,再求其绝对值.
    由于有-0不大于0会造成死循环,循环的条件要改为不等于0

    参数
    n   数字
    s   接受字符串的数组
    w   最小字段宽度
*/
void itoa(int n, char s[], int w)
{
    int i;
    int sign;

    //记录符号
    sign = n;

    //转换数字
    i = 0;
    do 
    {
        s[i++] = abs(n % 10) + '0';
    } 
    while ((n /= 10) != 0);

    //处理正负号
    if (sign < 0)
    {
        s[i++] = '-';
    }

    //处理字段宽度,如果宽度不够,往数组接着填充空格
    while (i < w)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

/* 反转字符串 */
void reverse(char s[])
{
    int i;
    int j;
    char temp;

    for (j = 0; s[j] != '\0'; j++)
    {
    }

    for (i = 0, j--; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}