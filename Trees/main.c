#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

Node *insert_node(int item)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->value = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->value);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->value);
    }
}

int TotalNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (TotalNodes(root->left) + TotalNodes(root->right) + 1);
    }
}

int height(Node *root)
{
    int leftheight, rightheight;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        leftheight = height(root->left);
        rightheight = height(root->right);
        if (leftheight > rightheight)
        {
            return (leftheight + 1);
        }
        else
        {
            return (rightheight + 1);
        }
    }
}

Node *delete (Node *root, int value)
{
    Node *temp;
    if (root==NULL){
        return root;
    }

    if(value<root->value){
        return delete(root->left,value);
    }else if (value>root->value)
    {
        return delete(root->right,value);
    }
    else
    {
        if(root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }

        temp=findsmallestelement(root->left);

        root->value=temp->value;

        root->right=delete(root->right, temp->value);
    }
    return root;
}

Node *findsmallestelement(Node *tree)
{
    if (tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return findsmallestelement(tree->left);
    }
}

Node *findlargestelement(Node *tree)
{
    if (tree == NULL || tree->right == NULL)
    {
        return tree;
    }
    else
    {
        return findlargestelement(tree->right);
    }
}

Node *createTree()
{
    Node * root;
    int values;
    printf("Give us the value:\n");
    scanf("%d", &values);
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->value = values;
    root->left = NULL;
    root->right = NULL;
    int c = 1;
    int item;
    while (c != 0)
    {
        Node *current, *parent = NULL;
        current = root;
        printf("Give value:\n");
        scanf("%d", &item);
        while (current != NULL)
        {
            parent = current;
            if (item < parent->value)
            {
                current = parent->left;
            }
            else if (item > parent->value)
            {
                current = parent->right;
            }
            else
            {
                printf("Duplicate value\n");
                break;
            }
        }
        if (item < parent->value)
        {
            parent->left = insert_node(item);
        }
        else if (item > parent->value)
        {
            parent->right = insert_node(item);
        }
        printf("Wanan continue:\n");
        scanf("%d", &c);
    }
    return root;
}

Node * search(Node * root, int key){
    if(root == NULL){
    printf("Not found!");
        return NULL;
    }

    if (root->value==key){
        printf("Found the root! %d ", root->value);
        return root;
    }

    if(key>root->value){
        return search(root->right,key);
    }

    return search(root->left,key);
}

int main()
{
    Node *root;
    root=createTree();
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    int numberofNodes = TotalNodes(root);
    printf("%d is the total number of nodes!\n", numberofNodes);
    printf("%d is the height of the tree.\n",height(root));
    printf("%d is the largest of the tree.\n",findlargestelement(root)->value);
    printf("%d is the smallest element of the tree.\n",findsmallestelement(root)->value);

int pls;
    Node * result;
    printf("what do you want to search?\n");
    scanf("%d",&pls);
    result=search(root, pls);
}