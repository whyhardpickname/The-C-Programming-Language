#include<stdio.h>
#include<string.h>

int strrindex(char source[], char searchfor[]);
int strrindex_v2(char source[], char searchfor[]);
int main()
{
    char source[] = "abcabcabc";
    char searchfor[] = "abc";
    printf("expected: 6 actual: %d\n", strrindex(source, searchfor));
    printf("expected: 6 actual: %d\n", strrindex_v2(source, searchfor));
    return 0;
}

/* 
    返回字符串searchafor在字符串source最右边出现的位置

    参数
    source 源文本
    searchfor   目标字符串

    返回
    非负数  source的下表
    -1      未匹配
 */
int strrindex(char source[], char searchfor[])
{
    int i;
    int j;
    int k;
    int rightmost;//searchfor匹配时最靠近source右边的下标

    rightmost = -1;
    for (i = 0; source[i] != '\0'; i++)
    {
        //可以去掉s[j] != '\0',因为当s到底而t没到底,则t[k]!= '\0'
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
        {

        }
        if (k > 0 && searchfor[k] == '\0')//k > 0 表示非空字符
        {
            rightmost = i;
        }
    }
    return rightmost;
}

/* 
    返回字符串searchafor在字符串source最右边出现的位置
    从末尾开始找

    参数
    source 源文本
    searchfor   目标字符串

    返回
    非负数  source的下表
    -1      未匹配
 */
int strrindex_v2(char source[], char searchfor[])
{
    int i;
    int j;
    int k;
    
    //i不必减一,假设从i,到末尾长度是t,末尾下标s - 1 - i + 1 = t
    for (i = strlen(source) - strlen(searchfor); i >= 0; i--)
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