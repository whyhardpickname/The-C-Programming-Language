#include<stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int b = 16;
    int len = 100;
    char s[len];
    //测试0
    itob(0, s, b);
    printf("%s\n", s);
    //9
    itob(9, s, b);
    printf("%s\n", s);
    //10
    itob(10, s, b);
    printf("%s\n", s);
    //15
    itob(15, s, b);
    printf("%s\n", s);
    //16
    itob(16, s, b);
    printf("%s\n", s);
    
    //-2147483648
    itob(-2147483648, s, b);
    printf("%s\n", s);
    return 0;
}

/* 
    将数字转为以b为底的整数的字符串
*/
void itob(int n, char s[], int b)
{
    int i;
    int sign;
    int r; //余数

    //记录符号
    sign = n;

    //转换数字
    i = 0;
    do 
    {
        r = abs(n % b);
        s[i++] = r <= 9 ? r + '0' : r + 'a' - 10;
    } 
    while ((n /= b) != 0);

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