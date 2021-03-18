#define ALLOCSIZE 1000 /* 可用空间大小 */

static char allocbuf[ALLOCSIZE]; /* alloc使用的内存空间 */
static char *allocp = allocbuf; /* 指向下一个空闲位置的指针 */

/* 分配空间 */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* 剩余空间足够 */
        allocp += n;
        return allocp - n;
    }
    else { /* 剩余空间不足 */
        return 0;
    }
}

/* 释放分配的空间 */
void afree(char *p)
{
    if (allocbuf <= p && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}