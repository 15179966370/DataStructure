

typedef int elemtype;



typedef struct stack_tag{

    elemtype *elem;          /* ָ��������Ԫ�ص��ڴ�� */

    int top;                 /* ջ����ʶ��elem[top] ��ջ��Ԫ�� */

    int size;                /* ջ���������� elem ��ָ����ڴ��ܴ������Ԫ�ص�������� */
}SQSTACK;






extern int InitSqStack(SQSTACK *S,int n);

extern void DestroySqStack(SQSTACK *S);

extern int Push(SQSTACK *S,elemtype e);

extern int Pop(SQSTACK *S,elemtype *e);

extern int IsSqStackEmpty(SQSTACK S);

extern int IsSqStackFull(SQSTACK S);

