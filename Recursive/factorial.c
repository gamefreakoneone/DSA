#include<stdio.h>
#include<stdlib.h>

int fact(int n){
    if(n==0){
        return 1;
    }else
    {
        return n*fact(n-1);
    }
    
}

int main(){
    int n;
    scanf("%d",&n);
    int r=fact(n);
    printf("Factorial of %d is %d\n",n,r);
}