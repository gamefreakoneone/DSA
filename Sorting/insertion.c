#include<stdio.h>
#include<stdlib.h>
#define size 100

void insertion_sort(int *arr, int n){
    int i, j, temp;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j=i-1;
        while ((temp<arr[j]) && (j>=0) )
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    
}

void display(int *a, int n){
for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}

int main(){
    int arr[size], i, n;

    printf("\n Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("\n Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int a[] = {134, 12, 84, 15, 6, 11};
    insertion_sort(a,n);
    display(a,n);
}