#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int rollno;
    char name[20];
};

struct student getdata(struct student *x){
    x->rollno=24;
    strcpy(x->name,"Amogh");
}

void putdata(struct student x){
    printf("%d \n",x.rollno);
    printf("%s",x.name);
}


int main()
{
    struct student x,y; // you have to mention struct aldo x only exists in main()
    getdata(&x);
    putdata(x);
    
}