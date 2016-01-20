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
    printf("��ͷ�ڵ�--�鿴��������Ԫ��\n");
    int i=1;
    while (L->next!=NULL){
        L = L->next;
        printf("��%d��Ԫ��Ϊ%d\n",i++,L->x);
    }
}
/*----------------------------------��ȡ������-------------------------------*/
int getLength(LinkList L,int type){
    int i =1;
    while (L->next!=NULL){
        L = L->next;
        i++;
    }
    if(type == 3 || type==2){
        printf("������Ϊ%d \n",i-1);
        return i;
    } else{
        printf("������Ϊ%d \n",i);
        return i;
    }
}
/*----------------------------------����Ų���------------------------------------*/
LinkList findi(LinkList L,int i,int type){
    int j =1;
    if(type == 3){
        L = L->next;
    }
    while (L->next!=NULL){
        if(i ==j++){
            printf("��%d��Ԫ��Ϊ%d\n",i,L->x);
            return L;
        }
        L = L->next;
    }
    printf("û�ҵ�!!!\n");
    return 0;
}
/*----------------------------------��ֵ����------------------------------------*/
LinkList findx(LinkList L,int x){
    LinkList N = L->next;
    while (N->next!=NULL ){
        if(N->x ==x){
            printf("�ҵ���,Ԫ��Ϊ%d \n",N->x);
            return N;
        }
        N = N->next;
    }
    printf("û���ҵ�\n");
    return 0;
}
/*------------------------------���룺ǰ��---------------------------*/
int insert_before(LinkList L,int i, int x){
    printf("�ڵ�%d��λ��ǰ����%d\n",i,x);
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
/*------------------------------���룺���---------------------------*/
int insert_after(LinkList L,int i, int x){
    printf("�ڵ�%d��λ�ú����%d\n",i,x);
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
/*-------------------------------ɾ��------------------------------*/
int delete(LinkList L, int i){
    printf("ɾ����%d��Ԫ��\n",i);
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
/*---------------------------������-------------------------------*/
LinkList reverse(LinkList H){
    printf("++++������++++\n");
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
/*---------------------------����ȥ�ظ�-----------------------------*/
LinkList redundant(LinkList H){
    printf("++++����ȥ�ظ�++++\n");
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

/*--------------------------------------������-----------------------------*/
void main(){
//    printf("------------------------\n��ʼͷ������\n");
//    LinkList L1 = init_list1(); //��ʼ��
//    print_list1(L1); //��ʾ����Ԫ��
//    getLength(L1,1); //��ȡ������
//    findi(L1,1,1); //����Ų���
//    printf("ͷ���������\n------------------------\n\n");
//
//    printf("------------------------\n��ʼβ������\n");
//    LinkList L2 = init_list2(); //��ʼ��
//    print_list2(L2); //��ʾ����Ԫ��
//    getLength(L2,2); //��ȡ������
//    findi(L2,1,2); //����Ų���
//    printf("β���������\n------------------------\n\n");

    printf("------------------------\n��ͷ�ڵ������\n");
    LinkList L3 = init_list3();
    print_list3(L3);
    getLength(L3,3);
    findi(L3,1,3); //����Ų���
    findx(L3,34); //��ֵ����
    insert_before(L3,1,34); //ǰ��
    print_list3(L3); //��ʾ
    insert_after(L3,1,99); //���
    print_list3(L3); //��ʾ
    findx(L3,34); //��ֵ����
    delete(L3,1);
    print_list3(L3); //��ʾ
    reverse(L3);
    print_list3(L3);
    redundant(L3);
    print_list3(L3);
    printf("��ͷ�ڵ��������\n------------------------\n\n");
}