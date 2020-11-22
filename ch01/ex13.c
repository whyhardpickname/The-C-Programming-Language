#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 20

int main()
{
    int i, c, state, word_len;
    int words_len_count[MAX_LENGTH];

    for (i = 0; i < MAX_LENGTH; i++)
    {
        words_len_count[i] = 0;
    }
    state = OUT;
    word_len = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            if (word_len > 0)
            {
                words_len_count[word_len]++;
            }
            word_len = 1;
            state = IN;
        }
        else if (state == IN)
        {
            word_len++;
            state = IN;
        }
    }

    int j;

    for (i = 0; i < MAX_LENGTH; i++)
    {
        if (words_len_count[i] != 0)
        {
            printf("%d ", i);
            for (j = 0; j < words_len_count[i]; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }

    int copy[MAX_LENGTH];
    for (i = 0; i < MAX_LENGTH; i++)
    {
        copy[i] = words_len_count[i];
        printf("%2d ", i);
    }
    printf("\n");

    for (i = 0; i < MAX_LENGTH; i++)
    {
        for (j = 0; j < MAX_LENGTH; j++)
        {
            if (copy[j] > 0)
            {
                printf("%2s ", "*");
                copy[j] -= 1;
            }
            else
            {
                printf("%2s ", " ");
            }
        }
        printf("\n");
    }
    return 0;
}
