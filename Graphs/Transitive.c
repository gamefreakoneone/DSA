#include <stdio.h>
#include <stdlib.h>

void mult(int A[][10], int A1[][10], int result[][10],int n){
    for (int i = 0; i < n; i++)
    {
        for(int j = 0;j<n;j++){
            result[i][j]=0;
            for(int k=0;k<n;k++){
                result[i][j]=result[i][j] || A[i][k]*A1[k][j];
            }
        }
    }
    
}

void copy(int A[][10], int A1[][10], int result[][10], int path[][10], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            A1[i][j]=result[i][j];
            path[i][j]=path[i][j] || result[i][j];
        }
    }
}

void adj(int A[][10], int n)
{
    printf("Adjoint:\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d ", A[i][j]);
        }
    printf("\n");
    }
    printf("______________________________\n");
}

void trans(int A[][10], int path[][10], int n){
    int A1[10][10], result[10][10]={0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A1[i][j]=A[i][j];
            path[i][j]=A[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        adj(A1,n);
        mult(A,A1,result,n);
        copy(A,A1,result,path,n);
    }
    
}

void clos(int A[][10], int result[][10], int n){
    int i,j,k;
    for(i = 0;i<n;i++){
        for(j=0;j<n;j++){
            result[i][j]=A[i][j];
        }
    }

    for( k = 0; k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                result[i][j]=result[i][j]||result[i][k]*result[k][j];
            }
        }
    }
    adj(result,n);
}

void graph(int A[][10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nPath from Node %d -> Node %d : ",i+1,j+1);
            scanf("%d", &A[i][j]);
        }
    }
}

int main()
{
    int A[10][10], path[10][10], result[10][10];
    int n = 4;

    graph(A, n);
    printf("\nAdjacency Matrix:\n");
    adj(A, n);
    printf("\n");
    trans(A, path, n);
    printf("Transitive Closure:\n");
    adj(A, n);
    printf("Transtive Closure:\n");
    clos(A, result,n);
}