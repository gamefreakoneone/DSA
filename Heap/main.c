#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
    struct Tree * left_child;
    struct Tree * right_child;
    int value;
}Node;

Node * insertNode(int item){
    Node * temp;
    temp =(Node *) malloc(sizeof(Node));
    temp->left_child=NULL;
    temp->right_child=NULL;
    temp->value=item;
}

void preorder(){
    printf("");
}

int main(){
    
}