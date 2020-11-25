#include <stdio.h>

float celsius(float fahr);

int main()
{
    int lower, upper, step;
    float fahr;

    lower = 0;
    upper = 300;
    step = 10;

    printf("%s %s\n", "fahr", "celsius");
    for (fahr = lower; fahr < upper; fahr += step)
    {
        printf("%3.0f %5.2f\n", fahr, celsius(fahr));
    }
    
    return 0;
}

float celsius(float fahr)
{
    return (5 / 9.0) * (fahr - 32);
}