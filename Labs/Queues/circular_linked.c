#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int d) //Insert elements in Queue
{
	struct node* n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = d;
	n->next = NULL;
	if((rear==NULL)&&(front==NULL))
	{
		front = rear = n;
		rear->next = front;
	}
	else
	{
		rear->next = n;
		rear = n;
		n->next = front;
	}
} 
void dequeue() // Delete an element from Queue
{
	struct node* t;
	t = front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
	else if(front == rear){
		front = rear = NULL;
		free(t);
	}
	else{
		front = front->next;
		rear->next = front;
		free(t);
	}
	
	
}
void Display(){ // Print the elements of Queue
	struct node* t;
	t = front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("\n%d",t->data);
			t = t->next;
		}while(t != front);
	}
}
int main()
{
	int opt,n,i,data;
	printf("Enter Your Choice:-");
	do{
		printf("\n MAIN MENU:");
        printf("\n 1. INSERT");
        printf("\n 2. DISPLAY");
        printf("\n 3. DELETE");
        printf("\n 0. EXIT");
        printf("\n Enter your option : ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				n=1;
				printf("\nEnter your data: ");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
				break;
			case 2:
				Display();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
	}while(opt!=0);
return 0;
}