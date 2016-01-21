//
// Created by hugbr on 2016/1/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}*Stack;

Stack init(){
    Stack s = NULL;
    return s;
}

int isEmpty(Stack s){
    if(s == NULL) return 1;
    else return 0;
}

Stack push(Stack s,int x){
    Stack T = malloc(sizeof(Stack));
    T->data = x;
    T->next = s;
    s = T;
    return s;
}

Stack pop(Stack s, int *x){
    if(isEmpty(s)) return 0;
    else{
        Stack t;
        *x = s->data;
        t = s;
        s = s->next;
        return s;
    }
}

int show(Stack s){
    if(isEmpty(s)) return 0;
    else{
        int j=1;
        while (s!=NULL){
            printf("�Զ����µ�%d��Ԫ��Ϊ%d\n",j++,s->data);
            s = s->next;
        }
        return 1;
    }
}

int get(Stack s,int *x){
    if (isEmpty(s)) return 0;
    else{
        *x = s->data;
        return 1;
    }
}

int flag = 0;

main(){
    printf("-------------\nջ��ʼ��\n");
    Stack L = init();
    printf("-------------\nջ��ʼ���ɹ�\n");
    int x;
    printf("����ջ\n");
    scanf("%d",&x);
    while (x!=flag){
        L = push(L,x);
        scanf("%d",&x);
    }
    show(L);
    get(L,&x);//��ȡջ��
    printf("ջ��Ԫ��Ϊ %d\n\n",x);
    L = pop(L,&x);
    printf("��ջԪ��Ϊ %d\n\n",x);
    show(L);
    L = pop(L,&x);
    printf("��ջԪ��Ϊ %d\n\n",x);
    show(L);
}