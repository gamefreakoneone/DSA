#include<stdio.h>
#include<stdlib.h>

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

int main(){
    int a[] = {12, 2, 8, 5, 6, 1};
    int n = 6;
    insertion_sort(a,n);
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}