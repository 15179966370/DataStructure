#include <stdio.h>
#include <stdlib.h>

#include "../Headers/SequenceList.h"










/** ���������� L ָ��Ҫ��ʼ����˳���
 *             n ˳��������
 *
 *             �����ʼ���ɹ����� 1�����򷵻� 0
 *
 */

int InitSqlist(SQLIST *L,int n){

    L ->elem = (elemtype *)malloc(n * sizeof(elemtype));   /* Ϊ elem �������� */

    if(L ->elem == NULL) return 0;                         /* ���䲻���ڴ棬��ʼ��ʧ�� */

    L ->size = n;                                           /* ����˳������� */

    L ->len = 0;                                            /* ��ʼ��Ϊ�ձ� */

    return 1;
}



/** ���������� ����˳���
 *
 */

void DestorySqlist(SQLIST *L){

    free(L ->elem);                 /* �ͷ� elem ��ָ����ڴ�� */

    L ->elem = NULL;

    L ->size = 0;

    L ->len = 0;
}


/** �������������˳��� L �Ѿ��ﵽ����󳤶ȣ����� 1�����򷵻� 0
 *
 *
 */

int IsSqlistFull(SQLIST L){

    return L.len == L.size;
}


/** �������������˳��� L �ǿձ����� 1�����򷵻� 0
 *
 *
 */

int IsSqlistEmpty(SQLIST L){

    return L.len == 0;
}



/** ���������� ���˳���δ������Ԫ�� e ��ӵ�˳����ĩβ��
 *             ����˳���ĳ��Ȼᷢ���仯������ L �����ó�
 *             ָ���Ͳ�������ӳɹ����� 1�����򷵻� 0��
 *
 *
 */

int AppendElem(SQLIST *L,elemtype e){

    if(IsSqlistFull(*L)) return 0;      /* ˳������� */

    L ->elem[L ->len] = e;              /* �� e ��ӵ���β */

    L ->len++;                          /* ˳��������� 1 */

    return 1;
}


/** ������������˳����� i(i >= 0)��λ���ϲ�������Ԫ��
 *
 *
 *
 */


int InsertElem(SQLIST *L,elemtype e,int i){

    int k;

    if(i > L ->len ||IsSqlistFull(*L))      /* i ֵ���Ϸ���˳��������������ʧ�� */

        return 0;

    for(k = L ->len - 1;k >= i;k--){        /* ��[i..len - 1]���������Ԫ������ƶ�һ����Ԫ���Ա�ʹ e �ܹ� */
                                            /* ���뵽  i ��λ���ϡ� */
        L ->elem[k + 1] = L ->elem[k];
    }

    L ->elem[i] = e;                        /* �� e ���뵽��ȷ��λ���� */

    L ->len++;                              /* ˳������� 1 */

    return 1;
}



/** ����������ɾ��˳����� i(i >= 0) λ���ϵ�Ԫ��
 *
 */


int DeleteElemSqlist(SQLIST *L,int i){

    int k;

    if(i >= L ->len || IsSqlistEmpty(*L))      /* i ֵ�Ƿ�����˳����ѿգ�����ʧ�� */

        return 0;

    for(k = i + 1;k < L ->len;k++){            /* ��[i..len - 1]���������Ԫ����ǰ�ƶ�һ����Ԫ*/

        L ->elem[k - 1] = L ->elem[k];
    }

    L ->len--;

    return 1;
}


/** ������������������˳�����Ԫ��������
 *
 */

void TraverseSqlist(SQLIST L){

    int i;

    for(i = 0;i < L.len;i++){          /* ���η������е�����Ԫ�� */

        printf(FORMATSTR,L.elem[i]);
    }
}


/** ������������˳����в���ĳ������Ԫ�ء�
 *            ����ҵ��򷵻ظ�����Ԫ�ص��±꣬���򷵻� -1
 *
 *
 */

int SearchSqlist(SQLIST L,elemtype key){

    int i;

    for(i = 0;i < L.len;i++){

        if(L.elem[i] == key)

            return i;
    }

    return -1;
}


