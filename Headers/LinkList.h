

typedef int elemtype;




// NDOE 指的是 struct node_tag,即节点与数据类型。
// NODEPTR 是指 NODE * 类型，是指向节点的指针类型。
// LINKLIST 也是 NODE * 型，与 NODEPTR 属于同一类型。之所以又起了一个别名，完全是出于算法可读性的需要。

typedef struct node_tag{

    elemtype data;

    struct node_tag *next;
}NODE,*NODEPTR,*LINKLIST;


#define FORMATSTR "%d "               /* 输出格式 */






extern int InitLinkList(LINKLIST *L);

extern void DestoryLinkList(LINKLIST *L);

extern NODEPTR GetElemAt(LINKLIST L,int i,NODEPTR *pre);

extern int AddElem(LINKLIST L,elemtype e);

extern int InsertElemAt(LINKLIST L,elemtype e,int i);

extern int DeleteElemAt(LINKLIST L,int i);

extern void TraverseLinkList(LINKLIST L);

extern NODEPTR SearchLinkList(LINKLIST L,elemtype e,NODEPTR *pre);

extern int DeleteElemLinkList(LINKLIST L,elemtype e);









