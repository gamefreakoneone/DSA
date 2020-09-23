#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create(Node *Start){
    Node * previous, * newnode;
    int num;
    printf("Give me a value:(exit with -1)");
    scanf("%d",&num);
    while (num!= -1)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=num;
        if(Start==NULL){
            newnode->next=newnode;
            Start=newnode;
        }else
        {
            previous=Start;
            while (previous->next!=Start)
            {
                previous=previous->next;
            }
            previous->next=newnode;
            newnode->next=Start;
        }
        printf("Give me a number:\n");
        scanf("%d",&num);
    }
    return Start;
}

void display(Node *Start){
    Node *current;
    current=Start;
    while (current->next!=Start)
    {
        printf(" %d ",current->data);
        current=current->next;
    }
    printf(" %d ",current->data);
    
}

void main(){
    Node *Start=NULL;
    Start=(struct node*)malloc(sizeof(struct node));
    Start->next=Start;
    printf("Give a starting value:\n");
    scanf("%d",&(Start->data));
    Start=create(Start);
    display(Start);
    // Start=InertBegin(Start);
    // display(Start);
    // Start=Insertlast(Start);
    // display(Start);
    // Start=InsertPart(Start);
    // display(Start);
    // Start=deleteFirst(Start);
    // printf("Deleting the fiest element:\n");
    // printf("\n");
    // display(Start);
    // Start=deleteLast(Start);
    // printf("Deleting the last element!");
    // printf("\n");
    // display(Start);
    // Start=deletePart(Start);
    // printf("\n");
    // display(Start);
}