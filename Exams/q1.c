#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coef;
    int power;
    struct Node * next;
};

struct Node * create_pol(struct Node * Base){
    int data, power;
    struct Node * newptr =NULL, *ptr = NULL;
    do
    {
        if(Base == NULL){
            printf("Give me a value:\n");
            scanf("%d",&data);
            printf("Give me the coefficient:\n");
            scanf("%d", &power);
            newptr=(struct Node *)malloc(sizeof(struct Node));
            newptr->coef=data;
            newptr->power = power;
            newptr->next=NULL;
            Base = newptr;
        }else
        {
            printf("Give me a value:\n");
            scanf("%d",&data);
            printf("Give me the coefficient:\n");
            scanf("%d", &power);
            newptr=(struct Node *)malloc(sizeof(struct Node));
            newptr->coef=data;
            newptr->power = power;
            newptr->next=NULL;
            ptr = Base;
            while (ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newptr;
        }
    } while (data!=66);
    return Base;
}


void display(struct Node * Base){
    printf("Displaying!\n");
    struct Node *ptr;
    ptr= Base;
    while (ptr!=NULL)
    {
        // printf(" \n ");
        printf(" (%dx^%d) ",ptr->coef,ptr->power);
        ptr=ptr->next;
        if(ptr->next!=NULL){
            printf("+");
        }
    }
}


void main(){
    struct Node * Base =NULL;
    Base=create_pol(Base);
    display(Base);
}