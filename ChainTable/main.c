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

/*----------------------------ͷ����������---------------------------------*/
/*����ͷ������*/
LinkList init_list1(){
    LinkList L=NULL;
    LinkList T;
    int x = 1;
    scanf("%d",&x);
    while (x!=flag){
        T = malloc(sizeof(LinkList));
        T->x = x;
        T->next = L;
        L = T;//ǰ�ڵ�
        scanf("%d",&x);
    }
    return L;
}
/*�鿴����1����Ԫ��*/
void print_list1(LinkList L){
    printf("ͷ������--�鿴��������Ԫ��\n");
    LinkList T = L;
    int sum=0,i=0;
    while(T->next!=NULL){//ͳ�Ƹ���
        sum++;
        T = T->next;
    }
    int a[sum];//��ʼ������
    printf("����%d��Ԫ��\n",sum+1);
    int num = sum;
    a[num--] = L->x;
    while(L->next!=NULL){
        L = L->next;
        a[num--]=L->x;
    }
    while (i<=sum){
        printf("Ԫ��Ϊ%d\n",a[i++]);
    }
}

/*------------------------------β����������-------------------------*/
/*����β������*/
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
        else E->next = T;//���µĽڵ�ŵ�E����
        E = T;//��Eָ���µĽڵ�
    }
    if(E!=NULL) E->next = NULL;//����
    return L;
}
/*�鿴����2����Ԫ��*/
void print_list2(LinkList L){
    printf("β������--�鿴��������Ԫ��\n");
    int i=1;
    while(L->next!=NULL){
        printf("��%d��Ԫ��Ϊ%d\n",i++,L->x);
        L = L->next;
    }
}

/*---------------------------------��ͷ�ڵ��β������--------------------------*/
LinkList init_list3(){

}

/*--------------------------------------������-----------------------------*/
void main(){
    printf("------------------------\n��ʼͷ������\n");
    LinkList L1 = init_list1();
    print_list1(L1);
    printf("ͷ���������\n------------------------\n\n");
    printf("------------------------\n��ʼβ������\n");
    LinkList L2 = init_list2();
    print_list2(L2);
    printf("β���������\n------------------------\n\n");
}