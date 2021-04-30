#include <stdio.h>
void writeLines(char *linePtr[], int nlines) {
    // int i;
    // for (i = 0; i < nlines; i++) {
    //     printf("%s\n", linePtr[i]);
    // }
    while (nlines-- > 0) {
        printf("%s\n", *linePtr++);
    }
}