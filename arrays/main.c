#include<stdio.h>

void swap(int *a,int *b){
    *a=9;
    *b=7;
}

void main(){
    int a=7,b=9;
    swap(&a,&b);
    printf("%d,%d",a,b);
}