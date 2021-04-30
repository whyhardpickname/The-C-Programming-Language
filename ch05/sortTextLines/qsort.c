#include<string.h>

void qsort(char *linesPtr[], int left, int right);
void swap(char *v[], int i, int j);
// void swap(char * p1, char *p2);

void qsort(char *linesPtr[], int left, int right) {
    int i;
    int last;

    if (left >= right) { /* 如果子数组元素个素小于2，则返回。 */
        return;
    }
    // int store = left;
    // swap(linesPtr[left], linesPtr[left]);
    swap(linesPtr, left, (left + right) / 2);
    last = left;

    // int i;
    for (i = left + 1; i <= right; i++) {
        // if (strlen(linesPtr[i]) < strlen(linesPtr[right])) {
        //     swap(linesPtr[store++], linesPtr[i]);
        // }
        if (strcmp(linesPtr[i], linesPtr[left]) < 0) {
            swap(linesPtr, i, ++last);
        }
    }
    swap(linesPtr, left, last);
    qsort(linesPtr, left, last - 1);
    qsort(linesPtr, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}