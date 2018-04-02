#include "../Headers/SequenceList.h"
#include "../Headers/LinkList.h"
#include "../Headers/StackSQ.h"





int main(void)
{
//    SQLIST L;
//
//    InitSqlist(&L,100);
//
//    AppendElem(&L,20);
//
//    AppendElem(&L,40);
//
//    AppendElem(&L,60);
//
//    DeleteElemSqlist(&L,1);
//
//    TraverseSqlist(L);

    LINKLIST LL;

    InitLinkList(&LL);

    AddElem(LL,23);

    AddElem(LL,24);

    AddElem(LL,25);

    AddElem(LL,26);

    TraverseLinkList(LL);

    DeleteElemLinkList(LL,24);

    TraverseLinkList(LL);

    DestoryLinkList(&LL);

    return 0;
}
