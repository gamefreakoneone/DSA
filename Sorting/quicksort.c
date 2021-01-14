#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int beg, int end)
{
    int left, right, temp, loc, flag = 0;
    loc = temp = beg;
    right = end;
    while (flag != 1)
    {
        while (a[loc] <= a[right] && (loc != right))
            right--;
        if (loc == right)
            flag = 1;
        else if (a[loc] > a[right])
        {
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right;
        }
        if (flag != 1)
        {
            while ((a[loc] >= a[left]) && (loc != left))
                left++;

            if (loc == left)
                flag = 1;
            else if (a[loc] < a[left])
            {
                temp = a[loc];
                a[loc] = a[left];
                a[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}

void quick_sort(int *a, int beg, int end)
{
    int loc;
    if (beg < end)
    {
        loc = partition(a, beg, end);
        quick_sort(a, beg, loc - 1);
        quick_sort(a, loc + 1, end);
    }
}

int main()
{
    int a[] = {12, 2, 8, 5, 6, 1};
    int n = 6;
    quick_sort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}