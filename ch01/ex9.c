#include <stdio.h>

#define NOBLANK 'a';

int main()
{
    int c;
    int last = NOBLANK;
    while ((c = getchar()) != EOF)
    {
        //输出读取的第一个空格，即相邻前一个字符不为空格的字符。其余空格都是相邻前一个字符为空格的字符。
        if (c != ' ' || last != ' ')
        {
            putchar(c);
        }
        last = c;
    }
    
    return 0;
}