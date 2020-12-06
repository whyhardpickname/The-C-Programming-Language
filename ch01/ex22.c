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
    
    while ((c = getchar()) != EOF && c != '\n')
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
                while(--counter >= 0)
                {
                    putchar(token[counter]);
                }
            }
            else
            {
                column = 0;
                putchar('\n');
                if (last == INWORD)
                {
                    while(--counter >= 0)
                    {   
                        putchar(token[counter]);
                    }
                }
            }
            counter = 0;
        }
        token[counter++] = c;
        column++;
        last = cur;
    }
    if (last == INWORD)
    {
        printf("%s", token);
    }
    printf("\n");
    return 0;
}