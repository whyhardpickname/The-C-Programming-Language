#include<stdio.h>

int binsearch_1(int x, int v[], int n);//循环内执行1次判断
int binsearch_2(int x, int v[], int n);//循环内执行2次判断


int main()
{
    int v[] = {1, 2, 3, 4 ,5};
    int n = 5;
    int x = 3;
    printf("%s %d\n", "binsearch_1", binsearch_1(x, v, n));
    printf("%s %d\n", "binsearch_2", binsearch_2(x, v, n));
    return 0;
}

int binsearch_1(int x, int v[], int n)
{
    int lo;
    int hi;
    int mid;

    lo = 0;
    hi = n - 1;
    /*
        将相等性测试移到while的循环判断内.
    */
    while (lo <= hi && x != v[mid])
    {
        mid = (lo + hi) / 2;
        if (x < v[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    if (x == v[mid])
    {
        return mid;
    }
    return -1;
    
}

int binsearch_2(int x, int v[], int n)
{
    int lo;
    int hi;
    int mid;

    lo = 0;
    hi = n - 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (x < v[mid])
        {
            hi = mid - 1;
        }
        else if (x > v[mid])
        {
            lo = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}