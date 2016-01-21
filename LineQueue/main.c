//
// Created by hugbr on 2016/1/21.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000

typedef struct node{
    int data[MAX_NUM];
    int begin,end,num;
}Queue;

Queue * init(){
    Queue * q = malloc(sizeof(Queue));
    q->begin = -1;
    q->end = -1;
    q->num = 0;
    return q;
}

int isEmpty(Queue *q){
    if(q->num == 0) {
        printf("����Ϊ��!\n");
        return 1;
    }
    else return 0;
}

int push(Queue *q ,int x){
    if(q->end > MAX_NUM-1) return 0;
    else{
        q->end++;
        q->data[q->end] = x;
        q->num++;
        return 1;
    }
}

int pop(Queue *q,int * x){
    if(isEmpty(q)) return 0;
    else{
        *x = q->data[++q->begin];
        q->num--;
        printf("%d������\n",*x);
        return 1;
    }
}

void show(Queue *q){
    int j=1, i = q->begin+1;
    while (i<=q->end){
        printf("�����е�%d��Ԫ��Ϊ%d\n",j++,q->data[i++]);
    }
}
int flag = 0;
main(){
    printf("-------------\n���г�ʼ��\n");
    Queue *q = init();
    printf("-------------\n����ʼ���ɹ�\n");
    int x;
    printf("����������\n");
    scanf("%d",&x);
    while (x!=flag){
        push(q,x);
        scanf("%d",&x);
    }
    show(q);
    pop(q,&x);
    pop(q,&x);
    show(q);
    printf("����������\n");
    scanf("%d",&x);
    while (x!=flag){
        push(q,x);
        scanf("%d",&x);
    }
    show(q);
}
