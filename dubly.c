#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
    int data;
    struct nod *prev, *next;
} node;

void insert_First(node **start, int data);
void insert_Last(node **start, int data);
void insert_Mid(node **start, int data, int pos);
void display(node *start);
int CountNode(node *start);

void insert_Mid(node **start, int data, int pos)
{
    int cn = CountNode(*start), i = 1;

    if (pos == 1)
    {
        insert_First(start, data);
        return;
    }
    if (pos > 1 && pos < cn)
    {
        node *temp, *prev, *newNode = (node *)malloc(sizeof(node));
        newNode->data = data;
        temp = *start;
        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        newNode->next = prev->next;
        newNode->prev = prev;
        prev->next = newNode;
        temp->prev = newNode;
        return;
    }
    if (pos >= cn)
    {

        insert_Last(start, data);
        return;
    }
}
void insert_First(node **start, int data)
{
    node *temp, *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (*start == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        *start = newNode;
    }
    else
    {
        temp = *start;
        newNode->next = *start;
        temp->prev = newNode;
        *start = newNode;
    }
}

void insert_Last(node **start, int data)
{
    node *temp, *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (*start == NULL)
    {
        newNode->prev = NULL;
        *start = newNode;
    }
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = NULL;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int CountNode(node *start)
{
    int count = 0;
    node *temp = start;
    if (start == NULL)
    {
        return 0;
    }
    while (start != NULL)
    {
        count++;
        start = start->next;
    }
    return count;
}

void display(node *start)
{
    node *temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    node *start = NULL;
    insert_Last(&start, 7);
    insert_Last(&start, 8);
    insert_First(&start, 6);
    insert_First(&start, 1);
    insert_Mid(&start, 3, 2);
    insert_Mid(&start, 2, 2);
    display(start);
    // printf("%d", CountNode(start));
    return 0;
}