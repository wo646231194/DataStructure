//
// Created by hugbr on 2016/1/22.
//

#include <stdio.h>
#include <stdlib.h>

int length(char *s){
    char c;
    int i=0;
    c = s[i];
    while (c!='\0'){
        c = s[++i];
    }
    //printf("长度为%d\n",i);
    return i;
}

void show(char s[]){
    char c;
    int i=0;
    c = s[i];
    while (c!='\0'){
        printf("%c",s[i++]);
        c = s[i];
    }
    printf("\n");
}

char * link(char s1[], char s2[]){
    printf("连接字符串:\n");
    show(s1);
    show(s2);
    char c;
    int n = length(s1)+length(s2);//总字符串长度
    char * s;
    s = (char *)malloc(sizeof(char)*n);
    int i=0,j=0;
    c = s1[i];
    while (c!='\0'){
        s[j++] = s1[i++];
        c = s1[i];
    }
    i=0;
    c = s2[i];
    while (c!='\0'){
        s[j++] = s2[i++];
        c = s2[i];
    }
    s[j] = '\0';
    show(s);
    return s;
}

char * get(char s[],int x,int y){
    char *r = malloc(sizeof(char));
    if(x<1 || y>length(s)){
        printf("超出字符长度\n");
    } else{
        printf("取字符串%d--%d\n",x,y);
        int i,j=0;
        for(i=x-1;i<y;i++){
            r[j++] = s[i];
        }
        r[j] = '\0';
        show(r);
        return r;
    }
}

main(){
    char s1[]="huyang";
    show(s1);length(s1);
    char s2[]="mayan";
    show(s2);length(s2);
    char *s = link(s1,s2);
    get(s,2,3);
    get(s,8,9);
}