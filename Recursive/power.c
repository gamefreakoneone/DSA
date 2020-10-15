#include<stdio.h>
#include<stdlib.h>

int power(int m, int n){
    n=n-1;
    if(n==0){
        return 1;
    }
    return m * power(m,n);
}

int main(){
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    n=n+1;
    int r= power(m,n);
    printf("%d",r);
}
