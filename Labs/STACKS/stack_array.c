#include <stdlib.h>
#include <stdio.h>
#define MAX 5 //MACRO

typedef struct Stack
{
    int info[MAX];
    int top;
} STACK;

void push(STACK *s, int n)
{
    if (s->top == MAX - 1)
    {
        printf("STACK FULL");
        return;
    }
    s->top++;
    s->info[s->top] = n;
}

int pop(STACK *s)
{
    int n;
    if (s->top == -1)
    {
        printf("Stack underflow");
        return -1;
    }
    n = s->info[s->top];
    s->top--;
    return n;
}

int main()
{
    STACK s;
    s.top = -1;
    int true = 0, choice, answer, popped;
    while (true == 0)
    {
        printf("What would you like to do:\n1.)Push\n2.)Pop\n3.)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The number you would like to push:\n");
            scanf("%d", &answer);
            push(&s, answer);
            break;

        case 2:
            printf("Popping \n");
            popped = pop(&s);
            printf("The number popped is %d \n", popped);
            break;

        case 3:
            printf("Exiting!!\n");
            true = 1;
            break;

        default:
            printf("Something went wrong! Try again!\n");
            break;
        }
    }
}