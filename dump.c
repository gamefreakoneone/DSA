#include <stdio.h>
#include <stdlib.h>

int evensum(int lower,int higher){
    int sum=0;
    for(int i=lower;i<=higher;i++){
        if(i%2==0){
            printf(" %d ,",i);
            sum+=i;
        }
        else
        {
            continue;
        }
        
    }
}

int main(){
    char scentence[100];
    int lower;
    int higher;
    fgets(scentence,sizeof(scentence),stdin);
    printf("%s",scentence);
    printf("Give me the range\n");
    scanf("%d %d",&lower,&higher);
    evensum(lower,higher);
}