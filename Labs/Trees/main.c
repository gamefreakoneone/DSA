#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
Node *insert_node(int item);
Node *createTree();
int TotalNodes(Node *root);
int height(Node *root);
Node *delete (Node *root, int value);
Node *findsmallestelement(Node *tree);
Node *findlargestelement(Node *tree);
Node *search(Node *root, int key);

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

Node *insert_node(int item)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->value = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *createTree()
{
    Node *root;
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
                exit(1);
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

Node * insertion(Node * root){
        int item;
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
        return root;
}

Node *delete (Node *root, int value)
{
    Node *temp;
    if (root == NULL)
    {
        return root;
    }

    if (value < root->value)
    {
        return delete (root->left, value);
    }
    else if (value > root->value)
    {
        return delete (root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findsmallestelement(root->left);

        root->value = temp->value;

        root->right = delete (root->right, temp->value);
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

Node *search(Node *root, int key)
{
    if (root == NULL)
    {
        printf("Not found!\n");
        return NULL;
    }

    if (root->value == key)
    {
        printf("Found the root! %d \n", root->value);
        return root;
    }

    if (key > root->value)
    {
        return search(root->right, key);
    }

    return search(root->left, key);
}

int main()
{
    Node *root;
    Node *result;
    printf("Let us create a Tree:\n");
    root = createTree();
    int truth = 1, option, pls;
    while (truth == 1)
    {
        printf("What do you want to do:\n");
        printf("1.)Traverse Preorder\n");
        printf("2.)Traverse Inorder\n");
        printf("3.)Traverse Postorder\n");
        printf("4.)Search\n");
        printf("5.)Largest Element:\n");
        printf("6.)Smallest Element:\n");
        printf("7.)Delete a node\n");
        printf("8.)Insertion of a node\n");
        printf("9.)Exit\n");
        printf("What do you want to do: \n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 2:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("what do you want to search?\n");
            scanf("%d", &pls);
            result = search(root, pls);
            break;
        case 5:
            printf("%d is the largest of the tree.\n", findlargestelement(root)->value);
            break;
        case 6:
            printf("%d is the smallest element of the tree.\n", findsmallestelement(root)->value);
            break;
        case 7:
            printf("What would you like to delete:\n");
            scanf("%d", &pls);
            root = delete (root, pls);
            break;
        case 8:
            root = insertion(root);
            break;
        case 9:
            printf("Done!");
            exit(1);
        default:
            printf("Something went wrong!\n");
            break;
        }
    }

    // printf("Preorder: ");
    // preorder(root);
    // printf("\n");
    // printf("Inorder: ");
    // inorder(root);
    // printf("\n");
    // printf("Postorder: ");
    // postorder(root);
    // printf("\n");
    // int numberofNodes = TotalNodes(root);
    // printf("%d is the total number of nodes!\n", numberofNodes);
    // printf("%d is the height of the tree.\n", height(root));
    // printf("%d is the largest of the tree.\n", findlargestelement(root)->value);
    // printf("%d is the smallest element of the tree.\n", findsmallestelement(root)->value);

    // printf("what do you want to search?\n");
    // scanf("%d", &pls);
    // result = search(root, pls);
}