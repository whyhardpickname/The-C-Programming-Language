#include<stdio.h>
void escape(char s[], char t[]);
void escape_inverse(char s[], char t[]);

int main()
{
    
    return 0;
}

void escape(char s[], char t[])
{
    int i;
    int j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;

        default:
            s[j++] = t[i];
            break;
        }
        s[j] = '\0';
    }
}

void escape_inverse(char s[], char t[])
{
    int i;
    int j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        if (t[i] != '\\')
        {
            s[j++] = t[i];
        }
        else
        {
            switch (t[i])
            {
            case 't':
                s[j++] = '\t';
                break;
            
            case 'n':
                s[j++] = '\n';
                break;

            default:
                break;
            }
        }
    }
    s[j] = '\n';
}