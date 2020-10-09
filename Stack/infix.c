#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


typedef struct stack
{
    float data[MAX];
    int top;
} Stacks;


float evaluate(char exp[]);
void push(struct stack *s, float n);
float pop(struct stack *s);

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


    