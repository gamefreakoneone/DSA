#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct Queue{
    int data[MAX];
    int front;
    int rear;
}Que;

void enque(Que *q, int item){
    printf("Enqueing \n");
    if(q->rear=MAX-1){
        printf("Overflow\n");
        return;
    }
    q->rear=q->rear+1;
    q->data[q->rear]=item;
    return;
}

int deque(Que *q){
    if(q->rear<q->front){
        printf("underflow");
        return -1;
    }
    int item = q->data[q->front];
    q->front=q->front+1;
    return item;
}

void display(Que *q){
    int limit = q->rear;
    for (int i = 0; i < limit; i++)
    {
        printf(" %d ",q->data[i]);
    }
    return;
}

int main(){
    printf("Main function\n");
    Que q;
    q.front=-1;
    q.rear=-1;
    enque(&q,1);
    enque(&q,2);
    enque(&q,3);
    display(&q);
}