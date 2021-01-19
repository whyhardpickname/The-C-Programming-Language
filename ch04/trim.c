#include<stdio.h>
#include<string.h>

int trim(char s[]);

int main()
{
    //空字符串
    char s1[] = "";
    trim(s1);
    printf("expected: %s\tactual: %s\n", "", s1);

    //空格字符串
    char s2[] = "  ";
    trim(s2);
    printf("expected: %s\tactual: %s\n", "", s2);

    //空格字符串
    char s3[] = "abc  ";
    trim(s3);
    printf("expected: %s\tactual: %s\n", "abc", s3);
    return 0;
}

/* 
    删除字符串尾部的空格,换行符和制表符.

    参数
    s   字符串
 */
int trim(char s[])
{
    int i;

    //从字符串尾部反向扫描,当遇到第一个不是空格,换行和制表的字符时,
    //推出循环.
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
        {
            break;
        }
    }
    s[i + 1] = '\0';
    return i;
}