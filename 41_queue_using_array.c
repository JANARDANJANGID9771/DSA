
#include <stdio.h>
#include <stdlib.h> // this is using for malloc

struct queue
{

    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("this queue is Full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int Denqueue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("this queue is Full");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    // if (isEmpty(&q))
    // {
    //     printf("Queue is Empty");
    // }
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    enqueue(&q, 1);
    //   enqueue(&q, 1);
 
    printf("Dequeuing element %d\n", Denqueue(&q));
    printf("Dequeuing element %d\n", Denqueue(&q));
    printf("Dequeuing element %d\n", Denqueue(&q));
    printf("Dequeuing element %d\n", Denqueue(&q));
        enqueue(&q, 1);                                                               

    if (isEmpty(&q))
    {
        printf("queue is Empty\n");
    }

    if (isFull(&q))
    {
        printf("queue is  Full\n");
    }

    return 0;
}