#include<stdio.h>
#include<stdlib.h>

typedef struct polynode
{
    float coeff;//info
    int power; //info
    struct polynode * next; //next
} Node;

Node * create(Node* name){
    printf("Hello");
    return name;
}
int main(){

}
