//
// Created by hugbr on 2016/1/25.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node * lchild,* rchild;
}Node,* Btree;

//初始化一个空节点
Btree init(){
    Btree b = malloc(sizeof(Btree));
    b->lchild = NULL;
    b->rchild = NULL;
    return b;
}
Btree initx(char x){
//    printf("准备开辟空间\n");
    Btree b = malloc(sizeof(Btree));
//    printf("开辟空间成功\n");
    b->data = x;
    b->lchild = NULL;
    b->rchild = NULL;
    return b;
}
//生成节点
Btree create(char x,Btree lt,Btree rt){
    Btree b = malloc(sizeof(Btree));
    b->data = x;
    b->lchild = lt;
    b->rchild = rt;
    return b;
}
//返回数据元素为x 的节点
//树根b 目标节点r 数据元素x
void find(Btree b,Btree * r,char x){
    if(b == NULL) return;
    find(b->lchild,r,x);
    find(b->rchild,r,x);
    if(x == b->data) * r = b;
}

//数据元素为x的节点作为父节点，插入d
Btree insertL(Btree b, Btree t, char d){
//    printf("准备左插入%c\n",d);
    if(t->lchild!=NULL){
        t->lchild->data = d;
    } else{
        Btree n = initx(d);
//        printf("初始化新的节点成功\n");
        t->lchild = n;
    }
    printf("%c左插入%c成功\n",t->data,d);
    return b;
}
Btree insertR(Btree b, Btree t, char d){
//    printf("准备右插入%c\n",d);
    if(t->rchild!=NULL){
        t->rchild->data = d;
    } else{
        Btree n = initx(d);
//        printf("初始化新的节点成功\n");
        t->rchild = n;
    }
    printf("%c右插入%c成功\n",t->data,d);
    return b;
}
Btree deleteL(Btree b,Btree t){
    printf("删除%c左节点%c\n",t->data,t->lchild->data);
    t->lchild = NULL;
    return b;
}
Btree deleteR(Btree b,Btree t){
    printf("删除%c右节点%c\n",t->data,t->rchild->data);
    t->rchild = NULL;
    return b;
}

//先序遍历
void showl(Btree b){
    if(b==NULL) return;
    printf("%c",b->data);
    showl(b->lchild);
    showl(b->rchild);
}
//中序遍历
void showm(Btree b){
    if(b==NULL) return;
    showm(b->lchild);
    printf("%c",b->data);
    showm(b->rchild);
}
//后序遍历
void showr(Btree b){
    if(b==NULL) return;
    showr(b->lchild);
    showr(b->rchild);
    printf("%c",b->data);
}
//树深度
int high(Btree b){
    int lh,rh,h;
    if(b==NULL) h=0;
    else{
        lh = high(b->lchild);
        rh = high(b->rchild);
        h=(lh>rh?lh:rh)+1;
    }
    return h;
}
//层次遍历
void show(Btree b){
    int num= 2^high(b);
    Btree a[num],t;
    int front=-1,end=0;
    a[end] = b;
    while (front!=end){
        t = a[++front];
        printf("%c",t->data);
        if(t->lchild!=NULL){
            a[++end] = t->lchild;
        }
        if(t->rchild!=NULL){
            a[++end] = t->rchild;
        }
    }
}
int countleaf(Btree b){
    if(b==NULL) return 0;
    else{
        if(b->lchild==NULL && b->rchild==NULL) return 1;
        else return countleaf(b->lchild)+countleaf(b->rchild);
    }
}

main(){
    printf("--------初始化二叉树--------\n");
    Btree a = initx('A');
    printf("--------初始化成功--------\n");
    a = insertL(a,a,'B');
    a = insertR(a,a,'C');
    showl(a);printf("\n");
    a = insertL(a,a->lchild,'D');
    a = insertR(a,a->lchild,'E');
    showl(a);printf("\n");
    showm(a);printf("\n");
    showr(a);printf("\n");
    Btree c = init();
    find(a,&c,'C');
    insertL(a,c,'F');
    showl(a);printf("\n");
    showm(a);printf("\n");
    showr(a);printf("\n");
    Btree f = init();
    find(a,&f,'F');
    insertR(a,f,'G');
    showl(a);printf("\n");
    Btree e = init();
    find(a,&e,'E');
    insertL(a,e,'X');
    showl(a);printf("\n");
    int h = high(a);
    printf("树深度为%d\n",h);
    printf("层次遍历为:\n");
    show(a);printf("\n");
    printf("叶子节点有%d\n",countleaf(a));
    Btree b;
    find(a,&b,'B');
    deleteL(a,b);
    show(a);printf("\n");

    Btree p = initx('P');
    Btree link1 = create('O',a,p);
    show(link1);printf("\n");
    Btree link2 = create('O',p,a);
    show(link2);printf("\n");
    int x;
    scanf("%d",&x);
}