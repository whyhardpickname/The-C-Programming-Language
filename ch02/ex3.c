#include<stdio.h>

int htoi(char s[]);

int main()
{
    printf("%d\n", htoi("0x1"));
    printf("%d\n", htoi("0X9"));
    printf("%d\n", htoi("0xa"));
    printf("%d\n", htoi("0Xf"));
    printf("%d\n", htoi("0xA"));
    printf("%d\n", htoi("0XF"));
    printf("%d\n", htoi("0Xq"));
    return 0;
}

int htoi(char s[])
{
    int i = 0;
    int n = 0;
    int valid = 1;
    
    if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
    {
        i += 2;
    }

    for (; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            n = n * 16 + (s[i] - '0');
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            n = n * 16 + (s[i] - 'a' + 10);
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            n = n * 16 + (s[i] - 'A' + 10);
        }
        else
        {
            valid = 0;
            break;
        }
    }
    if (!valid)
    {
        return -1;
    }
    return n;
}