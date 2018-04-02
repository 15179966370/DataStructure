

typedef int elemtype;



typedef struct stack_tag{

    elemtype *elem;          /* 指向存放数据元素的内存块 */

    int top;                 /* 栈顶标识，elem[top] 是栈顶元素 */

    int size;                /* 栈的容量，即 elem 所指向的内存能存放数据元素的最大数量 */
}SQSTACK;






extern int InitSqStack(SQSTACK *S,int n);

extern void DestroySqStack(SQSTACK *S);

extern int Push(SQSTACK *S,elemtype e);

extern int Pop(SQSTACK *S,elemtype *e);

extern int IsSqStackEmpty(SQSTACK S);

extern int IsSqStackFull(SQSTACK S);

