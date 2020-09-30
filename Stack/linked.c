#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node * push(Node * Start, int n){
    Node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data =n;
    newnode->next=Start;
    return newnode;
}

Node *pop(Node * Start, int * n){
    Node * temp;
    temp=Start;
    *n=Start->data;
    Start=Start->next;
    temp->next=NULL;
    free(temp);
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

int main(){
    int n;
    Node * Start;
    Start = NULL;
    Start=push(Start,3);
    Start=push(Start,5);
    display(Start);
    printf("\n");
    Start = pop(Start,&n);
    printf("deleted number: %d\n-",n);
    display(Start);
}