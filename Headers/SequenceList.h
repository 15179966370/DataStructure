//#include "SequenceList.h"  //�ظ�����������


typedef int elemtype;



typedef struct{

    elemtype *elem;   /* ָ����˳�������Ԫ�ص��ڴ�� */

    int size;         /* ˳������� */

    int len;          /* ˳����� */
}SQLIST;





#define FORMATSTR "%d "               /* �����ʽ */







extern int InitSqlist(SQLIST *L,int n);

extern void DestorySqlist(SQLIST *L);

extern int IsSqlistFull(SQLIST L);

extern int IsSqlistEmpty(SQLIST L);

extern int AppendElem(SQLIST *L,elemtype e);

extern int InsertElem(SQLIST *L,elemtype e,int i);

extern int DeleteElemSqlist(SQLIST *L,int i);

extern void TraverseSqlist(SQLIST L);

extern int SearchSqlist(SQLIST L,elemtype key);







