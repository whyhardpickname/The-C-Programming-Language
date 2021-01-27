#include <stdio.h>
#include <stdlib.h>      /* 调用atof函数,将字符值转为小数 */
#include <math.h>
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
    double var[26];     /* 26个变量 */
    int varname;    /* 变量符号 */
    
    for (int i = 0; i < 26; i++)
    {
        var[i] = 0.0;
    }

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case NAME:
            mathfunc(s);
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
        
        case '=': 
            pop();  /* 例子 2 B = */
            if (varname >= 'A' && varname <= 'Z')
            {
                var[varname - 'A'] = pop();
            }
            else
            {
                printf("error:invlid variable name.\n");
            }
            break;
        
        case '\n':
            var[0] = pop();
            printf("%f\n", var[0]);
            break;
        
        default:
            if (type >= 'A' && type <= 'Z')
            {
                push(var[type - 'A']);
            }
            else
            {
                printf("error,illegal operator.\n");
            }
            break;
        }
        varname = type; /* 用于保存当前变量名 */
    }
    return 0;
}