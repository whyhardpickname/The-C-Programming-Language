#include<stdio.h>

#define MAX_COLUMN 10 //每行允许最大列数
#define INWORD 1 //位于单词之中为1,位于空格之中为0

int main()
{
    int c;
    int cur = !INWORD;
    int last = !INWORD;
    int column = 0;
    int counter = 0;
    char token[MAX_COLUMN];

    printf("0123456789012345678901234567890123456789\n");
    while ((c = getchar()) != EOF && c != '\n')
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
                column %= MAX_COLUMN;
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