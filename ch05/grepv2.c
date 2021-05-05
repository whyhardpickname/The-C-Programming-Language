#include<stdio.h>
#include<string.h>

#define MAXLINE 100

int getline(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int c;
    int number = 0, exception = 0, found = 0, lineno = 0;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'n' :
                    number = 1;
                    break;
                case 'x':
                    exception = 1;
                    break;
                default :
                    printf("found illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if (argc != 1) {
        printf("Uage: find -x -n pattern\n");
    }
    else {
        while (getline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != exception) {
                if (number) {
                    printf("%d: ", lineno);
                }
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