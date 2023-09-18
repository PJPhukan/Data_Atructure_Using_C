#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} Stack;
int is_empty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Push(Stack *s, int data)
{
    s->arr[++s->top] = data;
}
void Pop(Stack *s)
{
    if (!is_empty(s))
    {
        s->top--;
    }
}
char Perenthesis_Match(char *exp)
{
    Stack *sp;
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; ++i)
    {
        if (exp[i] == '(')
        {
            Push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (is_empty(sp))
            {
                return 0;
            }
            Pop(sp);
        }
    }
    if (is_empty(sp))
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
    char *exp = "2*3))";
   if( Perenthesis_Match(exp)){
    printf("Perenthesis matching");
   }
   else{
        printf("Perenthesis not matching");
   }
    return 0;
}