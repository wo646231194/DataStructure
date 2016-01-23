//
// Created by hugbr on 2016/1/23.
//
// 稀疏矩阵

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000

typedef struct node{
    int i,j,value;
}Node;

typedef struct matrix{
    int mx,my,num;
    Node data[MAX_NUM];
}Matrix;

int init_row(Matrix * m,int mx){
    int value,my = 1;
    int num = m->num+1;
    char c = ' ';
    while (c!=';'){
        scanf("%d",&value);
        if(value!=0){
            m->data[num].i = mx;
            m->data[num].j = my;
            m->data[num].value = value;
            num++;//元素数量自加1
        }
        my++;//列自加1
        scanf("%c ",&c);
    }
//    printf("%d行输入完毕,结束输入回车后请按e\n",mx);
    m->mx = mx;
}

Matrix * init(){
    int num=0,mx=1,my=1;//个数，行数，列数
    int value,index=0;//值，索引
    char c=' ';
    printf("--------生成稀疏矩阵--------\n");
    printf("请输入矩阵第一行，空格+分号 ;结束\n");
    Matrix * m = malloc(sizeof(Matrix));
    while (c!=';'){
        scanf("%d",&value);
        if(value!=0){
            m->data[num].i = mx;
            m->data[num].j = my;
            m->data[num].value = value;
            num++;//元素数量自加1
        }
        my++;//列自加1
        scanf("%c",&c);
    }
    m->mx = mx;
    m->my = my-2;
    m->num = num-1;
    printf("----矩阵列数为%d----\n",m->my);
    printf("请输入更多行,每一行以空格加分号 ;分割，e结束\n");
    mx = 2;my = 1;
    char s = ' ';
    while (s!='e'){
        init_row(m,mx);
        mx++;
        scanf("%c",&s);
    }
    return m;
}

int show(Matrix *m){
    printf("--------查看矩阵元素--------\n");
    int i,j,index=0;
    for(i=0;i<m->mx;i++){
        for(j=0;j<m->my;j++){
            if(i+1 ==m->data[index].i && j+1 ==m->data[index].j){
                printf(" %d",m->data[index].value);
                index++;
            } else{
                printf(" 0");
            }
        }
        printf("\n");
    }
    return 1;
}

main(){
    Matrix * m = init();
    printf("矩阵列数为%d\n",m->my);
    printf("矩阵行数为%d\n",m->mx);
    show(m);
}