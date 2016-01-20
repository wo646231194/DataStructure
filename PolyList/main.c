//
// Created by hugbr on 2016/1/20.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode{
    int coef;
    int exp;
    struct PolyNode *next;
}PolyNode, * PolyList;

int flag = 0;

PolyList create(){
    PolyList T,E,L;
    L = malloc(sizeof(PolyList));
    T = L;
    int c,e;
    printf("请输入系数和指数\n");
    scanf("%d,%d",&c,&e);
    while (c!=flag){
        E = malloc(sizeof(PolyList));
        E->coef = c;
        E->exp = e;
        T->next = E;
        T = E;
//        printf("请输入系数和指数\n");
        scanf("%d,%d",&c,&e);
    }
    T->next = NULL;
    return L;
}

PolyList plus(PolyList L1,PolyList L2){
    PolyList R,T,p1,p2;
    R = malloc(sizeof(PolyList));
    T = R;
    int sum;
    p1 = L1->next;
    p2 = L2->next;
    while (p1!=NULL &&p2!=NULL){
        if(p1->exp < p2->exp){
            T->next = p1;
            T = p1;
            p1 = p1->next;
        } else if(p1->exp > p2->exp){
            T->next = p2;
            T = p2;
            p2 = p2->next;
        } else{
            sum = p1->coef+p2->coef;
            if(sum!=0){
                p1->coef = sum;
                T->next = p1;
                T = p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1!=NULL){
        T->next = p1;
        T = p1;
        p1 = p1->next;
    }
    while (p2!=NULL){
        T->next = p2;
        T = p2;
        p2 = p2->next;
    }
    return R;
}

void print_list(PolyList L){
    printf("查看当前多项式\n");
    while (L->next!=NULL){
        L = L->next;
        printf("%dX^%d + ",L->coef,L->exp);
    }
    printf("0\n");
}

main(){
    PolyList L1 = create();
    print_list(L1);
    PolyList L2 = create();
    print_list(L2);
    PolyList S = plus(L1,L2);
    print_list(S);
    int t;
    scanf("%d",&t);
}