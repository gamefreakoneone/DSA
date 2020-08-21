#include<stdio.h>

int n=20;

void Change(){
    n=10;
    return;
}

int main(){
    Change();
    printf("%d",n);
}
