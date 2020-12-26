#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coef;
    int power;
    struct Node * next;
};

struct Node * create_pol(struct Node * Base){
    int data, power,exit=1;
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
        printf("Do you want to continue?\n");
        scanf("%d", &exit);
    } while (exit!=0);
    return Base;
}


void display(struct Node * Base){
    printf("Displaying!\n");
    struct Node *ptr =NULL;
    ptr = Base;
    while (ptr->next!=NULL)
    {
        printf(" (%d x^ %d) ",ptr->coef,ptr->power);
        ptr=ptr->next;
        printf("+");
    }
    printf(" (%d x^ %d) ",ptr->coef,ptr->power);
}


void sort(struct Node * Base){
    int m,n;
    struct Node * ptr ,* nxtptr;
    for(ptr=Base;ptr!=NULL;ptr=ptr->next){
        for (nxtptr = ptr->next; nxtptr!=NULL; nxtptr=nxtptr->next)
        {
            if (ptr->power<nxtptr->power)
            {
                m=ptr->power;
                n=ptr->coef;
                ptr->power=nxtptr->power;
                ptr->coef=nxtptr->coef;
                nxtptr->power=m;
                nxtptr->coef=n;
            }
        }
    }
}

void main(){
    struct Node * Base =NULL;
    Base=create_pol(Base);
    display(Base);
    printf("\n");
    sort(Base);
    printf("\n");
    display(Base);
    printf("\n");
}