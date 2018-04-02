#include <stdio.h>
#include <stdlib.h>

#include "../Headers/StackSQ.h"





/** ������������ʼ��ջ
 *
 *  ����˵������ʼ��˳��ջ��ջ�������� n ���ɹ��򷵻� 1�����򷵻� 0��
 *
 *
 */


int InitSqStack(SQSTACK *S,int n){

    S ->elem = (elemtype *)malloc(n * sizeof(elemtype));     /* Ϊ����Ԫ�ط����ڴ� */

    if(S ->elem == NULL) return 0;                           /* ��ʼ��ʧ�� */

    S ->size = n;                                            /* ����ջ������ */

    S ->top = -1;                                            /* ����ջΪ��ջ */

    return 1;
}


/** ��������������ջ
 *
 *  ע���ͷ�ջ��ռ���ڴ�
 */

void DestroySqStack(SQSTACK *S){

    free(S ->elem);                                         /* �ͷ��ڴ棬������Ϊ NULL */

    S ->elem = NULL;

    S ->top = -1;                                           /* ��������Ա���óɰ�ȫֵ */

    S ->size = 0;
}



/** ������������ջ
 *
 *  ����˵������ջ��һ�˲�������Ԫ�� e�������ɹ����򷵻� 1�����򷵻� 0��
 */

int Push(SQSTACK *S,elemtype e){

    if(IsSqStackFull(*S)) return 0;                       /* ջ��������ʧ�� */

    S ->top++;                                            /* top �� 1 */

    S ->elem[S ->top] = e;                                /* �� e ��ֵ���µĳ�Ա */

    return 1;
}



/** ������������ջ
 *
 *  ����˵������ȡջ��Ԫ�أ���ɾ��ջ���������ɹ����򷵻� 1�����򷵻� 0��
 *
 *
 */

int Pop(SQSTACK *S,elemtype *e){

    if(IsSqStackEmpty(*S)) return 0;                      /* ջ�գ�����ʧ�� */

    *e = S ->elem[S ->top];                               /* ��ȡջ��Ԫ�� */

    S ->top -- ;                                          /* ɾ��ջ�� */

    return 1;
}


/** �����������ж�ջ��
 *
 */


int IsSqStackEmpty(SQSTACK S){

    return S.top == -1;
}


/** �����������ж�ջ��
 *
 */

int IsSqStackFull(SQSTACK S){

    return S.top == S.size - 1;
}





