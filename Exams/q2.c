#include<stdio.h>
#include<stdlib.h>
#define MAX 10


typedef struct Que{
    int data[MAX];
    int front;
    int rear;
}que;

void Enque(que * q, int item){
    if(q->front==((q->rear)%MAX)){
        printf("Overflow");
        return ;
    }
    if(q->front==-1 && q->rear==-1){
        q->front=q->rear=0;
        q->data[q->rear]=item;
    }else{
        q->rear=((q->rear)+1)%MAX;
        q->data[q->rear]=item;
    }
}

int Deque(que * q){
    int value;
    if (q->front==-1)
    {
        printf("Underflow!\n");
        return -1;
    }
    if(q->front==q->rear){
        q->front=q->rear=0;
        return q->data[q->front];
    }else{
        q->front=(q->front+1)%MAX;
        value = q->data[q->front];
        printf("The dequed value will be %d",value);
    }
    return value;
}

void display(que * Q){
    printf("Displaying:\n");
    int limit = Q->rear;
    for(int i = 0; i <limit;i++){
        printf(" %d ", Q->data[i]);
    }
    return;
}

void main(){
    que Q;
    Q.front=-1;
    Q.rear=-1;
    Enque(&q,1);
    display(&q);
    Enque(&q,3);
    display(&q);
    enque(&q,5);
    display(&q);
    enque(&q,7);
    display(&q);
    enque(&q,9);
    display(&q);
    enque(&q,2);
    display(&q);
    int first = Deque(&q);
    int second = Deque(&q);
    int third = Deque(&q);
    int fourth = Deque(&q);
    int fifth = Deque(&q);
    display(&q);
}