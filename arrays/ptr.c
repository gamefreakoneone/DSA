#include<stdio.h>
#include<stdlib.h>
void getdata(int *p, int n)
{
    int i;
    for (i=0;i<n;i++){
        scanf("%d",p+i);// Here p is the address therefore p+i will be the various addresses of the array
    }
}

void putdata(int *p,int n){
    int i;
    printf("--------\n");
    for(i=0;i<n;i++){
        printf("%d \n",p[i]);
    }
}
void main(){
    // int *p; // p can store the address of an integer i.e p is a pointer to integer variable.
    // int a=3;
    // // int *q // q can only store the address of an integer variable i.e q is a pointer to integer variable.
    // int **q;  // here q can store the address of pointers
    // p=&a;
    // q=&p;
    // printf("%d",**q);

// int *p;
// int a=3;
// p=&a;

// printf("%d \n",*p);
// p++;
// printf("%d",*p);

    int n;
    int *p;
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int)); //Reserving address
    getdata(p,n);
    putdata(p,n);
}