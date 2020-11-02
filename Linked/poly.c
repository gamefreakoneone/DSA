#include<stdio.h>
#include<stdlib.h>

typedef struct polynode
{
    int coeff;//info
    int power; //info
    struct polynode * next; //next
} Node;

Node * create(Node* Exp,int coef, int power){
    printf("Creating\n");
    Node *current, *temp;
    current=Exp;
    if(current==NULL){
        temp=(Node *)malloc(sizeof(Node));
        temp->coeff=coef;
        temp->power=power;
        temp->next=(Node *)malloc(sizeof(Node));
        temp=temp->next;
        current=temp;
    }else{
        temp=current;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->coeff=coef;
        temp->power=power;
        current->next=(Node *)malloc(sizeof(Node));
        current=current->next;
        current->next=NULL;
    }
    return current;
}

void show( Node *node) 
{ printf("display");
while(node->next != NULL) 
	{ 
	printf("%dx^%d", node->coeff, node->power); 
	node = node->next; 
	if(node->next != NULL) 
		printf(" + "); 
	} 

    printf("\n");
} 

Node * add(Node *poly1, Node *poly2, Node *poly){
    while (poly1->next && poly2->next)
    {
        if(poly1->power>poly2->power){
            poly->power=poly1->power;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }else if (poly1->power<poly2->power)
        {
            poly->power=poly2->power;
            poly->coeff=poly2->coeff;
            poly2=poly2->next;
        }else
        {
            poly->power=poly1->power;
            poly->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        return poly;
    }
    
}

int main(){
    Node * f_exp1=NULL, *f_exp2=NULL, *f_exp=NULL;
    f_exp1=create(f_exp1,5,2);
    f_exp1=create(f_exp1,2,1);
    // f_exp1=create(f_exp1,6,0);
    show(f_exp);

    // f_exp2=create(f_exp2,8,3);
    // f_exp2=create(f_exp2,5,1);
    // f_exp2=create(f_exp2,2,0);
    // show(f_exp2);

    // f_exp=(struct polynode *)(malloc(sizeof(struct polynode)));
    // f_exp=add(f_exp1,f_exp2,f_exp);
    // show(f_exp);

}
