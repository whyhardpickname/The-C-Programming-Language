#include<stdio.h>

int main()
{
    int i = 0;
    int lim = 10;
    int c;
    char s[lim];
    
    // for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    // {
    //     s[i] = c;
    // }

    for (i = 0; i < lim - 1;)
    {
        c = getchar();
        if (c != '\n')
        {
            if (c != EOF)
            {
                s[i++] = c;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    printf("%s\n", s);
    return 0;
}