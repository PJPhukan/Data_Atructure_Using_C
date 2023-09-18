#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node bt;
int insert(bt **root, int data);
int inorder(bt *root);
void search(bt *root, int key);


void search(bt *root, int key){
    if (root != NULL){
        if (root->data == key){
            printf("\nItem found");
            return;
        }
        else{
            root->data > key ? search(root->left, key) : search(root->right, key);
        }
    }
    else{
        printf("\nItem not found");
    }
}
void non_recursive_search(bt *root, int key){
    while (root != NULL){
        if (root->data == key){
            printf("\nItem found");
            return;
        }
        else{
            root = root->data > key ? root->left : root->right;
        }
    }
    printf("\nItem not found");
}
int inorder(bt *root){
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        inorder(root->left);
        printf("%d \t", root->data);
        inorder(root->right);
    }
}
int insert(bt **root, int data){
    bt *temp, *loc, *prev;
    temp = (bt *)malloc(sizeof(bt));
    temp->data = data;
    temp->left = temp->right = NULL;

    if (*root == NULL)
    {
        *root = temp;
        return 1;
    }
    else
    {
        for (loc = *root, prev = NULL; loc != NULL && loc->data != data;)
        {
            prev = loc;
            loc = loc->data > data ? loc->left : loc->right;
        }
        if (loc != NULL)
        {
            if (loc->data == data)
            {
                printf("Already %d exist in the tree \n", data);
            }
            return 0;
        }
        if (prev->data > data){
            prev->left = temp;
            return 0;
        }
        else{
            prev->right = temp;
            return 0;
        }
    }
}


int main()
{
    bt *root = NULL;
    insert(&root, 1);
    insert(&root, 9);
    insert(&root, 6);
    insert(&root, 4);
    // insert(&root, 6);
    insert(&root, 7);
    inorder(root);
    // search(root, 5);
    // non_recursive_search(root, 7);
    Delete(root, 1);
    inorder(root);
    return 0;
}