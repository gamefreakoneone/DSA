#include <stdio.h>
#include <malloc.h>

struct node
{
    int num;
    int coeff;
    struct node *next;
};

struct node *create_poly(struct node *start)
{
    struct node *new_node, *ptr;
    int n, c;
    printf("\n Enter the power (To exit type -1) : ");
    scanf("%d", &n);
    printf("\nEnter its coefficient : ");
    scanf("%d", &c);
    while (n != -1)
    {
        if (start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->num = n;
            new_node->coeff = c;
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->num = n;
            new_node->coeff = c;
            new_node->next = NULL;
            ptr->next = new_node;
        }
        printf("\n Enter the power : ");
        scanf("%d", &n);
        if (n == -1)
            break;
        printf("\n Enter its coefficient : ");
        scanf("%d", &c);
    }
    return start;
}

void display_poly(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("\n%d x %d\t", ptr->num, ptr->coeff);
        ptr = ptr->next;
    }
}

struct node *add_poly(struct node *start1, struct node *start2, struct node *start3)
{
    struct node *ptr1, *ptr2;
    int sum_num, c;
    ptr1 = start1, ptr2 = start2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->coeff == ptr2->coeff)
        {
            sum_num = ptr1->num + ptr2->num;
            start3 = add_node(start3, sum_num, ptr1->coeff);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->coeff > ptr2->coeff)
        {
            start3 = add_node(start3, ptr1->num, ptr1->coeff);
            ptr1 = ptr1->next;
        }
        else if (ptr1->coeff < ptr2->coeff)
        {
            start3 = add_node(start3, ptr2->num, ptr2->coeff);
            ptr2 = ptr2->next;
        }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            start3 = add_node(start3, ptr2->num, ptr2->coeff);
            ptr2 = ptr2->next;
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            start3 = add_node(start3, ptr1->num, ptr1->coeff);
            ptr1 = ptr1->next;
        }
    }
    return start3;
}

// void polyadd(struct node* poly1, struct node* poly2,
//              struct node* poly)
// {
//     while (poly1->next && poly2->next) {
//         // If power of 1st polynomial is greater then 2nd,
//         // then store 1st as it is and move its pointer
//         if (poly1->num > poly2->num) {
//             poly->num = poly1->num;
//             poly->coeff = poly1->coeff;
//             poly1 = poly1->next;
//         }
 
//         // If power of 2nd polynomial is greater then 1st,
//         // then store 2nd as it is and move its pointer
//         else if (poly1->num < poly2->num) {
//             poly->num = poly2->num;
//             poly->coeff = poly2->coeff;
//             poly2 = poly2->next;
//         }
 
//         // If power of both polynomial numbers is same then
//         // add their coefficients
//         else {
//             poly->num = poly1->num;
//             poly->coeff = poly1->coeff + poly2->coeff;
//             poly1 = poly1->next;
//             poly2 = poly2->next;
//         }
 
//         // Dynamically create new node
//         poly->next
//             = (struct node*)malloc(sizeof(struct node));
//         poly = poly->next;
//         poly->next = NULL;
//     }
//     while (poly1->next || poly2->next) {
//         if (poly1->next) {
//             poly->num = poly1->num;
//             poly->coeff = poly1->coeff;
//             poly1 = poly1->next;
//         }
//         if (poly2->next) {
//             poly->num = poly2->num;
//             poly->coeff = poly2->coeff;
//             poly2 = poly2->next;
//         }
//         poly->next
//             = (struct node*)malloc(sizeof(struct node));
//         poly = poly->next;
//         poly->next = NULL;
//     }
// }

struct node *add_node(struct node *start, int n, int c)
{
    struct node *ptr, *new_node;
    if (start == NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->num = n;
        new_node->coeff = c;
        new_node->next = NULL;
        start = new_node;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->num = n;
        new_node->coeff = c;
        new_node->next = NULL;
        ptr->next = new_node;
    }
    return start;
}

int main(){
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *poly3 = NULL;

    printf("Enter the fist polynomial:\n");
    poly1 = create_poly(poly1);
    printf("Displayng the first polynomial:\n");
    display_poly(poly1);
    printf("Enter the second polynomial:");
    poly2 = create_poly(poly2);
    printf("Displaying the second polynomial:\n");
    display_poly(poly2);
    printf("Adding the two polynomials:");
    poly3=add_poly(poly1,poly2,poly3);
    printf("The result is:\n");
    display_poly(poly3);
}