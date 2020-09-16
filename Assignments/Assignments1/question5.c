#include<stdio.h>
#include<stdlib.h>

void shiftleft(int arr[],int *lengthofarray){
    int position,inter;
    printf("How many positions do you want to shift:");
    scanf("%d",&position);

for (int j = 0; j < position; j++)
{

        inter=arr[0];
        for(int i=0 ;i<*(lengthofarray)-1;i++){
            arr[i]=arr[i+1];
        }
        arr[*(lengthofarray)-1]=inter;
}
}

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

int main(){
    int position,arr[20],lengthofarray;
    scanf("%d",&lengthofarray);
    getdata(arr,&lengthofarray);
    readdata(arr,lengthofarray);
    shiftleft(arr,&lengthofarray);
    readdata(arr,lengthofarray);
}