#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int patient_id;
    char name[20];
    int Doctor_id;
    int Bed_No;
    int ward;
    struct node *next;
} Node;

Node *create(Node *Start)
{
    struct node *newnode = NULL, *previous = NULL;
    int num, D_id, B_No, Ward;
    printf("Give me the patient id first and then the name: \n");
    scanf(" %d ", &num);
    while (num != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->patient_id = num;

        scanf("%s", newnode->name);
        printf("Which doctor is handling the patient:\n");
        printf("Doctors:\n1.) Dr.Raj\n2.) Dr.Char\n3.)Dr.Janesh\n");
        scanf("%d", &(newnode->Doctor_id));
        printf("The Bed Number:\n");
        scanf("%d", &(newnode->Bed_No));
        printf("Give me the ward number:\n");
        scanf("%d", &(newnode->ward));

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
        printf("\n___________________________________________\n");
        printf("Give me the patient id: (exit = -1)\n");
        scanf("%d", &num);
        if (num != -1)
        {
            printf("Give me the name of the patient:\n");
        }
        printf("\n");
    }
    newnode->next = NULL;
    return Start;
}

void display(Node *Start, int Doc_id)
{
    Node *current;
    current = Start;
    int truth = 0;
    while (current != NULL)
    {
        if (current->Doctor_id == Doc_id)
        {
            truth++;
            printf("\n");
            printf("The patient name is: ");
            puts(current->name);
            printf("The patient id is %d \n", current->patient_id);
            printf("The Bed Number is %d.\n", current->Bed_No);
            printf("The ward is %d \n", current->ward);
            printf("__________________________________________________\n");
        }
        current = current->next;
    }
    if (truth == 0)
    {
        printf("Sorry! No patients under this doctor is found!\n");
    }
}

Node *InertBegin(Node *Start)
{
    printf("\n");
    Node *First;
    First = (struct node *)(malloc(sizeof(struct node)));
    int num;
    printf("Give me the patient id first and then the name: \n");
    scanf(" %d ", &num);
    First->patient_id = num;
    scanf("%s", First->name);
    printf("Which doctor is handling the patient:\n");
    printf("Doctors:\n1.) Dr.Raj\n2.) Dr.Char\n3.)Dr.Janesh\n");
    scanf("%d", &(First->Doctor_id));
    printf("The Bed Number:\n");
    scanf("%d", &(First->Bed_No));
    printf("Give me the ward number:\n");
    scanf("%d", &(First->ward));
    First->next = Start;
    Start = First;
    return Start;
}

void main()
{
    Node *Start = NULL;
    int truth = 0, choice;
    printf("Lets start listing the hospital database starting with the patient id's:\n");
    Start = create(Start);
    while (truth==0)
    {
        printf("What do you want to do?\n1.)Display\n2.)Insert at the Beginning\n3.)Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Which doctor would you like to see:\n");
            printf("Doctors:\n1.) Dr.Raj\n2.) Dr.Char\n3.)Dr.Janesh\n");
            scanf("%d", &choice);
            display(Start, choice);
            break;
        case 2:
            Start=InertBegin(Start);
            break;
        case 3:
            printf("Exiting!");
            truth=1;
            break;
        default:
            printf("Something went wrong!");
            break;
        }
    }
}