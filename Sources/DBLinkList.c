#include <stdio.h>
#include <stdlib.h>

#include "../Headers/DBLinkList.h"




/** 功能描述： 删除双向链表的某个节点
 *
 *  参数说名：p 是某双向链表中的节点，将 p 从链表中删除并释放节点内存
 *
 *  注：双向链表删除操作需要修改 2 个指针域
 *
 */


void DeleteElemDBLinkList(DBNODEPTR p){

    DBNODEPTR pre;

    pre = p ->proir;                       /* pre 指向 p 的前驱 */

    if(pre != NULL)

        pre ->next = p ->next;             /* pre 的后继指向 p 后面的节点*/

    if(p ->next != NULL)

        p ->next ->proir = pre;            /* p 的前驱指向 pre */

    free(p);                               /* 释放 p 节点内存 */
}



/** 功能描述：将元素插入到双向链表中节点  p  的后面。
 *
 *  参数说明：将元素 e 插入到某双向链表中节点 p 的后面。
 *
 *  注1：双向链表插入元素需要修改 4 个指针域。
 *
 *  注2：这类操作本着 “先接后拆” 的顺序原则。
 *
 *
 */


int InsertElemAfterDB(DBNODEPTR p,elemtype e){

    DBNODEPTR q;

    q = (DBNODEPTR)malloc(sizeof(DBNDOE));  /* 分配节点 */

    if(q == NULL) return 0;

    q ->data = e;

    q ->next = p ->next;

    q ->proir = p;

    if(p ->next != NULL)

        p ->next ->proir = q;

    p ->next = q;

    return 1;
}

