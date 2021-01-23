#include <stdio.h>
#include "calcu.h"

#define MAXVAL 100 /* 栈的最大深度 */

int sp = 0; /* 指向下一个栈空闲位置 */
double val[MAXVAL]; /* 保存值的栈 */

/* 将一个小数压入栈中 */
void push(double f)
{
    /* 检测栈是否还有空间 */
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("%s", "The stack is full.\n");
    }
}

/* 将一个小数弹出栈 */
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("%s", "The stack is empty.\n");
        return 0.0;
    }
    
}

/* 测试 */
int main()
{
    push(1.0);
    push(2.0);
    push(3.0);
    printf("%f\n", pop());
    printf("%f\n", pop());
    printf("%f\n", pop());
    printf("%f\n", pop());

    sp = MAXVAL;
    push(4.0);

}