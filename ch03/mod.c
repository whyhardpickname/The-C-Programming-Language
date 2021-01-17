#include<stdio.h>

int main()
{
    /* 
        c语言中x % y 与 (-x) % y 的结果是相反数
        x % y = x - y * (x / y)
        -x % y = -x - y * (-x / y)
               = -(x - y * (x / y))
     */

    printf("%d\n", 6 % 5);
    printf("%d\n", -6 % 5);
    printf("%d\n", 5 % 6);
    printf("%d\n", -5 % 6);

    printf("%d\n", 6 % -5);
    printf("%d\n", -6 % -5);
    printf("%d\n", 5 % -6);
    printf("%d\n", -5 % -6);
    return 0;
}