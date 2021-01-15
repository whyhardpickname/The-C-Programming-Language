#include<stdio.h>

void shellsort(int v[], int n);

int main()
{
    
    return 0;
}

void shellsort(int v[], int n)
{
    int gap;
    int i;
    int j;
    int temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}