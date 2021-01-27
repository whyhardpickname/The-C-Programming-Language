#define NUMBER '0'     /* 标识找到一个数 */
#define NAME 'n'    /* 表示一个函数名被找到 */



void push(double);      /* 将一个操作数压入栈 */
double pop(void);       /* 将一个操作数弹出栈 */
int getop(char []);     /* 获取下一个操作数或操作符 */
int getch(void);         /* 从缓冲区获取一个字符 */
void ungetch(char);   /* 把字符压入缓冲区 */
void mathfunc(char []); /* 数学函数 */