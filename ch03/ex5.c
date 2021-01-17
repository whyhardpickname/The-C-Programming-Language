//todo
#include<stdio.h>

#define abs(x) ((x) ? -(x) : (x))

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int n = 16;
    int b = 16;
    int len = 100;
    char s[len];
    itob(n, s, b);
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
        if (r >= 0 && r <= 9)
        {
            s[i++] = r + '0';
        }
        else 
        {
            //A的ASCII码是41,对应10
            s[i++] = (char) (r + 31);
        }
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