#include<stdio.h>
#include<ctype.h>

void expand(char s1[], char s2[]);
void expand_v2(char s1[], char s2[]);
int sometype(char c1, char c2);

int main()
{
    int len = 100;
    char s2[len];
    char *s1 = "-a-b-z-";
    expand_v2(s1, s2);
    printf("%s\n", s2);
    return 0;
}

/*
    将字符串s2中形如"-c1-cn-"的字字符串扩展为
    "-c1c2...ci...cn-",其中c1 < c2 < ... < ci < ... < cn
    任意两个字符都为数字或大小写相同的字母.
    ci表示编码对应的数值.
    前导和尾随的'-'可省略.
    结果保存在字符数组s1
    这样一串字符称为缩写字符串.
*/
void expand(char s1[], char s2[])
{
    char c;
    int i;
    int j;
    int k;
    
    k = 0;
    for (i = j = 0; s2[i] != '\0';)
    {
        if (s2[i + 1] != '\0' && 
                s2[i + 2] != '\0' &&
                sometype(s2[i], s2[i + 2]) && 
                s2[i + 1] == '-')
        {
            for (c = s2[i]; c < s2[i + 2]; c++) //边界条件<,暂时不输出最后一个字符
            {
                s1[k++] = c;
            }
            i += 2;//跳到该次缩写字符串最后一个字符进行下一次判断
        }
        else
        {
            //如果不满足条件,恰好输出相邻上个缩写字符串的最后一个字符或者其它字符
            s1[k++] = s2[i++];
        }
    }
    s1[k] = '\0';
}

/*
    返回1当两个字符都为数字或者都为小写或大写字母.
*/
int sometype(char c1, char c2)
{
    if (isdigit(c1) && isdigit(c1))
    {
        return 1;
    }
    else if (islower(c1) && islower(c2))
    {
        return 1;
    }
    else if (isupper(c1) && isupper(c2))
    {
        return 1;
    }

    return 0;
}

/*
    将缩写记号扩写后的字符串s1保存到s2中.
*/
void expand_v2(char s1[], char s2[])
{
    int i;
    int j;
    char c;

    i = j = 0;
    while ((c = s1[i++]) != '\0') //假设缩写记号都合法
    {
        if (s1[i] == '-' && s1[i + 1] >= c)
        {
            ++i;
            while (c < s1[i])
            {
                s2[j++] = c++;
            }
        }
        else
        {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}