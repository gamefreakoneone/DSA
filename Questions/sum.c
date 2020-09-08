#include<stdio.h>

int sums( int *a,int *b){
    return *a+*b;
}


int main(){
    int a,b,sum;
    scanf("%d %d",&a,&b);
    sum=sums(&a,&b);
    printf("%d",sum);
}