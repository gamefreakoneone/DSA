#include<stdio.h>
#include<stdlib.h>

void prime( int hrange){
    int value=0;
    for(int i=2;i<hrange;i++){
        value=0;
        if(hrange%i==0){
            printf("%d is not a prime\n",hrange);
            value=1;
            break;
        }  
    }
    if (value==0)
    {
        printf("%d is a prime number\n",hrange);
    }
}

int main(){
    int lrange,hrange;
    printf("Give me the range:\n");
    scanf("%d",&hrange);
    for(int i=2;i<hrange;i++){
        prime(i);
    }
    prime(hrange);
}