#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;
    struct node *prev;
    struct node *next;
} Node;

Node *create(Node *Start){
    Node *newnode,*prevnode=NULL;
    int c =0;
    while(c!=1){
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->info);
        newnode->next=NULL;
        newnode->prev=prevnode;
        if(Start==NULL){
            Start = newnode;
        }else{

            prevnode=Start;
            while (prevnode->next!=NULL)
            {
                prevnode=prevnode->next;
            }
            prevnode->next=newnode;
            prevnode=newnode;
        }
        printf("Quit:1");
        scanf("%d",&c);
    }
    return Start;
}

Node *insert_beg(Node *Start){
    Node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Give me the value to insert in the beginning:\n");
    scanf("%d",&newnode->info);
    newnode->next=Start;
    newnode->prev=NULL;
    Start=newnode;
    return Start;
}

void display(Node *Start){
    while (Start!=NULL)
    {
        printf(" %d ",Start->info);
        Start=Start->next;
    }
    
}

Node * insert_between(Node *Start){
    int position,i=1;
    Node *newnode, *previous,*after;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("After how many positions after: \n");
    scanf("%d",&position);
    printf("What do you want to store:\n");
    scanf("%d",&newnode->info);
    after=Start;
    previous=Start;
    while (i<position)
    {   
        if(i==1){
            printf("Continue:");
            continue;
        }else
        {
            previous=previous->next;
        }
        
        after=after->next;
        i++;
    }
    newnode->next=after;
    after->prev=newnode;
    newnode->prev=previous;
    previous->next=newnode;

    return Start;
}

int main(){
    Node *Start;
    Start=create(Start);
    display(Start);
    Start=insert_beg(Start);
    display(Start);
    Start=insert_between(Start);
    display(Start);
}