#include <stdio.h>
#include <stdlib.h>

typedef struct Binary{
    int value;
    struct Binary *left, *right;
}*B;

B initB(){
    B b = malloc(sizeof(B));
    b->left = NULL;
    b->right = NULL;
    return b;
}

B initBv(int v){
    B b = malloc(sizeof(B));
    b->value = v;
    b->left = NULL;
    b->right = NULL;
    return b;
}

void addB(B b, int value){
    if(value <= b->value){
        if(b->left==NULL){
            B bt = initBv(value);
            b->left = bt;
        } else{
            addB(b->left,value);
        }
    }
    if(value > b->value){
        if(b->right==NULL){
            B bt = initBv(value);
            b->right = bt;
        } else {
            addB(b->right,value);
        }
    }
}

int findB(B b, int value){
    if(value == b->value) return 1;
    if(value < b->value){
        if(b->left==NULL){
            return 0;
        } else{
            return findB(b->left, value);
        }
    }
    if(value > b->value){
        if(b->right==NULL){
            return 0;
        } else {
            return findB(b->right, value);
        }
    }
}

void find(B b, int value){
    if(findB(b, value))
        printf("%d find\n", value);
    else
        printf("%d can't find\n", value);
}

void printB(const B b){
    if(b == NULL) return;
    printf("%d ",b->value);
    printB(b->left);
    printB(b->right);
}

int main(){
    B tree = initBv(1);
    addB(tree, -4);
    addB(tree, -3);
    addB(tree, 2);
    addB(tree, 3);
    addB(tree, -1);
    printB(tree);
    printf("\n");
    find(tree, 2);
    find(tree, 4);
    find(tree, 0);
    find(tree, -1);
}