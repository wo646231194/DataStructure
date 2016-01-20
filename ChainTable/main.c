//
// Created by hugbr on 2016/1/18.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int x;
    struct LNode * next;
}*LinkList;

int flag = 0;

/*----------------------------头部插入链表---------------------------------*/
/*链表头部插入*/
LinkList init_list1(){
    LinkList L=NULL;
    LinkList T;
    int x = 1;
    scanf("%d",&x);
    while (x!=flag){
        T = malloc(sizeof(LinkList));
        T->x = x;
        T->next = L;
        L = T;//前节点
        scanf("%d",&x);
    }
    return L;
}
/*查看链表1所有元素*/
void print_list1(LinkList L){
    printf("头部插入--查看表中所有元素\n");
    LinkList T = L;
    int sum=0,i=0;
    while(T->next!=NULL){//统计个数
        sum++;
        T = T->next;
    }
    int a[sum];//初始化矩阵
    printf("共有%d个元素\n",sum+1);
    int num = sum;
    a[num--] = L->x;
    while(L->next!=NULL){
        L = L->next;
        a[num--]=L->x;
    }
    while (i<=sum){
        printf("元素为%d\n",a[i++]);
    }
}

/*------------------------------尾部插入链表-------------------------*/
/*链表尾部插入*/
LinkList init_list2(){
    LinkList L=NULL;
    LinkList T,E=NULL;
    int x=1;
    while (x!=flag){
        scanf("%d",&x);
        T = malloc(sizeof(LinkList));
        T->x = x;
        if(L==NULL) L = T;
        else E->next = T;//将新的节点放到E后面
        E = T;//将E指向新的节点
    }
    if(E!=NULL) E->next = NULL;//结束
    return L;
}
/*查看链表2所有元素*/
void print_list2(LinkList L){
    printf("尾部插入--查看表中所有元素\n");
    int i=1;
    while(L->next!=NULL){
        printf("第%d个元素为%d\n",i++,L->x);
        L = L->next;
    }
}

/*---------------------------------带头节点的尾部链表--------------------------*/
LinkList init_list3(){
    LinkList L,E;
    int x;
    L = malloc(sizeof(LinkList));
    L->next = NULL;
    E = L;
    scanf("%d",&x);
    while (x!=flag){
        E->next=malloc(sizeof(LinkList));
        E->next->x = x;
        E = E->next;
        scanf("%d",&x);
    }
    E->next = NULL;
    return L;
}
void print_list3(LinkList L){
    printf("带头节点--查看表中所有元素\n");
    int i=1;
    while (L->next!=NULL){
        L = L->next;
        printf("第%d个元素为%d\n",i++,L->x);
    }
}
/*----------------------------------获取链表长度-------------------------------*/
int getLength(LinkList L,int type){
    int i =1;
    while (L->next!=NULL){
        L = L->next;
        i++;
    }
    if(type == 3 || type==2){
        printf("链表长度为%d \n",i-1);
        return i;
    } else{
        printf("链表长度为%d \n",i);
        return i;
    }
}
/*----------------------------------按序号查找------------------------------------*/
LinkList findi(LinkList L,int i,int type){
    int j =1;
    if(type == 3){
        L = L->next;
    }
    while (L->next!=NULL){
        if(i ==j++){
            printf("第%d个元素为%d\n",i,L->x);
            return L;
        }
        L = L->next;
    }
    printf("没找到!!!\n");
    return 0;
}
/*----------------------------------按值查找------------------------------------*/
LinkList findx(LinkList L,int x){
    LinkList N = L->next;
    while (N->next!=NULL ){
        if(N->x ==x){
            printf("找到了,元素为%d \n",N->x);
            return N;
        }
        N = N->next;
    }
    printf("没有找到\n");
    return 0;
}
/*------------------------------插入：前插---------------------------*/
int insert_before(LinkList L,int i, int x){
    printf("在第%d个位置前插入%d\n",i,x);
    int j = 1;
    LinkList T;
    while (L->next!=NULL){
        if(i==j++){
            T = malloc(sizeof(LinkList));
            T -> x = x;
            T->next = L->next;
            L->next = T;
        }
        L=L->next;
    }
    return 1;
}
/*------------------------------插入：后插---------------------------*/
int insert_after(LinkList L,int i, int x){
    printf("在第%d个位置后插入%d\n",i,x);
    int j = 1;
    LinkList T;
    while (L->next!=NULL){
        L=L->next;
        if(i==j++){
            T = malloc(sizeof(LinkList));
            T -> x = x;
            T->next = L->next;
            L->next = T;
        }
    }
    return 1;
}
/*-------------------------------删除------------------------------*/
int delete(LinkList L, int i){
    printf("删除第%d个元素\n",i);
    int j = 1;
    LinkList T;
    while (L->next!=NULL){
        if(i==j++){
            T = L->next;
            L->next = T->next;
            free(T);
            return 1;
        }
        L=L->next;
    }
    return 1;
}
/*---------------------------链表倒置-------------------------------*/
LinkList reverse(LinkList H){
    printf("++++链表倒置++++\n");
    LinkList E,T,tmp=NULL;
    int j=1;
    E = H->next;
    while (E){
        T = malloc(sizeof(LinkList));
        T->x = E->x;
        T->next = tmp;
        tmp = T;
        E = E->next;
        H->next = T;
    }
    return H;
}
/*---------------------------链表去重复-----------------------------*/
LinkList redundant(LinkList H){
    printf("++++链表去重复++++\n");
    LinkList E,T,r;
    E = H->next;
    while (E->next!=NULL){
        T = E;
        while (T->next!=NULL){
            if(E->x == T->next->x){
                r = T->next;
                T->next = r->next;
                free(r);
            } else{
                T = T->next;
            }
        }
        E = E->next;
    }
    return H;
}

/*--------------------------------------主函数-----------------------------*/
void main(){
//    printf("------------------------\n开始头部插入\n");
//    LinkList L1 = init_list1(); //初始化
//    print_list1(L1); //显示所有元素
//    getLength(L1,1); //获取链表长度
//    findi(L1,1,1); //按序号查找
//    printf("头部插入结束\n------------------------\n\n");
//
//    printf("------------------------\n开始尾部插入\n");
//    LinkList L2 = init_list2(); //初始化
//    print_list2(L2); //显示所有元素
//    getLength(L2,2); //获取链表长度
//    findi(L2,1,2); //按序号查找
//    printf("尾部插入结束\n------------------------\n\n");

    printf("------------------------\n带头节点的链表\n");
    LinkList L3 = init_list3();
    print_list3(L3);
    getLength(L3,3);
    findi(L3,1,3); //按序号查找
    findx(L3,34); //按值查找
    insert_before(L3,1,34); //前插
    print_list3(L3); //显示
    insert_after(L3,1,99); //后插
    print_list3(L3); //显示
    findx(L3,34); //按值查找
    delete(L3,1);
    print_list3(L3); //显示
    reverse(L3);
    print_list3(L3);
    redundant(L3);
    print_list3(L3);
    printf("带头节点链表结束\n------------------------\n\n");
}