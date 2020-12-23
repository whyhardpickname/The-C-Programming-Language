#include<stdio.h>

unsigned rightrot(unsigned x, unsigned n);
int main()
{
    printf("%x\n", rightrot(0x3, 2));//0x34567812
    return 0;
}

unsigned rightrot(unsigned x, unsigned n)
{
    int offset = (sizeof(int) << 3) - n;
    return (x >> n) | (x << offset);
}