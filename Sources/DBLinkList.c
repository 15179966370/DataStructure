#include <stdio.h>
#include <stdlib.h>

#include "../Headers/DBLinkList.h"




/** ���������� ɾ��˫�������ĳ���ڵ�
 *
 *  ����˵����p ��ĳ˫�������еĽڵ㣬�� p ��������ɾ�����ͷŽڵ��ڴ�
 *
 *  ע��˫������ɾ��������Ҫ�޸� 2 ��ָ����
 *
 */


void DeleteElemDBLinkList(DBNODEPTR p){

    DBNODEPTR pre;

    pre = p ->proir;                       /* pre ָ�� p ��ǰ�� */

    if(pre != NULL)

        pre ->next = p ->next;             /* pre �ĺ��ָ�� p ����Ľڵ�*/

    if(p ->next != NULL)

        p ->next ->proir = pre;            /* p ��ǰ��ָ�� pre */

    free(p);                               /* �ͷ� p �ڵ��ڴ� */
}



/** ������������Ԫ�ز��뵽˫�������нڵ�  p  �ĺ��档
 *
 *  ����˵������Ԫ�� e ���뵽ĳ˫�������нڵ� p �ĺ��档
 *
 *  ע1��˫���������Ԫ����Ҫ�޸� 4 ��ָ����
 *
 *  ע2������������� ���ȽӺ�� ��˳��ԭ��
 *
 *
 */


int InsertElemAfterDB(DBNODEPTR p,elemtype e){

    DBNODEPTR q;

    q = (DBNODEPTR)malloc(sizeof(DBNDOE));  /* ����ڵ� */

    if(q == NULL) return 0;

    q ->data = e;

    q ->next = p ->next;

    q ->proir = p;

    if(p ->next != NULL)

        p ->next ->proir = q;

    p ->next = q;

    return 1;
}

