#include <stdlib.h>
#include <stdio.h>
#define MAX_NODE 100

typedef struct node{
    int value;
    struct node *next;
}Qnode;

typedef struct q{
    Qnode *head;
    Qnode *end;
}Q;

typedef struct g{
    int value[MAX_NODE][MAX_NODE];
    int length;
}G;

void initG (G *g){
    for(int i=0; i<MAX_NODE;i++){
        for(int j=0;j<MAX_NODE;j++){
            g->value[i][j] = 0;
        }
    }
    g->length = 0;
}

void connect(G *g, int x, int y){
    if(x >= MAX_NODE || y >= MAX_NODE){
        return;
    }
    g->value[x][y] = 1;
    g->value[y][x] = 1;
    g->length = x>y?(x+1):(y+1);
}

void printG (const G *g){
    for(int i=0; i<g->length;i++){
        for(int j=0;j<g->length;j++){
            printf("%d ",g->value[i][j]);
        }
        printf("\n");
    }
}

void printQ (const Q *q){
    Qnode *n = q->head;
    while(n->next!=NULL){
        printf("%d ", n->value);
        n = n->next;
    }
    printf("\n");
}

void initQ (Q *q){
    Qnode *n = malloc(sizeof(Qnode));
    n->next = NULL;
    q->head = n;
    q->end = n;
}

void push (Q *q, int value){
    Qnode *n = malloc(sizeof(Qnode));
    n->next = NULL;
    n->value = 0;
    q->end->value = value;
    q->end->next = n;
    q->end = n;
}

int pop (Q *q){
    int value = q->head->value;
    q->head = q->head->next;
    return value;
}

int isInQueue(Q *q, int v){
    Qnode *n = q->head;
    while (n->next != NULL){
        if(n->value == v) return 1;
        n = n->next;
    }
    return 0;
}

void breadIter(G *g, Q *q, int s){
    int count = 0;
    for(int i=0; i<g->length; ++i){
        int v = g->value[s][i];
        if(v && !isInQueue(q, i)){
            push(q, i);
            count ++;
        }
    }
    if(!count) return;
    Qnode *n = q->head;
    while (n->next != NULL){
        breadIter(g, q, n->value);
        n = n->next;
    }
}

void BFS(G *g, int s){
    Q q;
    initQ(&q);
    push(&q, s);
    breadIter(g, &q, s);
    printQ(&q);
}

int main(){
    G graph;
    Q queue;
    initG(&graph);
    initQ(&queue);

    connect(&graph, 0, 1);
    connect(&graph, 0, 2);
    connect(&graph, 0, 3);
    connect(&graph, 0, 5);

    connect(&graph, 1, 5);
    connect(&graph, 2, 4);
    connect(&graph, 3, 4);
    connect(&graph, 3, 5);

    printG(&graph);

    push(&queue, 1);
    push(&queue, 2);
    push(&queue, 3);
    push(&queue, 4);

    printQ(&queue);
    pop(&queue);
    printQ(&queue);

    BFS(&graph, 0);
}

