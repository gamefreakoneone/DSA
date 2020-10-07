#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define MAX 100


typedef struct stack
{
    float data[MAX];
    int top;
} Stacks;


float evaluate(char exp[]);
void push(struct stack *s, float n);
float pop(struct stack *s);

int main()
{
    char exp[100];
    printf("Give me the postfix expression:\n");
    scanf("%s", exp);
    printf("%s",exp);
    float answer = evaluate(exp);
    printf("The solutin is %f", answer);
}

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

float evaluate(char exp[100]){
    printf("evaluating\n");
    Stacks s;
    s.top=0;
    int r,i=0;
    char symbol;
    while(exp[i]!='\0')
    {
        int a,b;
        symbol=exp[i];
        if (isdigit(symbol))
        {
            printf("Its a digit!\n");
            push(&s,symbol-'0');
        }
        else
        {
            float op2 = pop(&s);
            printf("%f\n",op2);
            float op1 = pop(&s);
            printf("%f\n",op1);
            switch (symbol)
            {
            case '+':
                r=op1+op2;
                printf("Adding it up\n");
                break;
            case '-':
                r=op1-op2;
                printf("Subtracting it\n");
                break;
            case '*':
                r=op1*op2;
                printf("Multiplying\n");
                break;
            case '/':
                r=op1/op2;
                printf("Dividing\n");
                break;
            default:
                printf("That does not work around here!\n");
                break;
            }
            push(&s,r);
        }
        i++;
    }
    r = pop(&s);
    return r;
}
