#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int pr;
    struct node * next;
} Node;

Node * new_node(int d, int p){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=d;
    temp->pr=p;
    temp->next=NULL;
    return temp;
}

void insert(Node **h, int d, int p){
    Node *temp = new_node(d,p);
    Node *demo = *h;

    if(demo->pr>p){
        temp->next=demo;
        (*h)=temp;
    }else{
        while (demo->next!=NULL && demo->next->pr<p)
        {
            demo=demo->next;
        }
        temp->next=demo->next;//I think its NULL
        demo->next=temp;
    }
}

int get_highest_p(struct node **h){
    int max;
    if(*h==NULL){
        printf("Priority Queue is empty\n");
        return INT_MIN;
    }else{
        int max = (*h)->data,p=(*h)->pr;
        Node *temp =(*h)->next;

        while (temp!=NULL)
        {
            if(temp->pr>p){
                max=temp->data;
                p=temp->pr;
            }
            temp=temp->next;
        }
        printf("The data with highest priority is %d and the priority is %d \n",max,p);
        return max;
    }
}

void delete_highest_p(Node **h){
    if(*h==NULL){
        printf("Priority Queue is empty\n");
        return;
    }else{
        Node * demo =*h;
        int d,p;
        while(demo->next!=NULL){
            demo=demo->next;
        }
        d=demo->data;
        p=demo->pr;
        free(demo);
        printf("The deleted data with highest priority is %d and the priority is %d",d,p);
    }
}

int main(){
    Node *head = new_node(4,1);
    int i;
    insert(&head,9,7);
    insert(&head, 14,3);
    insert(&head,5,0);

    i=get_highest_p(&head);
    delete_highest_p(&head);
}