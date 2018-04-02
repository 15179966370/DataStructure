#include <stdio.h>
#include <stdlib.h>

#include "../Headers/SequenceList.h"










/** 功能描述： L 指向要初始化的顺序表，
 *             n 顺序表的容量
 *
 *             如果初始化成功返回 1，否则返回 0
 *
 */

int InitSqlist(SQLIST *L,int n){

    L ->elem = (elemtype *)malloc(n * sizeof(elemtype));   /* 为 elem 分配数组 */

    if(L ->elem == NULL) return 0;                         /* 分配不到内存，初始化失败 */

    L ->size = n;                                           /* 设置顺序表容量 */

    L ->len = 0;                                            /* 初始化为空表 */

    return 1;
}



/** 功能描述： 销毁顺序表
 *
 */

void DestorySqlist(SQLIST *L){

    free(L ->elem);                 /* 释放 elem 所指向的内存块 */

    L ->elem = NULL;

    L ->size = 0;

    L ->len = 0;
}


/** 功能描述：如果顺序表 L 已经达到其最大长度，返回 1，否则返回 0
 *
 *
 */

int IsSqlistFull(SQLIST L){

    return L.len == L.size;
}


/** 功能描述：如果顺序表 L 是空表，返回 1，否则返回 0
 *
 *
 */

int IsSqlistEmpty(SQLIST L){

    return L.len == 0;
}



/** 功能描述： 如果顺序表未满，把元素 e 添加到顺序表的末尾，
 *             由于顺序表的长度会发生变化，所以 L 被设置成
 *             指针型参数。添加成功返回 1，否则返回 0。
 *
 *
 */

int AppendElem(SQLIST *L,elemtype e){

    if(IsSqlistFull(*L)) return 0;      /* 顺序表已满 */

    L ->elem[L ->len] = e;              /* 将 e 添加到表尾 */

    L ->len++;                          /* 顺序表长度增加 1 */

    return 1;
}


/** 功能描述：在顺序表中 i(i >= 0)的位置上插入数据元素
 *
 *
 *
 */


int InsertElem(SQLIST *L,elemtype e,int i){

    int k;

    if(i > L ->len ||IsSqlistFull(*L))      /* i 值不合法或顺序表已满，则操作失败 */

        return 0;

    for(k = L ->len - 1;k >= i;k--){        /* 将[i..len - 1]区间的数据元素向后移动一个单元，以便使 e 能够 */
                                            /* 插入到  i 的位置上。 */
        L ->elem[k + 1] = L ->elem[k];
    }

    L ->elem[i] = e;                        /* 将 e 插入到正确的位置上 */

    L ->len++;                              /* 顺序表长度增 1 */

    return 1;
}



/** 功能描述：删除顺序表中 i(i >= 0) 位置上的元素
 *
 */


int DeleteElemSqlist(SQLIST *L,int i){

    int k;

    if(i >= L ->len || IsSqlistEmpty(*L))      /* i 值非法或者顺序表已空，操作失败 */

        return 0;

    for(k = i + 1;k < L ->len;k++){            /* 将[i..len - 1]区间的数据元素向前移动一个单元*/

        L ->elem[k - 1] = L ->elem[k];
    }

    L ->len--;

    return 1;
}


/** 功能描述：遍历整个顺序表，将元素逐个输出
 *
 */

void TraverseSqlist(SQLIST L){

    int i;

    for(i = 0;i < L.len;i++){          /* 依次访问所有的数据元素 */

        printf(FORMATSTR,L.elem[i]);
    }
}


/** 功能描述：在顺序表中查找某个数据元素。
 *            如果找到则返回该数据元素的下标，否则返回 -1
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


