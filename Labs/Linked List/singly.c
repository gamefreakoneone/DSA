#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create(Node *Start)
{
    struct node *newnode = NULL, *previous = NULL;
    int num;
    printf("Give me the number: \n");
    scanf("%d", &num);
    while (num != 0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (Start == NULL)
        {
            newnode->next = NULL;
            Start = newnode;
        }
        else
        {
            previous = Start;
            while (previous->next != NULL)
            {
                previous = previous->next;
            }
            previous->next = newnode;
        }
        printf("Give me a value: (exit = 0)\n");
        scanf("%d", &num);
    }
    newnode->next = NULL;
    return Start;
}

void display(Node *Start)
{
    Node *current;
    current = Start;
    while (current->next != NULL)
    {
        printf(" %d ", current->data);
        current = current->next;
    }
    printf(" %d ", current->data);
}

Node *InertBegin(Node *Start)
{
    Node *First;
    First = (struct node *)(malloc(sizeof(struct node)));
    int num;
    printf("\nGive me the value to be inserted in the begining:\n");
    scanf("%d", &num);
    First->data = num;
    First->next = Start;
    Start = First;
    return Start;
}

Node *Insertlast(Node *Start)
{
    Node *Last, *prev;
    prev = Start;
    int num;
    Last = (struct node *)(malloc(sizeof(struct node)));
    printf("\nGive me the value to be inserted at the end:\n");
    scanf("%d", &num);
    Last->data = num;
    Last->next = NULL;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }
    prev->next = Last;
    return Start;
}

Node *InsertPart(Node *Start)
{
    int position, num;
    Node *previous, *temp, *after;
    previous = Start;
    printf("\nAfter which node would you like to insert the element:\n");
    scanf("%d", &position);
    int i = 1;
    while (i <= position - 1)
    {
        previous = previous->next;
        after = previous->next;
        i++;
    }
    printf("Give me the value you want to store:\n");
    scanf("%d", &num);
    temp = (struct node *)(malloc(sizeof(struct node)));
    temp->data = num;
    temp->next = after;
    previous->next = temp;
    return Start;
}

Node *deleteFirst(Node *Start)
{
    Node *current;
    current = Start;
    Start = Start->next;
    current->next = NULL;
    free(current);
    return Start;
}

Node *deleteLast(Node *Start)
{
    Node *last, *current;
    last = Start;
    while (last->next != NULL)
    {
        current = last;
        last = last->next;
    }
    current->next = NULL;
    free(last);
    return Start;
}

Node *deletePart(Node *Start)
{
    Node *location, *previous, *after;
    int value, i = 0;
    location = previous = Start;
    printf("Which value do you want to delete?");
    scanf("%d", &value);
    while (location->data != value)
    {
        location = location->next;
        after = location->next;
        if (i == 0)
        {
            i++;
            continue;
        }
        else
        {
            previous = previous->next;
        }
    }
    free(location);
    previous->next = after;
    return Start;
}


void main()
{
    Node *Start = NULL;
    printf("Create a linked list:\n");
    Start = (struct node *)malloc(sizeof(struct node));
    Start = create(Start);
    int truth =0,choice;
    while (truth==0)
    {
        printf("What do you want to do?\n1.)Display\n2.)Insert at the Beginning\n3.)Insert at the end\n4.)Insert at a particular positon\n5.)Delete at the Beginning\n6.)Delete at the end\n7.)Delete a value\n8.)Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            display(Start);
            break;
        case 2:
            Start=InertBegin(Start);
            break;
        case 3:
            Start = Insertlast(Start);
            break;
        case 4:
            Start = InsertPart(Start);
            break;
        case 5:
            Start = deleteFirst(Start);
            break;
        case 6:
            Start = deleteLast(Start);
            break;
        case 7:
            Start = deletePart(Start);
            break;
        case 8:
            printf("Exiting!");
            truth=1;
            break;
        default:
            printf("Something went wrong!");
            break;
        }
    }
    
}