#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20

typedef struct stacks
{
    int data[MAX];
    int top;
} Stack;

typedef struct characters{
    char data[MAX];
    int top;
} Operators;

void push(struct stack *s, float n){
    printf("Pushing %f\n",n);
    if(s->top==MAX-1){
        printf("Stack overflow!\n");
        return;
    }
    s->data[s->top]=n;
    s->top=(s->top)+1;
}

float pop(struct stack *s){
    int n;
    s->top=(s->top)-1;
    printf("poping\n");
    if(s->top==-1){
        printf("Stack underflow\n");
        return 0;
    }
    n=s->data[s->top];
    return n;
}

int Empty(Operators operators){

}

int main(){
    printf("Give the infix expression:\n");
    char exp[MAX];
    scanf("%s",exp);
    Stack numbers;
    numbers.top=-1;
    Operators operators;
    operators.top=-1;
    for (int i = 0; exp[i] != "\0"; i++)
    {
        char symbol= exp[i];
        if (isdigit(symbol))
        {
            printf("%s is a digit");
            push(&numbers, symbol);
        }else
        {
             if ()
             {
                 /* code */
             }
             
        }
        
        
    }
    
}