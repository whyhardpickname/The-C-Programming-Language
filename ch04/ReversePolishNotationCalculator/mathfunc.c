#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calcu.h"

/* 根据函数名调用相应数学函数 */
void mathfunc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
            {
                push(sin(pop()));
            }
            else if (strcmp(s, "exp") == 0)
            {
                push(exp(pop()));
            }
            else if (strcmp(s, "pow") == 0)
            {
                op2 = pop();
                push(pow(pop(), op2));
            }
            else
            {
                printf("Invalid math function.\n");
            }
}