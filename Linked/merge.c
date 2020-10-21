#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create(Node *Start){
    struct node *newnode = NULL , *previous = NULL;
    int num;
    printf("Give me the number: \n");
    scanf("%d",&num);
    while (num!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        if (Start==NULL)
        {
            newnode->next=NULL;
        }
        else
        {
            previous=Start;
            while (previous->next!=NULL)
            {
                previous=previous->next;
            }
            previous->next=newnode;
        }
    printf("Give me a value: (exit = 0)\n");
    scanf("%d",&num);
    }
    newnode->next=NULL;
    return Start;
}

void display(Node *Start){
    Node *current;
    current=Start;
    while (current->next!=NULL)
    {
        printf(" %d ",current->data);
        current=current->next;
    }
    printf(" %d ",current->data);
    
}

int size(Node * L){
    Node* previous = NULL;
    int length=1;
    previous=L;
    while (previous->next!=NULL)
    {
        length++;
        previous=previous->next;
    }
    return length;
}


Node * merge(Node * L1, Node * L2){
    Node *inter1 = NULL, *inter2 = NULL,*inter3=NULL,*inter4=NULL;
    inter1=L1;
    printf("reached here\n");
    display(inter1);
    inter2=L2;
    int size1=size(inter1);
    printf("\n%d\n",size1);
    int size2 = size(inter2);
    printf("%d",size2);

    if(size1>size2){
        inter3=L1;
        while (inter2->next!=NULL)
        {
            inter1->next=inter2;
            inter1=inter1->next;
            inter2=inter2->next;
        }
        
    }
}

void main(){
    Node *Start1=NULL,*Start2=NULL;
    Start1=(struct node*)malloc(sizeof(struct node));
    printf("Give a starting value for 1st list:\n");
    scanf("%d",&(Start1->data));
    Start1=create(Start1);
    display(Start1);
    printf("\n");
    Start2=(struct node*)malloc(sizeof(struct node));
    printf("Give a starting value for 2 list:\n");
    scanf("%d",&(Start2->data));
    Start2=create(Start2);
    display(Start2);
    printf("\n");
    Node * L3 = merge(Start1,Start2);
    printf("\n");
    display(L3);
}