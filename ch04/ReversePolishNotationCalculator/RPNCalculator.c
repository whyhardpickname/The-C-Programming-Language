#include <stdio.h>
#include <stdlib.h>      /* 调用atof函数,将字符值转为小数 */
#include <math.h>
#include <string.h>
#include "calcu.h" /* 双引号使用相对路径,起点是项目总文件夹 */

#define MAXOP 100        /* 操作数或操作符最大长度 */

void clear(void);

/* 
    逆波兰表达式计算器

    输入逆波兰表达式,输出计算结果.包含的操作有加减乘除. 
*/
int main()
{
    /* 
    主程序伪代码
    while (下一个操作符或操作数不是文件结束指示符)
    {
        if (是操作数)
        {
            压入栈;
        }
        else if (是操作符)
        {
            弹出操作符所需操作数
            运算
            将结果压入栈
        }
        else if (是换行符)
        {
            将栈顶弹出
        }
        else 
        {
            打印错误信息
        }
    }
     */

    int type;   /* 操作符或操作数类型 */
    double op1; /* 二元运算符的第一个操作数 */
    double op2; /* 二元运算符的第二个操作数 */
    char s[MAXOP];  /* 下一个运算符或操作数 */
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case NAME:
            if (strcmp(s, "sin") == 0)
            {
                push(sin(pop()));
            }
            else if (strcmp(s, "exp") == 0)
            {
                push(exp(pop()));
            }
            else if (strcmp(s, "pow") == 0)
            {
                op2 = pop();
                push(pow(pop(), op2));
            }
            else
            {
                printf("Invalid math function.\n");
            }
            break;
        
        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;
        
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        
        case '/':
            op2 = pop();
            /* 处理除零错误 */
            if (op2 != 0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error,zero divisor.\n");
            }
            break;

        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), op2));
            }
            else
            {
                printf("error,zero divisor.\n");
            }
            break;
        
        case '\n':
            printf("%f\n", pop());
            break;
        
        default:
            printf("error,illegal operator.\n");
            break;
        }
    }
    return 0;
}