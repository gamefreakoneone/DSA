#include<stdio.h>
#include<stdlib.h>

void getdata(int A[][3], int m, int n){ //We are passing the address
    int i,j;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
}

void putdata(int A[][3], int m, int n){
    int i,j;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ",A[i][j]);
        }
    printf("\n");
    }
}

int main(){
    int A[4][3];
    getdata(A,4,3);
    putdata(A,4,3);
}