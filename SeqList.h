//
// Created by 吴映鹏 on 2023/4/10.
//

#ifndef SEQLIST_SEQLIST_H
#define SEQLIST_SEQLIST_H

#include "common.h"
#define SEQLIST_DEFAULT_SIZE 8
#define SeqList_ElemType int
#define SEQLIST_INC_SIZE 3

typedef struct{
    SeqList_ElemType *base;//顺序表的空间指针
    size_t capacity;       //顺序表的容量
    size_t size;           //顺序表的元素个数
}SeqList;

//函数声明
void InitList(SeqList *pst);
void SeqListPushBack(SeqList *pst,SeqList_ElemType value);
void SeqListShow(SeqList *pst);
void SeqListPushFront(SeqList *pst,SeqList_ElemType value);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList *pst);
int SeqListFind(SeqList *pst,SeqList_ElemType key);
void SeqListDeleteByVal(SeqList *pst,SeqList_ElemType key);
size_t SeqListLength(SeqList *pst);
size_t SeqListCapacity(SeqList *pst);
void SeqListInsertByPos(SeqList *pst,int pos,SeqList_ElemType value);
void SeqListInsertByVal(SeqList *pst,SeqList_ElemType value);
void SeqListDeleteByPos(SeqList *pst,int pos);
void SeqListClear(SeqList *pst);
void SeqListReverse(SeqList *pst);
void SeqListSort(SeqList *pst);
void SeqListDestroy(SeqList *pst);


//辅助函数，以下划线打头
bool _SeqListIsFull(SeqList *pst){
    assert(pst!=NULL);
    return pst->size>=pst->capacity;
}

bool _SeqListIsEmpty(SeqList *pst){
    assert(pst!=NULL);
    return pst->size==0;
}

void _swap(SeqList_ElemType *left,SeqList_ElemType *right){
    SeqList_ElemType temp = *left;
    *left = *right;
    *right = temp;
}

bool _SeqListInc(SeqList *pst){
    assert(pst != NULL);
    SeqList_ElemType* temp = (SeqList_ElemType*)realloc(pst->base,sizeof(SeqList_ElemType)*(pst->capacity+SEQLIST_INC_SIZE));

    if(temp == NULL){
        printf("内存不足，扩容失败\n");
        return false;
    }
    pst->base=temp;
    pst->capacity+=SEQLIST_INC_SIZE;
    return true;
}





//函数定义
void InitList(SeqList *pst){
    assert(pst!=NULL);
    pst->base=(SeqList_ElemType*)malloc(sizeof(SeqList_ElemType)*SEQLIST_DEFAULT_SIZE);
    assert(pst->base!=NULL);
    pst->capacity=SEQLIST_DEFAULT_SIZE;
    pst->size=0;
}

void SeqListPushBack(SeqList *pst,SeqList_ElemType value){
    assert(pst!=NULL);
    if(_SeqListIsFull(pst) && !_SeqListInc(pst)){
        printf("顺序表已满，这个数据不能尾部插入!\n");
        return;
    }
    pst->base[pst->size++]=value;
}

void SeqListShow(SeqList *pst){
    assert(pst);
    for(int i=0;i<pst->size;++i){
        printf("%d ",pst->base[i]);
    }
    printf("\n");
}

void SeqListPushFront(SeqList *pst,SeqList_ElemType value){
    assert(pst!=NULL);
    if(_SeqListIsFull(pst) && !_SeqListInc(pst)){
        printf("顺序表已满，这个数据不能头部插入!\n");
        return;
    }
    for(int i=pst->size;i>0;--i){
        pst->base[i]=pst->base[i-1];
    }
    pst->base[0]=value;
    ++pst->size;
}

void SeqListPopBack(SeqList *pst){
    assert(pst!=NULL);
    if(_SeqListIsEmpty(pst)){
        printf("顺序表已空，不能尾部删除\n");
        return;
    }
    --pst->size;
}

void SeqListPopFront(SeqList *pst){
    assert(pst!=NULL);
    if(_SeqListIsEmpty(pst)){
        printf("顺序表已空，不能头部删除\n");
        return;
    }
    for(int i=1;i<pst->size;++i){
        pst->base[i-1]=pst->base[i];
    }
    --pst->size;
}

int SeqListFind(SeqList *pst,SeqList_ElemType key){
    assert(pst!=NULL);
    for(int i=0;i<pst->size;++i){
        if(pst->base[i]==key){
            return i;
        }
    }
    return -1;
}

void SeqListDeleteByVal(SeqList *pst,SeqList_ElemType key){
    assert(pst!=NULL);
    int ret=SeqListFind(pst,key);
    if(ret==-1)
        return;
    for(int i=ret;i<pst->size-1;++i){
        pst->base[i]=pst->base[i+1];
    }
    --pst->size;
}

size_t SeqListLength(SeqList *pst){
    assert(pst!=NULL);
    return pst->size;
}

size_t SeqListCapacity(SeqList *pst){
    assert(pst!=NULL);
    return pst->capacity;
}

void SeqListInsertByPos(SeqList *pst,int pos,SeqList_ElemType value){
    assert(pst);
    if(((pos<0||pos>pst->size)|| _SeqListIsFull(pst))&&!_SeqListInc(pst))
        return;
    for(int i=pst->size;i>pos;--i){
        pst->base[i]=pst->base[i-1];
    }
    pst->base[pos]=value;
    ++pst->size;
}

//这是我自己的想法，双重for实现
//void SeqListInsertByVal(SeqList *pst,SeqList_ElemType value) {
//    assert(pst);
//    if (_SeqListIsFull(pst))
//        return;
//    int i, j;
//    for (i = 0; i < pst->size; ++i) {
//        if (value < pst->base[i]) {
//            for (j = pst->size; j > i; --j) {
//                pst->base[j] = pst->base[j - 1];
//            }
//            pst->base[j] = value;
//            ++pst->size;
//            return;
//        }
//    }
//    pst->base[pst->size] = value;
//    ++pst->size;
//}

//这是老师的解法
void SeqListInsertByVal(SeqList *pst,SeqList_ElemType value){
    assert(pst!=NULL);
    int i;
    for(i=pst->size;i>=0;--i){
        if(value>pst->base[i-1])
            break;
        pst->base[i]=pst->base[i-1];
    }
    pst->base[i]=value;
    ++pst->size;
}

void SeqListDeleteByPos(SeqList *pst,int pos){
    assert(pst!=NULL);
    if(pos<0 || pos>=pst->size){
        printf("删除的位置非法\n");
        return;
    }
    for(int i=pos;i<pst->size-1;++i){
        pst->base[i]=pst->base[i+1];
    }
    --pst->size;
}

void SeqListClear(SeqList *pst){
    assert(pst != NULL);
    pst->size = 0;
}

void SeqListReverse(SeqList *pst){
    assert(pst != NULL);
    int left =0,right = pst->size-1;
    while(left < right){
        _swap(&pst->base[left],&pst->base[right]);
        ++left;
        --right;
    }
}

void SeqListSort(SeqList *pst){
    for(int i=0;i<pst->size-1;++i){
        for(int j=0;j<pst->size-1-i;++j){
            if(pst->base[j]>pst->base[j+1]){
                _swap(&pst->base[j],&pst->base[j+1]);
            }
        }
    }
}

void SeqListDestroy(SeqList *pst){
    assert(pst != NULL);
    if(pst->base != NULL){
        free(pst->base);
        pst->size=pst->capacity=0;
    }
}

#endif //SEQLIST_SEQLIST_H
