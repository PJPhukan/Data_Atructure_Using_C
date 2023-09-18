#include <stdio.h>
#include <stdlib.h>
struct nod
{
    int data;
    struct nod *next;
};
typedef struct nod node;
void insertNodeFirst(node **start, int data) ;
void insertNodeLast(node **start, int data);
void insertNodeMid(node **start,int pos,int data);
int countNode(node *start);
void display(node *start);



void insertNodeFirst(node **start, int data)
{
    node *temp, *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (*start == NULL)
    {
        *start = newNode;
        (*start)->next = *start;
        return;
    }
    temp = *start;
    while (temp->next != *start)
    {
        temp = temp->next;
    }
    newNode->next = *start;
    *start = newNode;
    temp->next = *start;
}

void insertNodeLast(node **start, int data)
{
    node *temp, *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (*start == NULL)
    {
        *start = newNode;
        (*start)->next = *start;
    }
    temp = *start;
    while (temp->next != *start)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertNodeMid(node **start,int pos,int data)
{
    int cn = countNode((*start));
    if(pos==1){
        insertNodeFirst(start,data);
        return ;
    }
    if(pos>1 && pos<cn){
        node *temp,*prev, *newNode = (node *)malloc(sizeof(node));
        newNode->data = data;
        int i=1;
        temp = *start;
        while (i<pos)
        {
            // prev=*start;
            prev=temp;
            temp=temp->next;
            i++;
        }
        newNode->next=prev->next;
        prev->next=newNode;
     return;   
    }
    if(pos>=cn){
        insertNodeLast(start,data);
        return;
    }
}
int countNode(node *start)
{
    if (start == NULL)
    {
        return 0;
    }
    int count = 0;
    node *temp = start;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != start);
    return count;
}
void display(node *start)
{

    if (start == NULL)
    {
        printf("Linked list is empty");
        return;
    }
    node *temp = start;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != start);
}

int main()
{
    node *start = NULL;
    insertNodeFirst(&start, 3);
    insertNodeFirst(&start, 4);
    insertNodeLast(&start, 5);
    insertNodeLast(&start, 4);
   
insertNodeMid(&start,2,18);
    
insertNodeMid(&start,5,18);
insertNodeMid(&start,1,18);
    insertNodeFirst(&start, 31);
insertNodeMid(&start,3,8);
    // printf("%d\n",cn);
    display(start);
    return 0;
}