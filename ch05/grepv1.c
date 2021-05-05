#include<stdio.h>
#include<string.h>

#define MAXLINE 100

int getline(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;
    if (argc != 2) {
        printf("Uage: find pattern\n");
    }
    else {
        while (getline(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}

int getline(char *str, int limit) {
    int c;
    char *begin = str;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n') {
        *str++ = c;
    }
    if (c == '\n') {
        *str++ = c;
    }
    *str = '\0';
    return str - begin;
}