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

Node *insert_beg(Node *Start){
    Node *ptr,*newnode;
    int begin;
    printf("Give me the value to be added in the begining");
    scanf("%d",&begin);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=begin;
    newnode->next=Start;
    ptr=Start;
    while (ptr->next!=Start)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    Start=newnode;
    return Start;
}

Node *insert_end(Node *Start){
    Node *ptr, *last;
    last=(struct node *)malloc(sizeof(struct node));
    printf("Give me the value of the last node:\n");
    scanf("%d",&last->data);
    ptr=Start;
    while (ptr->next!=Start)
    {
        ptr=ptr->next;
    }
    ptr->next=last;
    last->next=Start;
    return Start;
    
}

Node *InsertPart(Node * Start){
    int position,num;
    Node *previous,*temp,*after;
    previous=Start;
    printf("\nAfter which node would you like to insert the element:\n");
    scanf("%d",&position);
    int i=1;
    while (i<=position-1)
    {
        previous=previous->next;
        after=previous->next;
        i++;
    }
    printf("Give me the value you want to store:\n");
    scanf("%d",&num);
    temp=(struct node*)(malloc(sizeof(struct node)));
    temp->data=num;
    temp->next=after;
    previous->next=temp;
    return Start;
}

Node *deleteFirst(Node * Start){
    Node *current,*last;
    last=Start;
    while (last->next!=Start)   
    {
        last=last->next;
    }
    
    current=Start;
    Start=Start->next;
    last->next=Start;
    current->next=NULL;
    free(current);
    return Start;
}

Node *deleteLast(Node * Start){
    Node *last ,*current;
    last=Start;
    while (last->next!=Start)
    {
        current=last;
        last=last->next;  
    }
    current->next=Start;
    free(last);
    return Start;
    
}

Node *deletePart(Node * Start){
    Node *location, *previous,*after;
    int value,i=0;
    location=previous=Start;
    printf("Which value do you want to delete?");
    scanf("%d",&value);
    while (location->data!=value)
    {
        location=location->next;
        after=location->next;
        if(i==0){
            i++;
            continue;
        }else
        {
            previous=previous->next;
        }
    }
    free(location);
    previous->next=after;
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

// Node *delete_duplicates(Node *Start){
//       printf("In the function!");
//       int length=1;
//       Node *inter;
//       inter=Start->next;
//       while (inter->next!=Start)
//       {
//           length++;
//       }
//       printf("\n %d \n",length);
//     return Start;
// }

Node *delete_dupes(Node * Start){
    int length=1;
    Node *current ,*next_one,*Destroy;
    current=Start;
    while (current->next!=Start)
    {
        current=current->next;  
        length=length+1;
    }

    current=Start;
    next_one=current->next;
    int limit=length*2,i=0;
    while (i<limit)
    {
        if(current->data==next_one->data){
            Destroy=next_one;
            next_one=next_one->next;
            current->next=next_one;
            Destroy->next=NULL;
            free(Destroy);
        }else{
            current=current->next;
            next_one=next_one->next;
            Destroy=NULL;
        }
        i++;
    }
    Start=current;
    return Start;
    
}

void main(){
    Node *Start=NULL;
    Start=(struct node*)malloc(sizeof(struct node));
    Start->next=Start;
    printf("Give a starting value:\n");
    scanf("%d",&(Start->data));
    Start=create(Start);
    display(Start);
    printf("Delete duplicates!\n");
    Start=delete_dupes(Start);
    display(Start);
    // Start=insert_beg(Start);
    // display(Start);
    // Start=insert_end(Start);
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