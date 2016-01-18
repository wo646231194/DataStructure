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
        T->next = L;
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

}

/*--------------------------------------主函数-----------------------------*/
void main(){
    printf("------------------------\n开始头部插入\n");
    LinkList L1 = init_list1();
    print_list1(L1);
    printf("头部插入结束\n------------------------\n\n");
    printf("------------------------\n开始尾部插入\n");
    LinkList L2 = init_list2();
    print_list2(L2);
    printf("尾部插入结束\n------------------------\n\n");
}