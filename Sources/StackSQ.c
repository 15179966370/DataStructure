#include <stdio.h>
#include <stdlib.h>

#include "../Headers/StackSQ.h"





/** 功能描述：初始化栈
 *
 *  参数说明：初始化顺序栈，栈的容量是 n 。成功则返回 1，否则返回 0。
 *
 *
 */


int InitSqStack(SQSTACK *S,int n){

    S ->elem = (elemtype *)malloc(n * sizeof(elemtype));     /* 为数据元素分配内存 */

    if(S ->elem == NULL) return 0;                           /* 初始化失败 */

    S ->size = n;                                            /* 设置栈的容量 */

    S ->top = -1;                                            /* 设置栈为空栈 */

    return 1;
}


/** 功能描述：销毁栈
 *
 *  注：释放栈所占的内存
 */

void DestroySqStack(SQSTACK *S){

    free(S ->elem);                                         /* 释放内存，并设置为 NULL */

    S ->elem = NULL;

    S ->top = -1;                                           /* 将其他成员设置成安全值 */

    S ->size = 0;
}



/** 功能描述：入栈
 *
 *  参数说明：在栈顶一端插入数据元素 e，操作成功，则返回 1，否则返回 0。
 */

int Push(SQSTACK *S,elemtype e){

    if(IsSqStackFull(*S)) return 0;                       /* 栈满，操作失败 */

    S ->top++;                                            /* top 加 1 */

    S ->elem[S ->top] = e;                                /* 将 e 赋值成新的成员 */

    return 1;
}



/** 功能描述：出栈
 *
 *  参数说明：获取栈顶元素，并删除栈顶，操作成功，则返回 1，否则返回 0。
 *
 *
 */

int Pop(SQSTACK *S,elemtype *e){

    if(IsSqStackEmpty(*S)) return 0;                      /* 栈空，操作失败 */

    *e = S ->elem[S ->top];                               /* 获取栈顶元素 */

    S ->top -- ;                                          /* 删除栈顶 */

    return 1;
}


/** 功能描述：判断栈空
 *
 */


int IsSqStackEmpty(SQSTACK S){

    return S.top == -1;
}


/** 功能描述：判断栈满
 *
 */

int IsSqStackFull(SQSTACK S){

    return S.top == S.size - 1;
}





