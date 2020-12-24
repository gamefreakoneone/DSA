#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode * leftchild;
    struct TreeNode * rightchild;
} Node;

Node * CreateNode(int item){
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
    printf("Give me the first value:\n");
    scanf("%d",&values);
    root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data=values;
    root->leftchild=NULL;
    root->rightchild=NULL;

    int cont =1;
    int itema;

    while (cont!=0)
    {
        Node *current, * parent =NULL;
        current=root;
        printf("Give me child value:\n");
        scanf("%d",&itema);
        printf("Check 1");
        while (current!=NULL)
        {
            parent=current;
            if(itema<parent->data){
                current=parent->leftchild;
            }else if (itema>parent->data)
            {
                current=parent->rightchild;
            }else{
                printf("Duplicate value!\n");
                break;
            }
        }
        if (itema<parent->data)
        {
            current->leftchild=CreateNode(itema);
        }else if (itema>parent->data)
        {
            current->rightchild=CreateNode(itema);
        }
        printf("Want to continue: (Type -1 to exit) \n");
        scanf("%d",&cont);
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