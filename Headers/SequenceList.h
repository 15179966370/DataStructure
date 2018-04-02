//#include "SequenceList.h"  //重复包含，出错


typedef int elemtype;



typedef struct{

    elemtype *elem;   /* 指向存放顺序表数据元素的内存块 */

    int size;         /* 顺序表容量 */

    int len;          /* 顺序表长度 */
}SQLIST;





#define FORMATSTR "%d "               /* 输出格式 */







extern int InitSqlist(SQLIST *L,int n);

extern void DestorySqlist(SQLIST *L);

extern int IsSqlistFull(SQLIST L);

extern int IsSqlistEmpty(SQLIST L);

extern int AppendElem(SQLIST *L,elemtype e);

extern int InsertElem(SQLIST *L,elemtype e,int i);

extern int DeleteElemSqlist(SQLIST *L,int i);

extern void TraverseSqlist(SQLIST L);

extern int SearchSqlist(SQLIST L,elemtype key);







