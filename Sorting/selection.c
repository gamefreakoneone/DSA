#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int a[] = {12, 3, 87, 2, 25, 11};
    int n = 6;
    selection_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}