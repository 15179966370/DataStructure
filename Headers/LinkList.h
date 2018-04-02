

typedef int elemtype;




// NDOE ָ���� struct node_tag,���ڵ����������͡�
// NODEPTR ��ָ NODE * ���ͣ���ָ��ڵ��ָ�����͡�
// LINKLIST Ҳ�� NODE * �ͣ��� NODEPTR ����ͬһ���͡�֮����������һ����������ȫ�ǳ����㷨�ɶ��Ե���Ҫ��

typedef struct node_tag{

    elemtype data;

    struct node_tag *next;
}NODE,*NODEPTR,*LINKLIST;


#define FORMATSTR "%d "               /* �����ʽ */






extern int InitLinkList(LINKLIST *L);

extern void DestoryLinkList(LINKLIST *L);

extern NODEPTR GetElemAt(LINKLIST L,int i,NODEPTR *pre);

extern int AddElem(LINKLIST L,elemtype e);

extern int InsertElemAt(LINKLIST L,elemtype e,int i);

extern int DeleteElemAt(LINKLIST L,int i);

extern void TraverseLinkList(LINKLIST L);

extern NODEPTR SearchLinkList(LINKLIST L,elemtype e,NODEPTR *pre);

extern int DeleteElemLinkList(LINKLIST L,elemtype e);









