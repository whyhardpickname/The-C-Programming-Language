#include<stdio.h>

int main(int args, char *argv[])
{
    printf("%3s\t%6s\n", "celsiusfahr", "fahr");

    double fahr, celsius;
    int upper, lower, step;
    
    upper = 300;
    lower = -100;
    step = 20;

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}