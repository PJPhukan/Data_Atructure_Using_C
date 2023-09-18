#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct queue_a
{
    int front, rear;
    int arr[MAX];
} queue;

int if_full(queue *q);
int if_empty(queue *q);
void dequeue(queue *q);
int enqueue(queue *q, int item);
void display(queue *q);

int main()
{
    queue q;
    q.front = q.rear = -1;
    for(int i=0;i<10;i++){

    enqueue(&q,rand()%20);
    }
    enqueue(&q,223);
    // enqueue(&q,3);
    // enqueue(&q,2);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}
int if_full(queue *q)
{
    if (q->rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int if_empty(queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dequeue(queue *q)
{
    int x;
    if (if_empty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = q->arr[q->front];
        q->front++;
        printf("\nDeleted element is  :%d\n", x);
    }
}

int enqueue(queue *q, int item)
{
    if (if_full(q))
    {
        printf("Queue is full\n");
        return 0;
    }
    else
    {
        if (q->front == -1)
        {
            q->front++;
            q->rear++;
            q->arr[q->rear] = item;
        }
        else
        {
            q->rear++;
            q->arr[q->rear] = item;
        }
    }
}

void display(queue *q)
{
    if (if_empty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf(" %d  -", q->arr[i]);
        }
    }
}
