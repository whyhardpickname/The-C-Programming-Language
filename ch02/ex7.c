#include<stdio.h>

int invert(int x, int p, int n);

int main()
{
    printf("%x", invert(0x0, 1, 3));//0x70000000
    return 0;
}

int invert(int x, int p, int n)
{
    int ymask = (1 << n) - 1;
    int offset = (sizeof(int) << 3) - n - p;
    int xmask = ymask << offset;
    return (~x & xmask) | (x & ~xmask);
}