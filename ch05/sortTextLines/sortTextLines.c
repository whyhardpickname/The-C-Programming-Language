#include <stdio.h>
#include <string.h>
#define MAXLINES 100 //进行排序的最大文本行数
#define MAXSTORE 1000 /* 可用空间大小 */

char lineStore[MAXSTORE]; /* alloc使用的内存空间 */
char *linePtr[MAXLINES]; //指向文本行的指针数组

int readLines(char *linePtr[], int maxLines);
void qsort(char *linesPtr[], int left, int right);
void writeLines(char *linePtr[], int nlines);
/* 对不同长度的文本行进行排序 
    1.读取所有文本行
    2.按长度升序排序
    3.输出排序后的所有文本行
*/


/* 对输入的文本行进行排序 */
int main() {
    int nLines; /* 读取得输入行行数 */
    if ((nLines = readLines(linePtr, MAXLINES)) >= 0) {
        qsort(linePtr, 0, nLines - 1);
        writeLines(linePtr, nLines);
        return 0;
    }
    else {
        printf("Error: too many lines.\n");
        return 1;
    }
}