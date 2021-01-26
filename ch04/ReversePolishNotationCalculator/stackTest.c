#include<stdio.h>

void push(double f);
double pop(void);
void peek();
void swapFirstTwoElement();
void clear();

int main()
{
    push(1.0);
    push(2.0);
    push(3.0);

    peek();
    swapFirstTwoElement();
    peek();
    clear();
    peek();
    return 0;
}