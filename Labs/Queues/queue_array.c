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

    int val, option, delete;
    do
    {
        printf("\n MAIN MENU:");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");

        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the number to insert in the queue:");
            scanf("%d", &val);
            enque(&q, val);
            break;
        case 2:
            delete = deque(&q);
            printf("The element dequeued is: %d", delete);
            break;
        case 3:
            display(&q);
            break;
        }
    } while (option != 4);
}