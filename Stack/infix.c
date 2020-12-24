// HELP!!!!!!!!!!!!!!
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 20

typedef struct node
{
    int data[MAX];
    int top;
} Node_operand;

typedef struct nodeC{
    char data[20];
    int top;
} Node_operator;

void push(Node_operand * s, float n){
    printf("Pushing number!\n");
    if(s->top==MAX-1){
        printf("Overload...exiting\n");
        return;
    }

    s->data[s->top]=n;
    s->top=(s->top)+1;
}

float pop(Node_operand * s){
    float n;

    printf("poping\n");
    if(s->top==-1){
        printf("Stack underflow\n");
        return -1;
    }
    s->top=(s->top)-1;
    n=s->data[s->top];
    return n;
}

void pushC(Node_operator * s, char c){
    printf("Pushing operator!\n");
    if(s->top==MAX-1){
        printf("Overloading.. exiting\n");
        return;
    }

    s->data[s->top]=c;
    s->top=(s->top)+1;
}

char popC(Node_operator *s){
    char c;

    printf("popping C\n");
    if(s->top==-1){
        printf("Stack underflow C\n");
        return '0';
    }
    s->top=(s->top)-1;
    c=s->data[s->top];
    return c;
}

float peek(Node_operand *s)
{
if(s->top == -1)
{
printf("\n STACK IS EMPTY \n");
return -1;
}
else
return (s->data[s->top]);
}

char peekC(Node_operator *s)
{
if(s->top == -1)
{
printf("\n STACK IS EMPTY C \n");
return -1;
}
else
return (s->data[s->top]);
}


int precedence(char optor){
    if(optor=='+'){
        return 1;
    }else if (optor == '-')
    {
        return 1;
    }else if (optor=='*')
    {
        return 2;
    }else if(optor=='/')
    {
        return 2;
    }
}

float operation(float v1, float v2, char optor){
    if(optor=='+'){
        printf("Adding!\n");
        return v1+v2;
    }else if (optor == '-')
    {
        printf("Subtracting\n");
        return v1-v2;
    }else if (optor=='*')
    {
        printf("Multiplying");
        return v1*v2;
    }else if(optor=='/')
    {
        printf("Dividing\n");
        return v1/v2;
    }
}

int main(){
    char exp[MAX];
    char c;
    printf("Give me the infix expression:\n");
    scanf("%s",exp);

    Node_operand opnds;
    opnds.top=-1;
    Node_operator optors;
    optors.top=-1;

    for(int i=0;exp[i]!='\0';i++){
        c=exp[i];

        if(c=='('){
            pushC(&optors,c);
        }else if (isdigit(c))
        {
            printf("Its a digit!\n");
            push(&opnds,c-'0');
        }else if(c==')'){
            while (peekC(&optors)!='(')
            {
                printf("Closing it up!\n");
                char optor = popC(&optors);
                float v2=pop(&opnds);
                float v1 = pop(&opnds);
                float result = operation(v1,v2,optor);
                push(&opnds,result);
            }
            popC(&optors);
        }else if(c=='+'|| c=='-'|| c=='/'|| c=='*'){
            while(optors.top!=-1 && peekC(&optors)!='(' && precedence(c)<=precedence(peekC(&optors))){
                char optor = popC(&optors);
                float v2=pop(&opnds);
                float v1 = pop(&opnds);
                float result = operation(v1,v2,optor);
                push(&opnds,result);
            }

            pushC(&optors,c);
        }
        
    }

    while (optors.top!=-1)
            {
                printf("Final!\n");
                char optor = popC(&optors);
                float v2=pop(&opnds);
                printf("%f \n",v2);
                float v1 = pop(&opnds);
                printf("%f \n",v1);
                float result = operation(v1,v2,optor);
                push(&opnds,result);
                printf("%f \n",result);
            }
    float result = pop(&opnds);
    printf("The result is  %f \n",result);
}