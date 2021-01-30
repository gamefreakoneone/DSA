#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
 
#define MAX 50
 
typedef struct stack
{
    int data[MAX];
    int top;
}Stack;
  
int precedence(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/'||x=='%')
        return(2);
 
    return(3);
}
 
int empty(Stack *s)
{
    if(s->top==-1)
        return(1);
 
    return(0);
}
 
int full(Stack *s)
{
    if(s->top==MAX-1)
        return(1);
 
    return(0);
}
 
void push(Stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}
 
int pop(Stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}
 
int top(Stack *p)
{
    return (p->data[p->top]);
}

void infix_to_postfix(char infix[],char postfix[])
{
    Stack s;
    char x,check;
    int i,j;
    s.top=-1;
    j=0;
 
    for(i=0;infix[i]!='\0';i++)
    {
        check=infix[i];
        if(isalnum(check))
            postfix[j++]=check;
        else
            if(check=='(')
               push(&s,'(');
        else
            if(check==')')
                while((x=pop(&s))!='(')
                      postfix[j++]=x;
                else
                {
                    while(precedence(check)<=precedence(top(&s))&&!empty(&s))
                    {
                        x=pop(&s);
                        postfix[j++]=x;
                    }
                    push(&s,check);
                }
    }
 
    while(!empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }
 
    postfix[j]='\0';
}

void main()
{
    char infix[30],postfix[30];
    printf("Enter infix expression: ");
    gets(infix);
    infix_to_postfix(infix,postfix);
    printf("\n The postfix expression: %s",postfix);
}
 