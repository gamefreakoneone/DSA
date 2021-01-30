#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *push(Node *Start, int n)
{
    Node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = Start;
    return newnode;
}

Node *pop(Node *Start, int *n)
{
    Node *temp;
    temp = Start;
    *n = Start->data;
    Start = Start->next;
    temp->next = NULL;
    free(temp);
    return Start;
}

int main()
{
    int n;
    Node *Start;
    Start = NULL;
    int true = 0, choice, answer, popped;
    while (true == 0)
    {
        printf("What would you like to do:\n1.)Push\n2.)Pop\n3.)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The number you would like to push:\n");
            scanf("%d", &answer);
            Start = push(Start, answer);
            break;

        case 2:
            printf("Popping \n");
            pop(Start, &popped);
            printf("The number popped is %d \n", popped);
            break;

        case 3:
            printf("Exiting!!\n");
            true = 1;
            break;

        default:
            printf("Something went wrong! Try again!\n");
            break;
        }
    }
}