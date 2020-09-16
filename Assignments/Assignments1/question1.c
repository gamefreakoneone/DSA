#include<stdio.h>
#include<stdlib.h>


int lread(int arr[], int listsize,int search){
    int torf=0;
for (int i = 0; i < listsize; i++)
    {
        if (search==*(arr+i))
        {
            torf=1;
            break;
        }
        
    }

    return torf;
}

void seatchlist(int arr[], int listsize){
    int search;
    int torf=0;
    printf("Give me the element you are searching for:");
    scanf("%d",&search);
    torf=lread(arr,listsize,search);
    if (torf==0)
    {
        printf("The element is not present in the array!");
    }else if (torf==1)
    {
        printf("The element is present in the array!");
    }
    
    
}


int main(){
    int arr[100],listsize;
    printf("Give me the number of elements you want to add:");
    scanf("%d",&listsize);
    printf("Enter the elements:\n");
    for (int i = 0; i < listsize; i++)
    {
        scanf("%d",arr+i);
    }
    seatchlist(arr,listsize);

}