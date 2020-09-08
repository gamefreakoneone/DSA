#include<stdio.h>
#include<stdlib.h>

int main(){
    int number;
    scanf("%d",&number);
    int test=number;
    int sum=0,inter;
    while (test>0)
    {
        inter=test%10;
        test=test/10;
        sum=sum+(inter*inter*inter);
    }
    if (sum==number)
    {
        printf("Its Armstrong!");
    }else
    {
        printf("Its not");
    }
    
    
    
}