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

typedef struct s{
    Qnode *top;
}S;

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
    g->length = g->length>x?g->length:(x+1);
    g->length = g->length>y?g->length:(y+1);
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

void printS (const S *s){
    Qnode *n = s->top;
    while (n->next!=NULL){
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

void pushQ (Q *q, int value){
    Qnode *n = malloc(sizeof(Qnode));
    n->next = NULL;
    n->value = 0;
    q->end->value = value;
    q->end->next = n;
    q->end = n;
}

int popQ (Q *q){
    int value = q->head->value;
    Qnode *n = q->head;
    q->head = q->head->next;
    free(n);
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

void initS(S *s){
    Qnode *n = malloc(sizeof(Qnode));
    n->next = NULL;
    s->top = n;
}

void pushS(S *s, int v){
    Qnode *n = malloc(sizeof(Qnode));
    n->next = s->top;
    n->value = v;
    s->top = n;
}

int popS(S *s){
    int value = s->top->value;
    Qnode *n = s->top;
    s->top = s->top->next;
    free(n);
    return value;
}

int isInStack(S *s, int v){
    Qnode *n = s->top;
    while (n->next!=NULL){
        if(n->value == v) return 1;
        n = n->next;
    }
    return 0;
}

void breadIter(G *g, Q *q, int source){
    int count = 0;
    for(int i=0; i<g->length; ++i){
        int v = g->value[source][i];
        if(v && !isInQueue(q, i)){
            pushQ(q, i);
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

void deepIter(G *g, Q *q, int source){
    for(int i=0; i<g->length; ++i){
        int v = g->value[source][i];
        if(v && !isInStack(q, i)){
            pushQ(q, i);
            deepIter(g, q, i);
        }
    }
}

void BFS(G *g, int source){
    Q q;
    initQ(&q);
    pushQ(&q, source);
    breadIter(g, &q, source);
    printQ(&q);
}

void DFS(G *g, int source){
    Q q;
    initQ(&q);
    pushQ(&q, source);
    deepIter(g, &q, source);
    printQ(&q);
}

int main(){
    G graph;
    Q queue;
    S stack;
    initG(&graph);
    initQ(&queue);
    initS(&stack);

    connect(&graph, 0, 1);
    connect(&graph, 0, 2);
    connect(&graph, 1, 3);
    connect(&graph, 1, 4);
    connect(&graph, 2, 5);
    connect(&graph, 2, 6);
    connect(&graph, 3, 7);
    connect(&graph, 4, 7);
    connect(&graph, 5, 6);

    printG(&graph);

    pushQ(&queue, 1);
    pushQ(&queue, 2);
    pushQ(&queue, 3);
    pushQ(&queue, 4);

    printQ(&queue);
    popQ(&queue);
    printQ(&queue);

    pushS(&stack, 1);
    pushS(&stack, 2);
    pushS(&stack, 3);
    pushS(&stack, 4);

    printS(&stack);
    popS(&stack);
    printS(&stack);

    BFS(&graph, 0);
    DFS(&graph, 0);
}
