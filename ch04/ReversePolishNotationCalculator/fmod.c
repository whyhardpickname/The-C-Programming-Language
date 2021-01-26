#include <stdio.h>
#include <math.h>

int main ()
{
   float a, b;
   int c;
   a = 9.2;
   b = 3.7;
   c = 2;
   printf("%f / %d 的余数是 %lf\n", a, c, fmod(a,c));
   printf("%f / %f 的余数是 %lf\n", a, b, fmod(a,b));
   
   return(0);
}