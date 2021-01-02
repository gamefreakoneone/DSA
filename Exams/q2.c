#include<stdio.h>
#include<stdlib.h>
#define MAX 10


typedef struct Que{
    char data[MAX];
    int front;
    int rear;
}que;

void Enque(que * q, char item){
    // char item;
    // printf("Give me a character:\n");
    // scanf(" %c",&item);
    if(q->front==((q->rear+1)%MAX)){
        printf("Overflow");
        return ;
    }
    if(q->front==-1 && q->rear==-1){
        q->front=q->rear=0;
        printf("\nEnquing 1.0  %c",item);
        q->data[q->rear]=item;
    }else{
        q->rear=((q->rear)+1)%MAX;
        q->data[q->rear]=item; 
        printf("\nEnquing %c",item);
    }
}

char Deque(que * q){
    char value;
    if (q->front==-1)
    {
        printf("Underflow!\n");
        return -1;
    }
    if(q->front==q->rear){
        q->front=q->rear=0;
        return q->data[q->front];
    }else{
        value = q->data[q->front];
        printf("\nThe dequed value will be %c\n",value);
        q->front=(q->front+1)%MAX;
    }
    return value;
}

void display(que * Q){
    printf("\nDisplaying:\n");
    int limit = Q->rear;
    for(int i = Q->front; i <limit;i++){
        printf(" %c ", Q->data[i]);
    }
    return;
}

void question(que *Q){
    char throw;
    char scentence[]="MANIPALUNIVERISTY";
    for(int i=0;i<MAX;i++){
        Enque(Q, scentence[i]);
        display(Q);
    }
    for(int j = MAX;scentence[j]!='\0';j++){
        throw = Deque(Q);
        Enque(Q, scentence[j]);
        display(Q);
    }
    while (Q->front!=Q->rear)
    {
        throw = Deque(Q);
        display(Q);
    }
    printf("Done!");
}

void main(){
    que Q;
    Q.front=-1;
    Q.rear=-1;

    question(&Q);
}