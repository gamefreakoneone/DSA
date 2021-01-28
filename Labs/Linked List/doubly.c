#include <stdio.h>

#include <malloc.h>
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

struct node *create(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter –1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    start->prev = new_node;
    new_node->next = start;
    new_node->prev = NULL;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    return start;
}

struct node *insert_after_value(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted:");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_value(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return start;
}

int main(){
    int choice, truth =0,value;
    printf("Create a doubly linked list!\n");
    printf("Give a value:\n");
    scanf("%d",&value);
    struct node * Start = NULL;
    Start = (struct node*)malloc(sizeof(struct node));
    Start->data = value;
    Start->next=NULL;
    Start->prev=NULL;
    Start = create(Start);
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
            Start=insert_beg(Start);
            break;
        case 3:
            Start = insert_end(Start);
            break;
        case 4:
            Start = insert_after_value(Start);
            break;
        case 5:
            Start = delete_beg(Start);
            break;
        case 6:
            Start = delete_end(Start);
            break;
        case 7:
            Start = delete_value(Start);
            break;
        case 8:
            printf("Exiting!");
            truth=1;
            break;
        default:
            printf("Something went wrong!");
            break;
        }
        printf("\n");
    }
}