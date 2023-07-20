#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *right;
    struct node *left;
    int height;   
    
};

typedef struct node node;

int height(node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return N -> height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}


//allocation of new node
node *newnode(int key)
{   
    node * N = (node *)malloc(sizeof(node));
    N->key = key;
    N->left = NULL;
    N->right = NULL;
    N->height = 1;
    return(N);
}


//single right rotation
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->height = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;

}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(node *N)
{
    if(N == NULL)
    {
        return 0;
    }
    return height(N->left) - height(N->right);
}

node *insert(node *n, int key)
{
    if (n == NULL)
    {
        return(newnode(key));
    }
    if (key < n->key)
    {
        n->left = insert(n -> left, key);
    }
    else if (key > n-> key)
    {
        n->right = insert(n -> right, key);
    }
    else
    {
        return n;
    }

    n->height = 1 + max(height(n->left), height(n->right));

    int balance = getBalance(n);

    if (balance > 1 && key < n-> left->key)
    {
        return rightRotate(n);
    }
    if (balance > -1 && key>n->right->key)  
    {
        return leftRotate(n);
    }
    if (balance > 1 && key> n->left->key)
    {
        n->left = leftRotate(n->left);
        return leftRotate(n);
    }

    return n;    
    
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 100);

    printf("Preorder traversal of the constructed AVL is \n");
    preOrder(root);

    return 0;
}
