#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int num;


Node * delete_parts(Node * Start,int post, int nodes){
    Node * previous =Start,*position=Start, *Inter =NULL;
    int start =0, inter =1,placeholder=0;
    while (inter<post)
    {
        position=position->next;
        inter++;
        if(placeholder==0){
            placeholder++;
            continue;
        }
        previous=previous->next;
    }

    while (start<nodes)
    {
        Inter = position;
        position=position->next;
        previous->next=position;
        Inter->next=NULL;
        free(Inter);
        start=start+1;
    }
return Start;
}

// Node* test(Node *start)
// {
//     struct node *newnode,*previous; //check
//     newnode=NULL;
//     previous=NULL;
    
//     int c=1;

//     printf("\nEnter Data [Type 0 to exit] > ");
//     scanf("%d",&c);

//     while (c!=0)
//     {
//         newnode=(struct node*)malloc(sizeof(struct node));
//         newnode->data=c;
        
//         if (start==NULL)
//         {
//             newnode->next=NULL;
//             start = newnode;
//         }else
//         {
//             previous=start;
//             printf("\nThe data for the nodes in linked list are > ");
//             while(previous->next!=NULL)
//             {
//                 printf(" %d",previous->data);
//                 previous=previous->next;
//             }
//             printf(" %d",previous->data);
                
//             printf("\nAdding a new node at the end %d",newnode->data);
                
//             previous->next = newnode;
//             newnode->next=NULL;
//         }
//         printf("\n\nEnter Data [Type 0 to exit] > ");
//         scanf("%d",&c);
//     }
//     return start;
// }

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
            Start=newnode;
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

Node *InertBegin(Node *Start){
    Node *First;
    First=(struct node*)(malloc(sizeof(struct node)));
    int num;
    printf("\nGive me the value to be inserted in the begining:\n");
    scanf("%d",&num);
    First->data=num;
    First->next=Start;
    Start=First;
    return Start;
}

Node *Insertlast(Node *Start){
    Node *Last,*prev;
    prev=Start;
    int num;
    Last=(struct node*)(malloc(sizeof(struct node)));
    printf("\nGive me the value to be inserted at the end:\n");
    scanf("%d",&num);
    Last->data=num;
    Last->next=NULL;
    while (prev->next!=NULL)
    {
        prev=prev->next;
    }
    prev->next=Last;
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
    Node *current;
    current=Start;
    Start=Start->next;
    current->next=NULL;
    free(current);
    return Start;
}

Node *deleteLast(Node * Start){
    Node *last ,*current;
    last=Start;
    while (last->next!=NULL)
    {
        current=last;
        last=last->next;  
    }
    current->next=NULL;
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

void main(){
    Node *Start=NULL;
    Start=(struct node*)malloc(sizeof(struct node));
    printf("Give a starting value:\n");
    scanf("%d",&(Start->data));
    Start=create(Start);
    display(Start);
    printf("Here!");
    printf("\n");
    Start=delete_parts(Start,2,4);
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
    //display(Start);
}