#include<stdio.h>

#define MAXLINE 100 //最大输入行长度

int getlines(char line[], int lim);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";

/*
    找出所有与模式匹配的行
    
    流程:
    while (还有未处理行)    
        if (满足所给模式)
        {
            输出与模式匹配的行
        }

 */
int main()
{
    char line[MAXLINE];
    int found;//与模式匹配的行数
    found = 0;
    while (getlines(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) != -1)
        {
            printf("%s", line);
            found++;
        }
    }
    return found;
}
//TODO
// -getline函数
// -strindex函数

/* 
    该函数读取输入文本的一行,并把当前行保存在字符数组line中.
    
    参数
    line    存储文本每行内容的字符数组
    lim     字符组数最大长度,包括'\0'

    返回
        1   当输入文本存在下一行,并把当前行保存在line中.
        0   当输入文本不存在下一行.
 */
int getlines(char line[], int lim)
{
    int c;
    int i;
    //lim先减1因为最后还要放'\0'
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }
    if (c == '\n') //如果有换行符,说明lim > 0
    {
        line[i++] = '\n';
    }
    line[i] = '\0';//总要放终止符
    return i;
}
/* 
    该函数返回字符串t在字符串s中第一次出现的位置的下表索引
    参数
    s   文本
    t   目标字符串
    
    返回
    非负数  字符串t在s出现的初始位置
    -1     文本不含指定字符串

 */
int strindex(char source[], char searchfor[])
{
    int i;
    int j;
    int k;

    for (i = 0; source[i] != '\0'; i++)
    {
        //可以去掉s[j] != '\0',因为当s到底而t没到底,则t[k]!= '\0'
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
        {

        }
        if (k > 0 && searchfor[k] == '\0')//k > 0 表示非空字符
        {
            return i;
        }
    }
    return -1;
}