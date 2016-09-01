#include<iostream>
using namespace std;
#define N 50

void down(int *x,int *y){
    *y+=1;
}
void up(int *x,int *y){
    *y-=1;
}
void left(int *x, int *y){
    *x-=1;
}
void right(int *x, int *y){
    *x+=1;
}

void gonext(int state,int *x,int *y){
    if(state == 0) right(x,y);
    if(state == 1) down(x,y);
    if(state == 2) left(x,y);
    if(state == 3) up(x,y);
}
void goback(int state,int *x,int *y){
    if(state == 0) left(x,y);
    if(state == 1) up(x,y);
    if(state == 2) right(x,y);
    if(state == 3) down(x,y);
}

void show(int m[N][N], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j]<<" ";
        }
        cout << endl;
    }
}

int main(){
    int n =0,m[N][N]={0};
    cin >> n;
    int now=1;
    int state = n*2-1;
    int x=0,y=0,t=0;
    while(state){
        int go = (state+1)/2;
        for(int i=0;i<go;i++){
            m[y][x]=now;
            now++;
            gonext(t,&x,&y);
        }
        goback(t,&x,&y);
        t++;
        t%=4;
        state-=1;
        gonext(t,&x,&y);
    }
    show(m, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j]<<" ";
        }
    }
    cin >> n;
}
