#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

void Push(node **stack, int data);
void display(node *stack);
void Peek(node *stack);
void Pop(node **stack);
int main()
{
    node *stack = NULL;
    for (int i = 0; i < 3; i++)
    {
        Push(&stack, rand() % 20);
    }

    display(stack);
    Peek(stack);
    Pop(&stack);
    Peek(stack);
    display(stack);
}
void Push(node **stack, int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *stack;
    *stack = newnode;
}
void display(node *stack)
{
    if (stack == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        while (stack != NULL)
        {
            printf("%d \n", stack->data);
            stack = stack->next;
        }
    }
}
void Peek(node *stack)
{
    if (stack == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Top element is : %d\n", stack->data);
    }
}
void Pop(node **stack)
{
    if (*stack == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        node *temp = *stack;
        printf("Popped element is : %d\n", temp->data);
        *stack = (*stack)->next;
    }
}