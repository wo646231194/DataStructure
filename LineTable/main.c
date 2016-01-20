//
// Created by hugbr on 2016/1/18.
//
#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10000

typedef struct {
    int data[MAX_NUM];
    int last;
}List;

//��ʼ��L->last=-1
List * init(){
    List * L;
    L = malloc(sizeof(List));//���ٿռ�
    L->last = -1;
    printf("��ʼ���ɹ�\n");
    return L;
}
/**
 * ���Ա�L��i��Ԫ�ز���x
 * @param List L,int i,int x
 * ʱ�临�Ӷ� n/2
 * */
int insert(List * L,int i,int x){
    int j;
    if(L->last > MAX_NUM-1){
        printf("������\n");
        return (-1);
    }
    if(i<1 || i>L->last+2){
        printf("����λ�ò���ȷ\n");
        return (0);
    }
    for(j=L->last; j>i-2;j--){
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = x;
    printf("��%d��λ�ò���%d \n",i,x);
    L->last++;
    printf("����Ϊ%d \n",L->last+1);
    return 1;
}

/*ɾ�����Ա�L �ĵ� i ��Ԫ��*/
int delete(List * L,int i){
    int j;
    if(i<1 || i>L->last+2){
        printf("������\n");
        return (0);
    }
    printf("ɾ����%d��λ�õ�Ԫ��%d\n",i,L->data[i-1]);
    for(j=i;j<=L->last;j++){
        L->data[j-1] = L->data[j];
    }
    L->last--;
    return 1;
}

/*�ҳ����Ա�L�е�Ԫ��x*/
int find(List * L,int x){
    int j;
    for(j=0;j<=L->last;j++){
        if(x==L->data[j]){
            printf("�ҵ���,%dԪ���ڵ�%d��λ��\n",x,j+1);
            return j;
        }
    }
    printf("û���ҵ� %d\n",x);
    return -1;
}

/*�õ����Ա��i��Ԫ��*/
int get(List * L,int i){
    printf("��ȡ��ĵ�%d��Ԫ��Ϊ%d",i,L->data[i-1]);
    return L->data[i-1];
}

/*��ʾ���Ա�L������Ԫ��*/
void show(List *L){
    int j;
    printf("��ʾ������Ԫ��:\n");
    for(j=0;j<=L->last;j++){
        printf("��%d��λ�õ�Ԫ��Ϊ%d\n",j+1,L->data[j]);
    }
}

void sort(List *L, int type){
    int i,j,temp;
    if(type) {
        for (i = 0; i < L->last; i++) {
            for (j = i + 1; j <= L->last; j++) {
                if (L->data[i] > L->data[j]) {
                    temp = L->data[j];
                    L->data[j] = L->data[i];
                    L->data[i] = temp;
                }
            }
        }
    } else{
        for (i = 0; i < L->last; i++) {
            for (j = i + 1; j <= L->last; j++) {
                if (L->data[i] < L->data[j]) {
                    temp = L->data[j];
                    L->data[j] = L->data[i];
                    L->data[i] = temp;
                }
            }
        }
    }
    show(L);
}

void merge(List *L1,List *L2,List *L3){
    int i=0,j=0,k=0;
    if(i<L1->last && i<L2->last){
        if(L1->data[i]<L2->data[i])
            L3->data[k++] = L1->data[i++];
        else
            L3->data[k++] = L2->data[j++];
    }
    while (i<L1->last){
        L3->data[k++] = L1->data[i++];
    }
    while (j<L2->last){
        L3->data[k++] = L2->data[j++];
    }
    L3->last = k-1;
}

main(){
    List * L;
    L = init();
    printf("----------------------------------------\n����Ԫ��\n");
    insert(L,1,99);
    insert(L,1,-12);
    insert(L,2,32);
    insert(L,1,250);
    show(L);
    printf("----------------------------------------\n����\n");
    sort(L,1);//��С����
    sort(L,0);//�Ӵ�С
    printf("----------------------------------------\nɾ��Ԫ��\n");
    delete(L,2);
    show(L);
    printf("----------------------------------------\n����Ԫ��\n");
    find(L,1);
    find(L,32);
    printf("----------------------------------------\n��ȡԪ��\n");
    get(L,2);
}
