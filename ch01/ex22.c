#include<stdio.h>

#define MAX_COLUMN 10 //每行允许最大列数
#define INWORD 1 //位于单词之中为1,位于空格之中为0

/*
    原理:token每接收一组非空字符或空字符后,如果当前位置小于最大列数,输出token.
        反之如果token是非空字符,换行输出.如果是空字符,换行.同时位置重置为0
    缺点:无法处理换行符和空行
*/
int main()
{
    int c;
    int cur = !INWORD;
    int last = !INWORD;
    int column = 0;
    int counter = 0;
    char token[MAX_COLUMN];
    printf("0123456789\n");
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t')
        {
            cur = INWORD;
        }
        else
        {
            cur = !INWORD;
        }

        if (cur == last)
        {
            token[counter++] = c;
        }
        else
        {
            if (column - 1 < MAX_COLUMN)
            {
                for (int i = 0; i < counter; i++)
                {
                    putchar(token[i]);
                }
            }
            else
            {
                putchar('\n');
                if (last == INWORD)
                {
                    for (int i = 0; i < counter; i++)
                    {
                        putchar(token[i]);
                    }
                }
                column = counter;
            }
            counter = 0;
            token[counter++] = c;
        }
        column++;
        last = cur;
    }
    
    if (column - 1 >= MAX_COLUMN)
    {
        putchar('\n');
    }

    for (int i = 0; i < counter; i++)
    {
        putchar(token[i]);
    }

    putchar('\n');
    return 0; 
}