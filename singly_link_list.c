#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int data;
    struct nod *next;
} node;

void Create_sll(node **start, int n);
void Display(node *t);
int Count(node *start);
void insert_at_begging(node **start, int item);
void insert_at_end(node **start, int item);
void insert_at_mid(node **start, int pos, int item, int ct);
void delete_at_begging(node **start);
void delete_at_end(node **start);
void delete_at_mid(node **start, int pos, int ct);
void Searching(node **start, int item);
void Concat(node **start1, node **start2);
int insert_sort(node **start, int item);
void Marge(node **start1, node **start2, node **marge);

// MAIN FUNCTION

int main()
{
    node *start = NULL, *start1 = NULL, *marge = NULL;
    int ct;
    // Create_sll(&start, 3);
    for (int i = 0; i < 5; i++)
    {
        insert_sort(&start, rand() % 100);
    }
    for (int i = 0; i < 5; i++)
    {
        insert_sort(&start1, rand() % 100);
    }
    Marge(&start, &start1, &marge);
    // for (int i = 0; i < 5; i++)
    // {
    //     insert_at_end(&start, rand() % 20);
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     insert_at_begging(&start1, rand() % 20);
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     insert_at_end(&start1, rand() % 20);
    // }
    // ct = Count(start);
    Display(start);
    printf("\n");
    Display(start1);
    printf("\n");
    Display(marge);
    // Display(start1);
    // Searching(&start,18);
    //   Concat(&start,&start1);
    printf("\n");
    // Display(start);
    // ct = Count(start);
    // Display(start);
    // printf("Total node : %d", ct);
    // insert_at_mid(&start, 2, 1000, ct);
    // delete_at_begging(&start);
    // ct = Count(start);
    // printf("Total node : %d", ct);
    // delete_at_end(&start);
    // delete_at_mid(&start, 3, ct);
    // printf("Total node : %d", ct);

    return 0;
}

//MARGE TWO LINKED LIST

void Marge(node **start1, node **start2, node **marge)
{
    node *p1, *p2;
    for (p1 = *start1, p2 = *start2; p1 != NULL && p2 != NULL;)
    {

        if (p1->data < p2->data)
        {
            insert_at_end(marge, p1->data);
            p1 = p1->next;
        }
        else
        {
            insert_at_end(marge, p2->data);
            p2 = p2->next;
        }
    }
    for (; p1 != NULL; p1 = p1->next)
    {
        insert_at_end(marge, p1->data);
    }
    for (; p2 != NULL; p2 = p2->next)
    {
        insert_at_end(marge, p2->data);
    }
}

// INSERT SHORTED

int insert_sort(node **start, int item)
{
    node *newnnode, *prev;
    newnnode = (node *)malloc(sizeof(node));
    if (newnnode == NULL)
    {
        return 0;
    }
    newnnode->data = item;
    if (*start == NULL)
    {
        *start = newnnode;
        newnnode->next = NULL;
        return 1;
    }
    if ((*start)->data > item)
    {
        newnnode->next = *start;
        *start = newnnode;
        return 1;
    }
    else
    {
        for (prev = *start; prev->next != NULL && prev->next->data < item; prev = prev->next)
            ;
        newnnode->next = prev->next;
        prev->next = newnnode;
        return 1;
    }
}

// CONCAT TWO LINKED LIST

void Concat(node **start1, node **start2)
{
    node *temp1 = *start1, *temp2 = *start2;
    if (temp1 == NULL)
    {
        temp1 = temp2;
    }
    else
    {
        while ((temp1)->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp2;
    }
}

// SEARCHING A SPECIFIC ITEM

void Searching(node **start, int item)
{
    int pos = 1;
    node *temp = *start;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("position is :%d", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Item not found");
}

// INSERT AT THE BEGGING

void insert_at_begging(node **start, int item)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->next = NULL;
    if (*start == NULL)
    {
        *start = newnode;
    }
    else
    {
        newnode->next = *start;
        *start = newnode;
    }
}

// INSERT AT THE END

void insert_at_end(node **start, int item)
{
    node *temp, *newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->next = NULL;
    if (*start == NULL)
    {
        *start = newnode;
    }
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// INSERT AT A SPECIFIC POSITION

void insert_at_mid(node **start, int pos, int item, int ct)
{
    int i = 1;
    if (pos < ct && pos > 1)
    {
        node *temp, *newnode = (node *)malloc(sizeof(node));
        temp = *start;
        newnode->data = item;
        newnode->next = NULL;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("Invalid position ");
        exit(0);
    }
}

// DELETE FROM THE BEGGING

void delete_at_begging(node **start)
{
    if (*start == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        node *temp = *start;
        *start = (*start)->next;
        free(temp);
    }
}

// DELETE FROM THE END

void delete_at_end(node **start)
{
    if (*start == NULL)
    {
        printf("Linked is Empty");
    }
    else
    {
        node *temp = *start, *pre;
        while (temp->next != NULL)
        {
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        free(temp);
    }
}

// DELETE FROM A SPECIFIC POSITION

void delete_at_mid(node **start, int pos, int ct)
{
    if (pos < ct && pos > 1)
    {
        node *temp = *start, *prev;
        int i = 1;
        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void Create_sll(node **start, int n)
{
    node *newnode, *temp;
    int i = 0, item;
    newnode = (node *)malloc(sizeof(node));
    while (i < n)
    {
        printf("Enter %d node data item :", i + 1);
        scanf("%d", &item);
        newnode->data = item;
        newnode->next = NULL;
        if (*start == NULL)
        {
            *start = newnode;
        }
        else
        {
            temp = *start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        i++;
    }
    newnode->next = *start;
}
void Display(node *start)
{
    printf("Head");
    while (start != NULL)
    {
        printf("--->%d", start->data);
        start = start->next;
    }
    printf("--->NULL\n");
}
int Count(node *start)
{
    int count = 0;
    while (start != NULL)
    {
        start = start->next;
        count++;
    }
    return count;
}