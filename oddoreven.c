#include <stdio.h>

int evenodd(int n){
    if(n%2==0){
        printf("Its true!");
    }else
    {
        printf("Its false");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    evenodd(n);
}