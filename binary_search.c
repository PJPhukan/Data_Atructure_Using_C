#include <stdio.h>
#include <stdlib.h>

struct nod
{
    int data;
    struct nod *left, *right;
};
typedef struct nod node;

int insert_binary(node **root, int item);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);

int main()
{
    node *root=NULL;
    insert_binary(&root,7);
    insert_binary(&root,4);
    insert_binary(&root,8);
    insert_binary(&root,3);
    insert_binary(&root,5);
    insert_binary(&root,2);
    insert_binary(&root,1);
    insert_binary(&root,11);
    insert_binary(&root,9);
    printf("preorder  :");
    preorder(root);
    printf("\n");
    printf("Inorder  :");
    inorder(root);
    printf("\n");
    printf("postorder  :");
    postorder(root);
    printf("\n");

    return 0;
}
int insert_binary(node **root, int item)
{
    node *newnode, *loc, *par;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    if (*root == NULL)
    {
        *root = newnode;
        return 0;
    }
    else
    {
        for (loc = *root, par = NULL; loc != NULL && loc->data != item;)
        {
            par = loc;
            loc = loc->data < item ? loc->right : loc->left;
        }
        if (loc != NULL)
        {
            printf("insert value already exist");
            return 0;
        }
        if (par->data > item)
        {
            par->left = newnode;
        }
        else
        {
            par->right = newnode;
        }
    }
}


void preorder(node *root){
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("  %d ", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}


void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("  %d ", root->data);
        inorder(root->right);
    }
}


void postorder(node *root){
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        inorder(root->right);
        printf("  %d ", root->data);
    }
}