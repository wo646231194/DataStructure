//
// Created by hugbr on 2016/1/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Qnode;

typedef struct queue{
    Qnode *begin,*end;
}Queue;

Queue * init(){
    Queue *q = malloc(sizeof(Queue));
    Qnode *t = malloc(sizeof(Qnode));
    t->next = NULL;
    q->begin = t;
    q->end = t;
    return q;
}

int isEmpty(Queue *q){
    if(q->begin ==q->end){
        printf("waring-------����Ϊ��!!!\n");
        return 1;
    } else return 0;
}

int push(Queue *q,int x){
    Qnode *n = malloc(sizeof(Qnode));
    n->data = x;
    n->next = NULL;
    q->end->next = n;
    q->end = n;
    printf("%d�����\n",x);
    return 1;
}

int pop(Queue *q,int *x){
    if(isEmpty(q)) return 0;
    else{
        *x = q->begin->next->data;
        q->begin->next = q->begin->next->next;
        printf("%d������\n",*x);
        return 1;
    }
}

void show(Queue *q){
    isEmpty(q);
    Qnode *n;
    int i=1;
    n = q->begin->next;
    while (n!=NULL){
        printf("���еĵ�%d��Ԫ��Ϊ%d\n",i++,n->data);
        n = n->next;
    }
}

main(){
    printf("-------------\n���г�ʼ��\n");
    Queue *q = init();
    printf("-------------\n����ʼ���ɹ�\n");
    int x;
    printf("����������\n");
    scanf("%d",&x);
    while (x!=0){
        push(q,x);
        scanf("%d",&x);
    }
    show(q);
    pop(q,&x);
    pop(q,&x);
    show(q);
    printf("����������\n");
    scanf("%d",&x);
    while (x!=0){
        push(q,x);
        scanf("%d",&x);
    }
    show(q);
    pop(q,&x);
    show(q);
}