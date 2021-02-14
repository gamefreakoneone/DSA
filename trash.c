#include<stdio.h>

int main() 
{ 
    char str[] = "TO"; 
    int i; 
    for(i=0; str[i]; i++) 
    printf("\n%c%c%c",  *(str+i), *(i+str), i[str] ); 
     
    getchar(); 
    return 0; 
}