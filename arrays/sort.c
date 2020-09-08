#include<stdio.h>
#include<stdlib.h>

void createArray(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        scanf("%d",arr+i);
    }
}

void sort(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i]<arr[j])
            {
                printf("Sorting\n");
                int inter=arr[j];
                arr[j]=arr[i];
                arr[i]=inter;
            }
            
        }
        
    }
    
}

int main(){
    int size;
    printf("Give me the size of the array:\n");
    scanf("%d",&size);
    int arr[size+1];
    createArray(arr,size);

    for (int i = 0; i < size; i++)
    {
        printf(" %d ",*(arr+i));
    }
    
    sort(arr,size);
    for (int i = 0; i < size; i++)
    {
        printf(" %d ",*(arr+i));
    }

    printf("Give me the input to be added:\n");
    scanf("%d",&arr[size]);
    sort(arr,size);
    for (int i = 0; i < size+1; i++)
    {
        printf(" %d ",*(arr+i));
    }
}