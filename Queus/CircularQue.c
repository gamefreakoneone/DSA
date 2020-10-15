#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct Queue{
    int data[MAX];
    int front;
    int rear;
}Que;


void enqueue(Que *q, int item){
    if(q->front==((q->rear)+1)%MAX){
        printf("Overflow");
        return
    }
}