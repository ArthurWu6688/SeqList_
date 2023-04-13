#include "SeqList.h"

int main(){
    SeqList mylist;
    InitList(&mylist);

    SeqList_ElemType item,key,index,pos;

    int select=1;
    while(select){
        printf("*********************************************\n");
        printf("*     [1]push_back        [2]push_front     *\n");
        printf("*     [3]show_list        [0]quit_system    *\n");
        printf("*     [4]pop_back         [5]pop_front      *\n");
        printf("*     [6]insert_pos       [7]insert_val     *\n");
        printf("*     [8]delete_pos       [9]delete_val     *\n");
        printf("*     [10]find            [11]reverse       *\n");
        printf("*     [12]sort            [13]length        *\n");
        printf("*     [14]capacity        [15]clear         *\n");
        printf("*********************************************\n");
        printf("请选择:>");
        scanf("%d",&select);

        if(select==0)
            break;

        switch(select){
            case 1:
                printf("请输入要插入的数据:>");
                while(scanf("%d",&item),item!=-1){
                    SeqListPushBack(&mylist,item);
                }
                break;
            case 2:
                printf("请输入要插入的数据:>");
                while(scanf("%d",&item),item!=-1){
                    SeqListPushFront(&mylist,item);
                }
                break;
            case 3:
                SeqListShow(&mylist);
                break;
            case 4:
                SeqListPopBack(&mylist);
                break;
            case 5:
                SeqListPopFront(&mylist);
                break;
            case 6:
                printf("请输入要插入的位置:>");
                scanf("%d",&pos);
                printf("请输入要插入的值:>");
                scanf("%d",&item);
                SeqListInsertByPos(&mylist,pos,item);
                break;
            case 7:
                printf("请输入要插入的值:>");
                scanf("%d",&item);
                SeqListInsertByVal(&mylist,item);
                break;
            case 8:
                printf("请输入要删除元素的下标:>");
                scanf("%d",&pos);
                SeqListDeleteByPos(&mylist,pos);
                break;
            case 9:
                printf("请输入要删除的数据:>");
                scanf("%d",&key);
                SeqListDeleteByVal(&mylist,key);
                break;
            case 10:
                printf("请输入要查找的数据:>");
                scanf("%d",&key);
                index=SeqListFind(&mylist,key);
                if(index==-1){
                    printf("没有找到该数据\n");
                }else{
                    printf("找到了该数据，下标是%d\n",index);
                }
                break;
            case 11:
                SeqListReverse(&mylist);
                break;
            case 12:
                SeqListSort(&mylist);
                break;
            case 13:
                printf("length=%lu\n",SeqListLength(&mylist));
                break;
            case 14:
                printf("capacity=%lu\n",SeqListCapacity(&mylist));
                break;
            case 15:
                SeqListClear(&mylist);
                break;
            default:
                break;
        }
    }
    SeqListDestroy(&mylist);
    return 0;
}