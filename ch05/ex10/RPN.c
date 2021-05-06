#include<stdio.h>

#define NUMBER 0

/* 逆波兰表达式计算器，通过命令行参数接受输入 */

/* while (下一个是数或运算符) {
    if (是数)
        压入栈
    else if (是运算符)
        弹出数
        运算
        压入栈
    else
        出错
    }
    将栈顶弹出
*/
int getop(char[]);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    int type;
    double temp;
    while (--argc > 0 && (type = getop(*++argv) != -1)) {
        switch (type) {
            case NUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                temp = pop();
                push(pop() - temp);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                if ((temp = pop()) != 0.0) {
                    push(pop() / temp);
                }
                else {
                    printf("Error: zero dividor.\n");
                }
                break;
            default:
                printf("Error:not a operator or oprand.\n");
        }
    }
    printf("%f\n", pop());
}