#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10

int deque[MAX];
int left=-1, right=-1;

void input_deque(void);
void output_deque(void);
void insert_left(void);
void insert_right(void);
void delete_left(void);
void display(void);

int main(){
    int option;
    printf("Menu\n");
    printf("1.Input restricted deque:\n");
    printf("2.Output restricted deque\n");
    printf("Enter your option:");
    switch(option){
        case 1:
            input_deque();
            break;
        case 2:
            output_deque();
            break;
    }
    return 0;
}

void input_deque(){
    int option;
    do{
        printf("\n Input Restricted Deque:\n");
        printf("\n1.Insert at right");
        printf("\n2.Delete from left");
        printf("\n3.Delete from right");
        printf("\n4.Display");
        printf("\n5.Quit");
        printf("\n Enter your option:");
        scanf("%d",&option);

        switch(option){
            case 1:
                insert_right();
                break;
            case 2:
                delete_left();
                break;
            case 3:
                delete_right();
                break;
            case 4:
                display();
                break;
        }
    }while(option!=5);
}

void output_deque(){
        int option;
    do{
        printf("\n O utput Restricted Deque:");
        printf("\n1.Insert at right");
        printf("\n2.Insert at left");
        printf("\n3.Delete from left");
        printf("\n4.Display");
        printf("\n5.Quit");
        printf("\n Enter your option:");
        scanf("%d",&option);

        switch(option){
            case 1:
                insert_right();
                break;
            case 2:
                insert_left();
                break;
            case 3:
                delete_left();
                break;
            case 4:
                display();
                break;
        }
    }while(option!=5);
}

void insert_right(){
    int val;
    printf("");
}