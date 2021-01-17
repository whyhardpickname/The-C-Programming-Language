#include<stdio.h>

#define abs(x) ((x) ? -(x) : (x))

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int n = -2147483648;
    int len = 100;
    char s[len];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

/* 
    将数字转为字符串, 加入处理n为最大负数情况
    由于被模数是负数,模数是整数,所以结果为负,
    不过与被模数为正时是相反数,所以求模后,再求其绝对值.
    由于有-0不大于0会造成死循环,循环的条件要改为不等于0
*/
void itoa(int n, char s[])
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