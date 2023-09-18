#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *arr;
    int size;
    int top;
} stack;
void Create(stack *s, int size);
int is_empty(stack *s);
int is_full(stack *s);
int push(stack *s, int item);
int Pop(stack *s);
void Peek(stack *s);
void display(stack *s);

int main()
{
    stack s;
    Create(&s, 10);
    for (int i = 0; i < 10; i++)
    {

        push(&s, rand() % 10);
    }
    Peek(&s);
    Pop(&s);
    display(&s);

    return 0;
}
void Create(stack *s, int size)
{
    s->arr = (int *)malloc(size * sizeof(int));
    s->size = size;
    s->top = -1;
}
int is_empty(stack *s)
{
    return (s->top == -1);
}
int is_full(stack *s)
{
    return (s->top == s->size - 1);
}
int push(stack *s, int item)
{
    if (!is_full(s))
    {
        s->arr[++s->top] = item;
        return 1;
    }
    printf("Item successfully pushed");
    return 0;
}
int Pop(stack *s)
{
    if (!is_empty(s))
    {
        int p = s->arr[s->top--];
        printf("Poped item is %d", p);
        return 0;
    }
}
void Peek(stack *s)
{
    if (!is_empty(s))
    {
        printf("Peek item value is %d\n", s->arr[s->top]);
    }
    else
    {
        printf("stack is empty");
    }
}
void display(stack *s)
{
    if (!is_empty(s))
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf(" \n %d  ", s->arr[i]);
        }
    }
    else
    {
        printf("stack is empty");
    }
}