//
// Created by hugbr on 2016/1/21.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000

typedef struct{
    int data[MAX_NUM];
    int top;
}StackList;

StackList * init(){
    StackList *s ;
    s = malloc(sizeof(StackList));
    s->top = -1;
    return s;
}

int isEmpty(StackList * s){
    if(s->top == -1) return 1;
    return 0;
}

int show(StackList *s){
    if(isEmpty(s)) return 0;
    else{
        int i = s->top;
        while (i>=0){
            printf("第%d个元素为%d\n",i+1,s->data[i]);
            i--;
        }
        return 1;
    }
}

int push(StackList *s,int x){
    if(s->top>MAX_NUM-1) return 0;
    else {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

int pop(StackList *s,int * x){
    if(isEmpty(s)) return 0;
    else{
        *x = s->data[s->top--];
        return 1;
    }
}

int get(StackList *s,int *x){
    if(isEmpty(s)) return 0;
    else{
        *x = s->data[s->top];
        return 1;
    }
}

int flag = 0;

main(){
    printf("-------------\n栈初始化\n");
    StackList *L = init();
    printf("-------------\n栈初始化成功\n");
    int x;
    printf("请入栈\n");
    scanf("%d",&x);
    while (x!=flag){
        push(L,x);
        scanf("%d",&x);
    }
    show(L);
    get(L,&x);//读取栈顶
    printf("栈顶元素为 %d\n\n",x);
    pop(L,&x);
    printf("出栈元素为 %d\n\n",x);
    show(L);
    pop(L,&x);
    printf("出栈元素为 %d\n\n",x);
    show(L);
}