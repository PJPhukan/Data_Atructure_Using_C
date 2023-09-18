#include <stdio.h>
#include <stdlib.h>

typedef struct circular_queue
{
    int font, rear, size;
    int *arr;
} queue;
int is_empty(queue *q)
{
    return (q->font == q->rear);
}
int is_full(queue *q)
{
    if (q->font == -1 && q->rear == -1)
    {
        return 0;
    }
    else if (((q->rear + 1) % q->size) == q->font)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void CircularNQ(queue *q, int data)
{
    if (!is_full(q))
    {
        // printf("hello");
        if (q->font == -1 && q->rear == -1)
        {
            q->font++;
            q->rear++;
            q->arr[q->rear] = data;
            // q->rear++;
        }
        else if ((q->rear + 1) % q->size == q->font)
        {
            printf("Queue is full\n");
        }
        else
        {
            q->rear = (q->rear + 1) % q->size;
            q->arr[q->rear] = data;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}
void display(queue *q)
{
    for (int i = q->font; i <= q->rear; i++)
    {
        printf("%d\t", q->arr[i]);
    }
}
int CircularDQ(queue *q){
    if(q->rear==q->font){
        printf("Queue is empty");

    }
    else{
        int val = q->arr[q->font++];
        printf("delete value is %d\n",val);
    }
}

int main()
{
    queue q;
    q.font = q.rear = -1;
    q.size = 4;
    q.arr = (int *)malloc(sizeof(int) * q.size);
    CircularNQ(&q, 1);
    CircularNQ(&q, 2);
    CircularNQ(&q, 3);
   CircularDQ(&q);
    CircularNQ(&q, 7);
    CircularNQ(&q, 7);
    // CircularNQ(&q, 7);
    // display(&q);
    return 0;
}