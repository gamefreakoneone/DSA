#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct Queue{
    int data[MAX];
    int front;
    int rear;
}Que;

void enque(Que *q){
    printf("What is the value you want to add?");
    int num;
    scanf("%d",&num);
    printf("Enqueing \n");
    if(q->front==(q->rear+1)%MAX){
        printf("Overflow\n");
        return;
    }

    q->data[q->rear]=num;
    q->rear=(q->rear++)/MAX;
    return;
}

int deque(Que *q){
    if(q->front==-1){
        printf("underflow\n");
        return -1;
    }
    printf("\n Dequing\n");
    int item = q->data[q->front];
    if (q->front==q->rear)
    {
        q->front=q->rear=0;
        return item;
    }
    
    q->front=q->front+1;
    return item;
}

void display(Que *q){
    printf("Displaying");
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
    Que q;
    initializ(&q);
    enque(&q);
    display(&q);
    enque(&q);
    display(&q);
    enque(&q);
    display(&q);
    enque(&q);
    display(&q);
    enque(&q);
    display(&q);
    enque(&q);
    display(&q);
    int first = deque(&q);
    int second = deque(&q);
    int third = deque(&q);
    int fourth = deque(&q);
    int fifth = deque(&q);
    display(&q);
    int sizth = deque(&q);
}