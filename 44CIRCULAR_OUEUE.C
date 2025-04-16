
#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->r==q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enQueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is  Full\n");
    }
    else
    {
        q->r = (q->r +1)%q->size;  
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int deQueue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty\n ");
    }
    else
    {
        q->f = (q->f+1) %q->size;
        a = q->arr[q->f];
    }     
    return a;
}

 int main()
{
    struct circularQueue q;
    q.size =  4;
    q.f = q.r = 0;  //  r = rayer, f= front 
    q.arr = (int *)malloc(q.size * sizeof(int));
    // if (isEmpty(&q))
    // {
    //     printf("Queue is Empty");
    // }
    // Enqueue few elements
    enQueue(&q, 12);
    enQueue(&q, 15);
    enQueue(&q, 1);
    enQueue(&q, 1);
    //   enqueue(&q, 1);
 
    printf("Dequeuing element %d\n", deQueue(&q));
    printf("Dequeuing element %d\n", deQueue(&q));
    printf("Dequeuing element %d\n", deQueue(&q));

    enQueue(&q, 45);                            
    enQueue(&q, 45);                            
    enQueue(&q, 45);                            

    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }

    if (isFull(&q)) 
    {
        printf("Queue is  Full\n");
    }

    return 0;
}
