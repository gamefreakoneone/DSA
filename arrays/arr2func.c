#include <stdio.h>

// int* fun(int *arr)
// {
//     /* Some operations on arr[] */
//     arr[0] = 10;
//     arr[1] = 20;

//     return arr;
// }

void getData(int B[], int n)
{
    printf(" ");
    for (int i; i < n; i++)
    {
        scanf("%d", B + i);
    }
}

void putData(int B[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", B[i]);
    }
}

int main()
{
    int arr[5];
    printf("Enter the elements:\n");
    getData(arr, 5);
    printf("Here are the elements:\n");
    putData(arr, 5);

    // int* ptr = fun(arr);
    // printf("%d %d", ptr[0], ptr[1]);
    return 0;
}