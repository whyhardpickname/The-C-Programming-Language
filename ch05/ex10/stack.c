#include<stdio.h>

#define MAXLENGTH 100
static double stack[MAXLENGTH];
static double *p = stack;

void push(double f) {
    if (p < stack + MAXLENGTH) {
        *p++ = f;
    }
    else {
        printf("Error: stack overflow.\n");
    }
}
double pop(void) {
    if (p > stack) {
        return *--p;
    }
    else {
        printf("Error:stack is empty.\n");
        return 0.0;
    }
}