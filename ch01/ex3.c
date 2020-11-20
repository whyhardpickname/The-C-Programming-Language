#include<stdio.h>

int main(int args, char *argv[])
{
    printf("%3s\t%6s\n", "fahr", "celsius");

    double fahr, celsius;
    int upper, lower, step;
    
    upper = 300;
    lower = 0;
    step = 20;

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
    return 0;
}