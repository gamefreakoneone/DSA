#include<stdlib.h>
#include<stdio.h>
#define MAX 5 //MACRO


typedef struct Stack
{
    int info[MAX];
    int top;
} STACK;

void push(STACK *s, int n){
    if(s->top==MAX-1){
        printf("STACK FULL");
        return;
    }
    s->top++;
    s->info[s->top]=n;
}

int pop(STACK *s){
    int n;
    if(s->top==-1){
        printf("Stack underflow");
        return -1;
    }
    n=s->info[s->top];
    s->top--;
    return n;

}

int main(){
    STACK s;
    s.top=-1;
    push(&s,3);
    push(&s,4);
    int n=pop(&s);
}