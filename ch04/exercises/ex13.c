#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverse_helper(char s[], int lo, int hi);
void swap(char s[], int i, int j);

int main()
{
    char s[] = "abc";
    reverse(s);
    printf("%s\n", s);
    return 0;
}

/* 递归版反转字符串 */
void reverse(char s[])
{
    reverse_helper(s, 0, strlen(s) - 1);
}

void reverse_helper(char s[], int lo, int hi)
{
    if (lo < hi)
    {
        swap(s, lo, hi);
        reverse_helper(s, lo + 1, hi - 1);
    }
}

void swap(char s[], int i, int j)
{
    char temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}