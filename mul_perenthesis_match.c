#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int size;
    char *arr;
} stack;

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_empty(stack *s)
{
    return (s->top == -1);
}
// int is_empty(stack *s)
// {
//     if (s->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
void Push(stack *s, char data)
{
    s->arr[++s->top] = data;
}
void pop(stack *s)
{
    if (!is_empty(s))
    {
        s->top--;
    }
}

char mul_perenthesis_match(char *exp)
{
    stack *s;
    s->top = -1;
    s->size = 20;
    s->arr = (char *)malloc(s->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            Push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (is_empty(s))
            {
                return 0;
            }
            if (!match(s->arr[s->top], exp[i]))
            {
                return 0;
            }
            pop(s);
        }
    }
    if (is_empty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "[{4*5}]";
    if (mul_perenthesis_match(exp))
    {
        printf("Perenhesis Matching");
    }
    else
    {
        printf("Perenhesis  not Matching");
    }

    return 0;
}