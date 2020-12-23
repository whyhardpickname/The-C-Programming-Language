#include<stdio.h>

void squeese(char s[], char t[]);

int main()
{
    char s[] = "abcdef";
    char t[] = "abc";
    squeese(s, t);
    printf("%s\n", s);
    return 0;
}

void squeese(char s[], char t[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (; s[i] != '\0'; i++)
    {
        for (j = 0; t[j] != '\0' && t[j] != s[i]; j++)
        {
        }

        if (t[j] == '\0')
        {
            s[k++] = s[i];
        }
    }
    s[k] = '\0';
}