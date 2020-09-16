#include <stdio.h>
#include <stdlib.h>

void getdata(int arr[],int *lengthofarray);
void insert(int arr[],int *lengthofarray);


void getdata(int arr[],int *lengthofarray){
    for (int i = 0; i < *lengthofarray; i++)
    {
        scanf("%d",arr+i);
    }
}

void readdata(int arr[], int lengthofarray){
for (int i = 0; i < lengthofarray; i++)
    { 
        printf(" %d ",*(arr+i));
    }
}

void insert(int arr[], int *lengthofarray){
    int position,inter;
    int value;
    printf("What is the value you want to insert?");
    scanf("%d",&value);
    printf("At what position do you want to insert:\n");
    scanf("%d",&position);

    for(int i=(*lengthofarray)-1;i>=position;i--){
        arr[i+1]=arr[i];
    }

    arr[position]=value;
    
    *lengthofarray+=1;

}

int main(){
    int arr[50];
    int lengthofarray;
    
    printf("Give me the length of the array:");
    scanf("%d",&lengthofarray);

    getdata(arr,&lengthofarray);
    readdata(arr,lengthofarray);
    insert(arr,&lengthofarray);
    readdata(arr, lengthofarray);

}