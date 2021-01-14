#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n)
{
    int temp, flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
}

int main()
{
    int a[] = {12, 2, 8, 5, 6, 1};
    int n = 6;
    bubble_sort(a,n);
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    
}