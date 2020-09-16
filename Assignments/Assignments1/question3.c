#include <stdio.h>
#include <stdlib.h>

void getdata(int arr[],int *lengthofarray);
void delete(int arr[],int *lengthofarray);


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

void delete(int arr[], int *lengthofarray){
    int position,inter;
    int value;

    printf("At what position do you want to delete:\n");
    scanf("%d",&position);

    arr[position]=0;
    for(int i=position;i<*lengthofarray;i++){
        arr[i]=arr[i+1];
    }

    

    arr[*lengthofarray-1]='\0';
    
    *lengthofarray-=1;

}

int main(){
    int arr[50];
    int lengthofarray;
    
    printf("Give me the length of the array:");
    scanf("%d",&lengthofarray);

    getdata(arr,&lengthofarray);
    readdata(arr,lengthofarray);
    delete(arr,&lengthofarray);
    readdata(arr, lengthofarray);

}