#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{

    printf("%15s%12s%12s", "type name","MAX", "MIN");
    printf("\n");

    printf("%15s%12d%12d", "unsigned char",UCHAR_MAX, 0);
    printf("\n");
    printf("%15s%12d%12d", "signed char",CHAR_MAX, CHAR_MIN);
    printf("\n");

    printf("%15s%12d%12d", "unsigned short",USHRT_MAX, 0);
    printf("\n");
    printf("%15s%12d%12d", "signed short",SHRT_MAX, SHRT_MIN);
    printf("\n");

    printf("%15s%12d%12d", "unsigned int",UINT_MAX, 0);
    printf("\n");
    printf("%15s%12d%12d", "signed int",INT_MAX, INT_MIN);
    printf("\n");

    printf("%15s %lu%d", "unsigned long", ULONG_MAX, 0);
    printf("\n");
    printf("%15s %ld %ld", "signed long", LONG_MAX, LONG_MIN);
    printf("\n");

    printf("%15s %12f", "float_max", FLT_MAX);
    printf("\n");
    printf("%15s %12f", "float_min", FLT_EPSILON);
    printf("\n");
    printf("%15s %12f", "double_max", DBL_MAX);
    printf("\n");
    printf("%15s %12f", "double_min", DBL_EPSILON);
    printf("\n");


    return 0;
}