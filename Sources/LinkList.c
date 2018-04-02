#include <stdio.h>
#include <stdlib.h>

#include "../Headers/LinkList.h"






/**  功能描述：创建一个带有头节点的单链表，成功则返回 1，否则返回 0。
 *
 *   用法： LINKLIST L = NULL;
 *          InitLinkList(&L);
 *
 *
 */


int InitLinkList(LINKLIST *L){

    *L = (LINKLIST)malloc(sizeof(NODE));     /* 分配头节点 */

    if(*L == NULL) return 0;                 /* 失败 */

    (*L) ->next = NULL;                      /* 将链表设置为空链表 */

    return 1;
}


/** 功能描述：销毁 L 所指向的单链表，即释放所有的节点
 *
 *  用法： DestoryLinkList(&L);
 *
 */

void DestoryLinkList(LINKLIST *L){

    NODEPTR p,q;

    p = *L;                                 /* p 指向单链表的第一个节点，即头节点 */

    while(p){

        q = p;

        p = p ->next;                       /* p 指向自己的后继节点，即 p 沿着 next 链向后移动一个单元 */

        free(q);                            /* 释放节点 q */
    }

    *L = NULL;
}



/** 功能描述：获取第 i(i >= 1) 个元素
 *
 *  参数说明：L 是某单链表表头节点指针，函数返回链表中第 i 个元素的节点指针，
 *             同时 *pre 将指向它的前驱，如果 i 值非法，将返回 NULL，并且 *pre
 *             将指向它的前驱。如果 i 值非法，将返回 NULL，并且 *pre 也会被设置成 NULL。
 *
 *
 *
 */

NODEPTR GetElemAt(LINKLIST L,int i,NODEPTR *pre){

    NODEPTR p;

    int k;

    p = L;                                  /* p 指向链表头节点 */

    k = 0;                                  /* 计数器 k 清 0 */

    while(k < i && p != NULL){              /* 如果没有达到链表末尾并且计数器的值 k 小于 i，就继续循环 */
                                            /* 循环过程中， *pre 一直是 p 的前驱 */
        *pre = p;                           /*  *pre 指向 p 的前驱节点 */

        p = p ->next;                       /* p 指向自己的后继 */

        k++;                                /* 计数器加 1 */
    }

    if(k < i){

        *pre = NULL;                        /* i 值非法 */
    }

    return p;

}



/** 功能描述：向单链表中增加元素
 *
 *  参数说明：将 e 添加到链表 L 中，最方便的做法就是将 e 节点插入到头节点的后面。
 *             如果成功则返回 1,否则返回 0。
 *
 *  注：采用了头插法插入元素，链表中的元素顺序会与输入顺序相反
 */

int AddElem(LINKLIST L,elemtype e){

    NODEPTR p;

    p = (NODEPTR)malloc(sizeof(NODE));    /* 为节点 e 分配节点 */

    if(p == NULL) return 0;               /* 操作失败 */

    p ->data = e;                         /* 将 e 存放到节点 p 中 */

    p ->next = L ->next;                  /* 先将 p 的后继指向头节点的后继 */

    L ->next = p;                         /* 头节点的后继指向 p */

    return 1;
}



/** 功能描述：在链表第 i(i >= 1)的位置上插入某数据元素
 *
 *  参数说明：将数据元素 e 插入 L 中第 i 的位置上，操作成功返回 1，否则返回 0。
 *
 *
 */


int InsertElemAt(LINKLIST L,elemtype e,int i){

    NODEPTR p,pre,q;

    q = (NODEPTR)malloc(sizeof(NODE));   /* 为节点 e 分配节点 */

    if(q == NULL) return 0;              /* 操作失败 */

    q ->data = e;                        /* 将数据 e 存放到节点 q 中 */

    p = GetElemAt(L,i,&pre);             /* 获取 L 中的第 i 个节点指针 p 及其前驱指针 pre ，节点将插入到 p 和 pre 之间 */

    if(pre == NULL) return 0;            /* i 值非法 */

    q ->next = p;                        /* 先将 q 的后继指向 p */

    pre ->next = q;                      /* 再将 pre 的后继指向 q  */

    return 1;
}




/** 功能描述：删除第 i(i >= 1) 个元素
 *
 *
 */

int DeleteElemAt(LINKLIST L,int i){

    NODEPTR p,pre;

    p = GetElemAt(L,i,&pre);             /* 找到要删除的节点 p 及其前驱 pre  */

    if(p == NULL) return 0;              /* i 值非法 */

    pre ->next = p ->next;               /* 删除节点 p */

    free(p);                             /* 释放节点 p */

    return 1;
}



/** 功能描述：遍历链表
 *
 *  注： L ->next 才是第一个数据节点，节点 L 是头节点，
 *       不存放有效数据。
 *
 *
 */

void TraverseLinkList(LINKLIST L){

    NODEPTR p;

    p = L ->next;                       /* p 指向 L 链表中的第一个数据点 */

    while(p){

        printf(FORMATSTR,p ->data);     /* 输出  p 的数据域 */

        p = p ->next;                   /* p 沿着 next 指针向后移动一个单元 */
    }
}


/** 功能描述：查找某个数据元素
 *
 *  参数说明：在链表 L 中查找值等于 e 的节点，返回节点指针以及
 *             该节点的前驱，如果找不到返回 NULL。
 *
 *
 *
 */

NODEPTR SearchLinkList(LINKLIST L,elemtype e,NODEPTR *pre){

    NODEPTR p;

    *pre = L;                           /* (*pre) 指向链表的头节点 */

    p = L ->next;                       /* p 指向链表的第一个数据点，这时 (*pre) 已经是 p 的前驱 */

    while(p != NULL && p ->data != e){  /* 如果 p 没有到达链表末尾并且 p 的数据域不是 e，则继续循环， */
                                        /* 在循环中，(*pre) s始终是 p 的前驱 */
        *pre = p;

        p = p ->next;                   /* p 沿着 next 指针先向后移动，移动前 (*pre) 指向 p */
    }

    if(p == NULL) return *pre = NULL;   /* 没有找到 e */

    return p;
}



/** 功能描述：删除某个特定数据元素
 *
 *  参数说明：将链表中数据域是 e 的节点删掉
 *
 *
 */


int DeleteElemLinkList(LINKLIST L,elemtype e){

    NODEPTR p,pre;

    p = SearchLinkList(L,e,&pre);      /* 查找数据域是 e 的节点及其前驱，返回节点指针 */

    if(p == NULL) return 0;            /* 操作失败，没有找到 */

    pre ->next = p ->next;             /* 删除节点 p */

    free(p);                           /* 释放节点 p */

    return 1;
}





