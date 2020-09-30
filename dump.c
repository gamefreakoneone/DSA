#include<stdio.h>
int main()
{int *ptr;
int arr[2][3] ={9,12,13,22,30,24};
ptr=arr;
*ptr = *ptr + 4;
printf("
output is %u",*ptr);
}