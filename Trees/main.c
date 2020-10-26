#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int value;
    struct TreeNode * left;
    struct TreeNode *right;
} Node;

Node * insert_node(int item){
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->value=item;
    temp->left=NULL;
    temp->right=NULL;
}

void inorder(Node * root){
    if(root!=NULL){
        inorder(root->left);
        printf(" %d ",root->value);
        inorder(root->right);
    }
}

int main(){
    Node * root;
    int values;
    printf("Give us the value:\n");
    scanf("%d",&values);
    root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->value=values;
    root->left=NULL;
    root->right=NULL;
    int c=1;
    int item;
    while (c!=0)
    {
        Node * current, *parent = NULL;
        current=root;
        printf("Give value:\n");
        scanf("%d",&item);
        while (current!=NULL)
        {
            parent=current;
            if(item<parent->value){
                current=parent->left;
            }else if (item>parent->value)
            {
                current=parent->right;
            }
            else{
                printf("Duplicate value\n");
                break;
            }
        }
        if(item<parent->value){
            parent->left=insert_node(item);
        }else if(item>parent->value){
            parent->right=insert_node(item);
        }
        printf("Wanan continue:\n");
        scanf("%d",&c);
    }

    inorder(root);
    printf("\n");
}