//
// Created by hugbr on 2016/1/23.
//
// ϡ�����

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
            num++;//Ԫ�������Լ�1
        }
        my++;//���Լ�1
        scanf("%c ",&c);
    }
//    printf("%d���������,��������س����밴e\n",mx);
    m->mx = mx;
}

Matrix * init(){
    int num=0,mx=1,my=1;//����������������
    int value,index=0;//ֵ������
    char c=' ';
    printf("--------����ϡ�����--------\n");
    printf("����������һ�У��ո�+�ֺ� ;����\n");
    Matrix * m = malloc(sizeof(Matrix));
    while (c!=';'){
        scanf("%d",&value);
        if(value!=0){
            m->data[num].i = mx;
            m->data[num].j = my;
            m->data[num].value = value;
            num++;//Ԫ�������Լ�1
        }
        my++;//���Լ�1
        scanf("%c",&c);
    }
    m->mx = mx;
    m->my = my-2;
    m->num = num-1;
    printf("----��������Ϊ%d----\n",m->my);
    printf("�����������,ÿһ���Կո�ӷֺ� ;�ָe����\n");
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
    printf("--------�鿴����Ԫ��--------\n");
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
    printf("��������Ϊ%d\n",m->my);
    printf("��������Ϊ%d\n",m->mx);
    show(m);
}