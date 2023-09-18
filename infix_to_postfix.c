#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stac
{
    int top;
    int size;
    char *arr;
};
typedef struct stac stack;
char stacktop(stack *sp)
{
    return sp->arr[sp->top];
}
// int match(char a, char b)
// {
//     if (a == '(' && b == ')')
//     {
//         return 1;
//     }
//     else if (a == '[' && b == ']')
//     {
//         return 1;
//     }
//     else if (a == '{' && b == '}')
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
int is_empty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
void Push(stack *s, char data)
{
    s->arr[++s->top] = data;
}
char pop(stack *s)
{
    if (!is_empty(s))
    {
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}
int is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
// char *infixToPostfix(char *infix)
// {
//     stack *sp = ( stack *)malloc(sizeof( stack));
//     sp->size = 10;
//     sp->top = -1;
//     sp->arr = (char *)malloc(sp->size * sizeof(char));
//     char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
//     int i = 0; // Track infix traversal
//     int j = 0; // Track postfix addition
//     while (infix[i] != '\0')
//     {
//         if (!is_operator(infix[i]))
//         {
//             postfix[j] = infix[i];
//             j++;
//             i++;
//         }
//         else
//         {
//             if (precedence(infix[i]) > precedence(stacktop(sp)))
//             {
//                 Push(sp, infix[i]);
//                 i++;
//             }
//             else
//             {
//                 postfix[j] = pop(sp);
//                 j++;
//             }
//         }
//     }
//     while (!is_empty(sp))
//     {
//         postfix[j] = pop(sp);
//         j++;
//     }
//     postfix[j] = '\0';
//     return postfix;
// }

char *infixToPostfix(char *infix)
{
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * (sizeof(char)));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            postfix[j] = infix[i];
           
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(sp)))
            {
                Push(sp, infix[i]);
              
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
        i++;
    }
    while (!is_empty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}