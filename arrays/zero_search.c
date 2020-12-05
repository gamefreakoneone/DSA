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

void rows(int A[][3], int m, int n){
    int selected[m+1],k=0;
    int truth;
    for (int i = 0; i < m; i++)
    {
        truth=0;
        for (int j = 0; j < n; j++)
        {
            if(A[i][j]==1){
                truth++;
            }
        }
        if(truth==0){
            selected[k]=i;
            k++;
        }
    }
    printf("\n**********\n");
    for (int i = 0; i < k; i++)
    {
        for(int j=0;j<n;j++){
            printf("%d",A[selected[i]][j]);
        }
        printf("\n");
    }
    
    printf("\n_________________\n");
    printf("The rows are:\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",selected[i]+1);
    }
    
}


int main(){
    int A[4][3];
    getdata(A,4,3);
    putdata(A,4,3);
    rows(A,4,3);
}