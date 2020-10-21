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
    if(q->rear==MAX-1){
        printf("Overflow\n");
        return;
    }
    q->data[q->rear]=item;
    
    q->rear++;
    return;
}

int deque(Que *q){
    if(q->rear<q->front){
        printf("underflow");
        return -1;
    }
    printf("\n Dequing");
    int item = q->data[q->front];
    q->front=q->front+1;
    return item;
}

void display(Que *q){
    int limit = q->rear;
    for (int i = q->front; i < limit; i++)
    {
        printf(" %d ",q->data[i]);
    }
    return;
}

void initializ(Que *q){
    q->front=0;
    q->rear=0;
}

int main(){
    printf("Main function\n");
    Que q;
    initializ(&q);
    enque(&q,1);
    enque(&q,2);
    enque(&q,3);
    display(&q);
    int a = deque(&q);
    printf(" %d \n",a);
    int b = deque(&q);
    printf(" %d \n",b);
    display(&q);
}