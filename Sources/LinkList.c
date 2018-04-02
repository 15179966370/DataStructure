#include <stdio.h>
#include <stdlib.h>

#include "../Headers/LinkList.h"






/**  ��������������һ������ͷ�ڵ�ĵ������ɹ��򷵻� 1�����򷵻� 0��
 *
 *   �÷��� LINKLIST L = NULL;
 *          InitLinkList(&L);
 *
 *
 */


int InitLinkList(LINKLIST *L){

    *L = (LINKLIST)malloc(sizeof(NODE));     /* ����ͷ�ڵ� */

    if(*L == NULL) return 0;                 /* ʧ�� */

    (*L) ->next = NULL;                      /* ����������Ϊ������ */

    return 1;
}


/** �������������� L ��ָ��ĵ��������ͷ����еĽڵ�
 *
 *  �÷��� DestoryLinkList(&L);
 *
 */

void DestoryLinkList(LINKLIST *L){

    NODEPTR p,q;

    p = *L;                                 /* p ָ������ĵ�һ���ڵ㣬��ͷ�ڵ� */

    while(p){

        q = p;

        p = p ->next;                       /* p ָ���Լ��ĺ�̽ڵ㣬�� p ���� next ������ƶ�һ����Ԫ */

        free(q);                            /* �ͷŽڵ� q */
    }

    *L = NULL;
}



/** ������������ȡ�� i(i >= 1) ��Ԫ��
 *
 *  ����˵����L ��ĳ�������ͷ�ڵ�ָ�룬�������������е� i ��Ԫ�صĽڵ�ָ�룬
 *             ͬʱ *pre ��ָ������ǰ������� i ֵ�Ƿ��������� NULL������ *pre
 *             ��ָ������ǰ������� i ֵ�Ƿ��������� NULL������ *pre Ҳ�ᱻ���ó� NULL��
 *
 *
 *
 */

NODEPTR GetElemAt(LINKLIST L,int i,NODEPTR *pre){

    NODEPTR p;

    int k;

    p = L;                                  /* p ָ������ͷ�ڵ� */

    k = 0;                                  /* ������ k �� 0 */

    while(k < i && p != NULL){              /* ���û�дﵽ����ĩβ���Ҽ�������ֵ k С�� i���ͼ���ѭ�� */
                                            /* ѭ�������У� *pre һֱ�� p ��ǰ�� */
        *pre = p;                           /*  *pre ָ�� p ��ǰ���ڵ� */

        p = p ->next;                       /* p ָ���Լ��ĺ�� */

        k++;                                /* �������� 1 */
    }

    if(k < i){

        *pre = NULL;                        /* i ֵ�Ƿ� */
    }

    return p;

}



/** ����������������������Ԫ��
 *
 *  ����˵������ e ��ӵ����� L �У������������ǽ� e �ڵ���뵽ͷ�ڵ�ĺ��档
 *             ����ɹ��򷵻� 1,���򷵻� 0��
 *
 *  ע��������ͷ�巨����Ԫ�أ������е�Ԫ��˳���������˳���෴
 */

int AddElem(LINKLIST L,elemtype e){

    NODEPTR p;

    p = (NODEPTR)malloc(sizeof(NODE));    /* Ϊ�ڵ� e ����ڵ� */

    if(p == NULL) return 0;               /* ����ʧ�� */

    p ->data = e;                         /* �� e ��ŵ��ڵ� p �� */

    p ->next = L ->next;                  /* �Ƚ� p �ĺ��ָ��ͷ�ڵ�ĺ�� */

    L ->next = p;                         /* ͷ�ڵ�ĺ��ָ�� p */

    return 1;
}



/** ����������������� i(i >= 1)��λ���ϲ���ĳ����Ԫ��
 *
 *  ����˵����������Ԫ�� e ���� L �е� i ��λ���ϣ������ɹ����� 1�����򷵻� 0��
 *
 *
 */


int InsertElemAt(LINKLIST L,elemtype e,int i){

    NODEPTR p,pre,q;

    q = (NODEPTR)malloc(sizeof(NODE));   /* Ϊ�ڵ� e ����ڵ� */

    if(q == NULL) return 0;              /* ����ʧ�� */

    q ->data = e;                        /* ������ e ��ŵ��ڵ� q �� */

    p = GetElemAt(L,i,&pre);             /* ��ȡ L �еĵ� i ���ڵ�ָ�� p ����ǰ��ָ�� pre ���ڵ㽫���뵽 p �� pre ֮�� */

    if(pre == NULL) return 0;            /* i ֵ�Ƿ� */

    q ->next = p;                        /* �Ƚ� q �ĺ��ָ�� p */

    pre ->next = q;                      /* �ٽ� pre �ĺ��ָ�� q  */

    return 1;
}




/** ����������ɾ���� i(i >= 1) ��Ԫ��
 *
 *
 */

int DeleteElemAt(LINKLIST L,int i){

    NODEPTR p,pre;

    p = GetElemAt(L,i,&pre);             /* �ҵ�Ҫɾ���Ľڵ� p ����ǰ�� pre  */

    if(p == NULL) return 0;              /* i ֵ�Ƿ� */

    pre ->next = p ->next;               /* ɾ���ڵ� p */

    free(p);                             /* �ͷŽڵ� p */

    return 1;
}



/** ������������������
 *
 *  ע�� L ->next ���ǵ�һ�����ݽڵ㣬�ڵ� L ��ͷ�ڵ㣬
 *       �������Ч���ݡ�
 *
 *
 */

void TraverseLinkList(LINKLIST L){

    NODEPTR p;

    p = L ->next;                       /* p ָ�� L �����еĵ�һ�����ݵ� */

    while(p){

        printf(FORMATSTR,p ->data);     /* ���  p �������� */

        p = p ->next;                   /* p ���� next ָ������ƶ�һ����Ԫ */
    }
}


/** ��������������ĳ������Ԫ��
 *
 *  ����˵���������� L �в���ֵ���� e �Ľڵ㣬���ؽڵ�ָ���Լ�
 *             �ýڵ��ǰ��������Ҳ������� NULL��
 *
 *
 *
 */

NODEPTR SearchLinkList(LINKLIST L,elemtype e,NODEPTR *pre){

    NODEPTR p;

    *pre = L;                           /* (*pre) ָ�������ͷ�ڵ� */

    p = L ->next;                       /* p ָ������ĵ�һ�����ݵ㣬��ʱ (*pre) �Ѿ��� p ��ǰ�� */

    while(p != NULL && p ->data != e){  /* ��� p û�е�������ĩβ���� p ���������� e�������ѭ���� */
                                        /* ��ѭ���У�(*pre) sʼ���� p ��ǰ�� */
        *pre = p;

        p = p ->next;                   /* p ���� next ָ��������ƶ����ƶ�ǰ (*pre) ָ�� p */
    }

    if(p == NULL) return *pre = NULL;   /* û���ҵ� e */

    return p;
}



/** ����������ɾ��ĳ���ض�����Ԫ��
 *
 *  ����˵�������������������� e �Ľڵ�ɾ��
 *
 *
 */


int DeleteElemLinkList(LINKLIST L,elemtype e){

    NODEPTR p,pre;

    p = SearchLinkList(L,e,&pre);      /* ������������ e �Ľڵ㼰��ǰ�������ؽڵ�ָ�� */

    if(p == NULL) return 0;            /* ����ʧ�ܣ�û���ҵ� */

    pre ->next = p ->next;             /* ɾ���ڵ� p */

    free(p);                           /* �ͷŽڵ� p */

    return 1;
}





