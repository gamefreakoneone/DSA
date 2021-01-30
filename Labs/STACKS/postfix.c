#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define MAX 100

typedef struct stack
{
    float data[MAX];
    int top;
} Stacks;

void push(Stacks * st, float val)
{
    if (st->top == MAX - 1){
        printf("\n STACK OVERFLOW");
        return;
    }
    else
    {
        st->top++;
        st->data[st->top] = val;
    }
}

float pop(Stacks * st)
{
    float val = -1;
    if (st->top == -1){
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        val = st->data[st->top];
        st->top--;
    }
    return val;
}

float evaluatePostfixExp(char exp[])
{
    Stacks st;
    st.top = -1;
    int i = 0;
    float op1, op2, value;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
            push(&st, (float)(exp[i] - '0'));
        else
        {
            op2 = pop(&st);
            op1 = pop(&st);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(&st, value);
        }
        i++;
    }
    return (pop(&st));
}


int main()
{
    float val;
    char exp[100];
    printf("\n Enter any postfix expression : ");
    gets(exp);
    val = evaluatePostfixExp(exp);
    printf("\n Value of the postfix expression = %.2f", val);
}