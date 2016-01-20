//
// Created by hugbr on 2016/1/18.
//
#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10000

typedef struct {
    int data[MAX_NUM];
    int last;
}List;

//初始化L->last=-1
List * init(){
    List * L;
    L = malloc(sizeof(List));//开辟空间
    L->last = -1;
    printf("初始化成功\n");
    return L;
}
/**
 * 线性表L第i个元素插入x
 * @param List L,int i,int x
 * 时间复杂度 n/2
 * */
int insert(List * L,int i,int x){
    int j;
    if(L->last > MAX_NUM-1){
        printf("表满了\n");
        return (-1);
    }
    if(i<1 || i>L->last+2){
        printf("插入位置不正确\n");
        return (0);
    }
    for(j=L->last; j>i-2;j--){
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = x;
    printf("第%d个位置插入%d \n",i,x);
    L->last++;
    printf("表长度为%d \n",L->last+1);
    return 1;
}

/*删除线性表L 的第 i 个元素*/
int delete(List * L,int i){
    int j;
    if(i<1 || i>L->last+2){
        printf("表满了\n");
        return (0);
    }
    printf("删除第%d个位置的元素%d\n",i,L->data[i-1]);
    for(j=i;j<=L->last;j++){
        L->data[j-1] = L->data[j];
    }
    L->last--;
    return 1;
}

/*找出线性表L中的元素x*/
int find(List * L,int x){
    int j;
    for(j=0;j<=L->last;j++){
        if(x==L->data[j]){
            printf("找到了,%d元素在第%d个位置\n",x,j+1);
            return j;
        }
    }
    printf("没有找到 %d\n",x);
    return -1;
}

/*得到线性表第i个元素*/
int get(List * L,int i){
    printf("获取表的第%d个元素为%d",i,L->data[i-1]);
    return L->data[i-1];
}

/*显示线性表L中所有元素*/
void show(List *L){
    int j;
    printf("显示表所有元素:\n");
    for(j=0;j<=L->last;j++){
        printf("第%d个位置的元素为%d\n",j+1,L->data[j]);
    }
}

void sort(List *L, int type){
    int i,j,temp;
    if(type) {
        for (i = 0; i < L->last; i++) {
            for (j = i + 1; j <= L->last; j++) {
                if (L->data[i] > L->data[j]) {
                    temp = L->data[j];
                    L->data[j] = L->data[i];
                    L->data[i] = temp;
                }
            }
        }
    } else{
        for (i = 0; i < L->last; i++) {
            for (j = i + 1; j <= L->last; j++) {
                if (L->data[i] < L->data[j]) {
                    temp = L->data[j];
                    L->data[j] = L->data[i];
                    L->data[i] = temp;
                }
            }
        }
    }
    show(L);
}

void merge(List *L1,List *L2,List *L3){
    int i=0,j=0,k=0;
    if(i<L1->last && i<L2->last){
        if(L1->data[i]<L2->data[i])
            L3->data[k++] = L1->data[i++];
        else
            L3->data[k++] = L2->data[j++];
    }
    while (i<L1->last){
        L3->data[k++] = L1->data[i++];
    }
    while (j<L2->last){
        L3->data[k++] = L2->data[j++];
    }
    L3->last = k-1;
}

main(){
    List * L;
    L = init();
    printf("----------------------------------------\n插入元素\n");
    insert(L,1,99);
    insert(L,1,-12);
    insert(L,2,32);
    insert(L,1,250);
    show(L);
    printf("----------------------------------------\n排序\n");
    sort(L,1);//从小到大
    sort(L,0);//从大到小
    printf("----------------------------------------\n删除元素\n");
    delete(L,2);
    show(L);
    printf("----------------------------------------\n查找元素\n");
    find(L,1);
    find(L,32);
    printf("----------------------------------------\n获取元素\n");
    get(L,2);
}
