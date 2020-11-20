#include<stdio.h>

int main(int args, char *argv[])
{
    int c = getchar() != EOF;
    printf("%d", c);
    return 0;
}