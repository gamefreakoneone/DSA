#include<stdlib.h>
#include<stdio.h>




typedef struct node
{
    int data;
    struct node *next;
} Node;

Node * Create(Node *Start){
    Node *newnode,*previous;
    int c=1;
    while (c!=0)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Give me the value\n");
        scanf("%d",&newnode->data);
        if (Start =NULL)
        {
            Start=newnode;
        }else{
            previous->next=newnode;
            previous=newnode;
        }
        previous=newnode;
        printf("Continue?");
        scanf("%d",&c);
    }
    
}

void display(Node *Start){
    while (Start!= NULL)
    {
        printf("%d",Start->data);
        Start=Start->next;
    }
    
}

void main(){
    Node *Start=NULL;
    Start = (struct node *)malloc(sizeof(struct node));
    Start=Create(Start);
    display(Start);


}