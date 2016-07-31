#include <stdio.h>

#define MAX_NUM 100

typedef struct list{
    int value[MAX_NUM];
    int length;
}L;

void initL(L *l, int *a, int length){
    for(int i=0; i<length; ++i){
        l->value[i] = a[i];
    }
    l->length = length;
}

void printL(const L *l){
    for(int i=0; i<l->length; ++i){
        printf("%d ",l->value[i]);
    }
    printf("\n");
}

int binarySearch(L *l, int v){
    int low,mid,high,count;
    low = 0;high = l->length-1;
    count = 0;
    while (low <= high){
        mid = (low + high) /2;
        if(l->value[mid] == v) {
            return count;
        }
        count ++;
        if(v < l->value[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int z = 10;

    L seq;
    initL(&seq, a, 10);
    printL(&seq);

    printf("binary search %d times is %d\n", z, binarySearch(&seq, z));
}