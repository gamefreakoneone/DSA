#include<stdio.h>

int main(){
    int a[5]; // Basically when a[5] is initialized, a by itself becomes an address which we can refer through pointer * or good ol a[i]
    for(int i=0; i<5;i++){
        scanf("%d",&a[i]);// here a+i refers to the address. This is similar to &a[i]. Here i means it goes to the next location
    }

    for(int i=0;i<5;i++){
        printf("%d",*(a+i));//Value will gets defreferenced with *
    }


    for(int i=0;i<5;i++){
        scanf("%d",&i[a]); // This does not mean that i is an array. Here a is the base address.
    }

    for(int i=0;i<5;i++){
        printf("%d",i[a]);
    }
    
}
