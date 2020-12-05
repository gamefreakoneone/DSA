#include<stdio.h>
#include<stdlib.h>

void getdata(int *p,int n){
    int input;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",p+i);
    }
    
}

void putdata(int *p, int size){
    for (int i = 0; i < size; i++)
    {
        printf("\n%d",*(p+i));
    }
}

int Largest(int *p, int size){
    int max=*p;
    for (int i = 0; i < size; i++)
    {
        if (*(p+i)>max)
        {
            max=*(p+i);
        }
    }
    return max;
}

void half(int *p, int size){
    int first=size/2;
    int second= size -first;
    int *arr1, *arr2;
    arr1=(int *)malloc(first*sizeof(int));
    arr2=(int *)malloc(second*sizeof(int));
    
    for (int i = 0; i < first; i++)
    {
        *(arr1+i)=*(p+i);
    }
    
    for (int i = 0,j=first; i < second; i++,j++)
    {
        *(arr2+i)=*(p+j);
    }
    int max1 = Largest(arr1, first);
    int max2=Largest(arr2, second);

    if (max1>max2)
    {
        printf("\n%d is the greatest number!\n",max1);
    }else if (max2>max1)
    {
        printf("\n%d is the greatest number!\n",max2);
    }else
    {
        printf("\n%d is the greates number!\n",max1);
    }
}

int main(){
    int *p;
    int size;
    printf("The size of the array is:\n");
    scanf("%d",&size);
    p=(int *)malloc(size*sizeof(int));
    getdata(p,size);
    putdata(p,size);
    half(p,size);
}