#include<stdio.h>

#define LEN 10 //每行最大列数
#define INWORD 1 //位于单词之中为1,位于空格之中为0

int main()
{
    int c;
    int column = 0;
    int cur = !INWORD;
    int last = !INWORD;
    int counter = 0;
    char token[LEN];
    char *test = "123 123     123132    123  123\n";
    
    while ((c = *test++) != '\n')
    {
        if (c != ' ' || c != '\t')
        {
            cur = INWORD;
        }
        else
        {
            cur = !INWORD;
        }

        if (cur != last)
        {
            if (column < LEN)
            {
                while (--counter >= 0)
                {
                    printf("%c", token[counter]);
                }
            }
            else
            {
                printf("\n");
                if (cur != INWORD)
                {
                    while (--counter >= 0)
                    {
                        printf("%c", token[counter]);
                    }
                }
            }
            counter = 0;
        }
        token[counter++] = c;
        last = cur;
        column %= LEN;
        column++;
    }
    if (last == INWORD)
    {
        printf("%s", token);
    }
    printf("\n");
    return 0;
}