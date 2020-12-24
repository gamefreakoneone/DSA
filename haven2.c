#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode * leftchild;
    struct TreeNode * rightchild;
} Node;

Node * insert_node(int item){
    Node* temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data=item;
    temp->leftchild=NULL;
    temp->rightchild=NULL;
    return temp;
}

Node * CreateTree(){
    Node * root;
    int values;
    printf("Give us the first value:\n");
    scanf("%d",&values);
    root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data=values;
    root->leftchild=NULL;
    root->rightchild=NULL;
    int c=1;
    int item;

    while (c!=0)
    {
        Node *current, * parent =NULL;
        current=root;
        printf("Give me child value:\n");
        scanf("%d",&item);
        while (current!=NULL)
        {
            parent=current;
            if(item<parent->data){
                printf("Current is parent left\n");
                current=parent->leftchild;
            }else if (item>parent->data)
            {
                printf("Current is parent right\n");
                current=parent->rightchild;
            }else{
                printf("Duplicate value!\n");
                break;
            }
        }
        if(item<parent->data){
            current=insert_node(item);
        }else if(item>parent->data){
            current=insert_node(item);
        }
        printf("Wanan continue:\n");
        scanf("%d",&c);
    }

    return root;
}

void preorder(Node * root){
    while (root!=NULL)
    {
        printf(" %d ",root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

int main(){
    Node * root;
    root= CreateTree();
    preorder(root);
}

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct TreeNode{
//     int value;
//     struct TreeNode * left;
//     struct TreeNode *right;
// } Node;

// Node * insert_node(int item){
//     Node *temp;
//     temp = (Node *)malloc(sizeof(Node));
//     temp->value=item;
//     temp->left=NULL;
//     temp->right=NULL;
//     return temp;
// }

// Node * CreateTree(){
//     Node * root;
//     int values;
//     printf("Give us the first value:\n");
//     scanf("%d",&values);
//     root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
//     root->value=values;
//     root->left=NULL;
//     root->right=NULL;
//     int c=1;
//     int item;
//     while (c!=0)
//     {
//         Node * current, *parent = NULL;
//         current=root;
//         printf("Give a child value:\n");
//         scanf("%d",&item);
//         while (current!=NULL)
//         {
//             parent=current;
//             if(item<parent->value){
//                 current=parent->left;
//             }else if (item>parent->value)
//             {
//                 current=parent->right;
//             }
//             else{
//                 printf("Duplicate value\n");
//                 break;
//             }
//         }
//         if(item<parent->value){
//             parent->left=insert_node(item);
//         }else if(item>parent->value){
//             parent->right=insert_node(item);
//         }
//         printf("Wanan continue:\n");
//         scanf("%d",&c);
//     }

//     return root;
// }

// void preorder(Node * root){
//     while (root!=NULL)
//     {
//         printf(" %d ",root->value);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// int main(){
//     Node * root;
//     root= CreateTree();
//     preorder(root);
// }