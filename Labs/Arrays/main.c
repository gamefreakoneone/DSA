#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void getdata(int *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i); // Here p is the address therefore p+i will be the various addresses of the array
    }
}

void putdata(int *p, int n)
{
    int i;
    printf("--------\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \n", p[i]);
    }
}

// int compare(int a, int b){
//     if(a==b){
//         return 1;
//     }else{
//         return 0;
//     }
// }

void insert_element(int *p, int *size, int element, int position)
{
    for (int i = (*size) - 1; i >= (position - 1); i--)
    {
        p[i + 1] = p[i];
    }
    p[position - 1] = element;
    *size += 1;
}

void delete_element(int *p, int *size, int position)
{
    for (int i = position; i < (*size) - 1; i++)
    {
        p[i] = p[i + 1];
    }
}

void linear_search(int to_find, int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (to_find == p + i)
        {
            printf("Found the element!");
            return;
        }
    }
    printf("The element is not available on the array!");
    return;
}

void binary_search(int *p, int to_find, int low, int high)
{
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        if (p[mid] == to_find)
        {
            printf("Found it!! at location %d of the array", (mid - 1));
        }
        else if (p[mid] < to_find)
        {
            low = mid + 1;
        }
        else if (p[mid] > to_find)
        {
            high = mid - 1;
        }
    }
    printf("The element could not be found!");
    return;
}

int smallest(int *a, int k, int n)
{
    int small = a[k], pos = k;
    for (int i = k + 1; i < n; i++)
    {
        if (a[i] < small)
        {
            small = a[i];
            pos = i;
        }
    }
    return pos;
}

void selection_sort(int *a, int n)
{
    int k, pos, temp;
    for (int i = 0; i < n; i++)
    {
        pos = smallest(a, i, n);
        temp = a[pos];
        a[pos] = a[i];
        a[i] = temp;
    }
}

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
    int size;
    int *arr, true = 1, choice, element, position;

    printf("Give me the size of the array:\n");
    scanf("%d", &size);

    arr = (int *)malloc(MAX * sizeof(int));
    getdata(arr, size);

    while (true == 1)
    {
        printf("What do you want to do:\n");
        printf("1.)Selection Sort\n2.)Bubble sort\n3.)Binary Search\n4.)Linear Search\n5.)Insert an element\n6.)Delete an element\n7.)Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Selection sort!\n");
            selection_sort(arr, size);
            putdata(arr, size);
            break;
        case 2:
            printf("Bubble sort!\n");
            bubble_sort(arr, size);
            putdata(arr, size);
            break;
        case 3:
            printf("Binary Search!\n");
            printf("What do you want to find?\n");
            scanf("%d", &element);
            binary_search(arr, element, 0, size);
            break;
        case 4:
            printf("Linear Search!\n");
            printf("What do you want to find?\n");
            scanf("%d", &element);
            linear_search(element, arr, size);
            break;
        case 5:
            printf("Inserting an element!\n");
            printf("Which element do you want to add:\n");
            scanf("%d", &element);
            printf("Which position:\n");
            scanf("%d", &position);
            insert_element(arr, &size, element, position);
            putdata(arr, size);
            break;
        case 6:
            printf("Deleting an element!\n");
            printf("Which position do you want to delete:\n");
            scanf("%d", &position);
            delete_element(arr, &size, position);
            break;
        case 7:
            printf("Thank you!");
            true = 0;
            break;
        default:
            printf("Soemthing went wrong");
            break;
        }
    }
}