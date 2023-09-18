#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int data;
    struct nod *next;
} node;

void insertQ(node **queue, int item);
void deleteQ(node **queaue);
void display(node *queue);
int main()
{
    node *queue = NULL;
    for (int i = 0; i < 10; i++)
    {
        insertQ(&queue, rand() % 20);
    }
    // insertQ(&queue, 5);
    // insertQ(&queue, 1);
    display(queue);
    deleteQ(&queue);
    printf("\n");
    display(queue);

    return 0;
}
void insertQ(node **queue, int item)
{
    node *newnode, *temp = *queue;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->next = NULL;
    if (*queue == NULL)
    {
        *queue = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void deleteQ(node **queaue)
{
    if (*queaue != NULL)
    {
        node *temp;
        temp = *queaue;
        *queaue = (*queaue)->next;
        printf("\nPopped element is : %d", temp->data);
        free(temp);
    }
    else
    {
        printf("\n Queue is empty ;");
    }
}

void display(node *queue)
{
    // if (queue != NULL)
    // {
    while (queue != NULL)
    {
        printf("   %d \t", queue->data);
        queue = queue->next;
    }
    // }
    //  else
    // {
    //     printf("\n Queue is empty ;");
    // }
}