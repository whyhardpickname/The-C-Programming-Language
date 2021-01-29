#include<stdio.h>
#define dprint(expr) printf(#expr " = %f\n", expr)
int main()
{
    double x = 1;
    double y = 2;
    dprint(x / y);
    return 0;
}