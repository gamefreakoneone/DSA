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

void display(Node *Start){
    while (Start!=NULL)
    {
        printf(" %d ",Start->info);
        Start=Start->next;
    }
    
}

Node * insert_between(){
    
}

int main(){
    Node *Start;
    Start=create(Start);
    display(Start);
}