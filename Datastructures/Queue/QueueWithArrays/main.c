#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int * Q;
};

int IsFull(struct Queue q)
{
    if(q.rear==q.size-1)
        return 1;
    return 0;
}

int IsEmpty(struct Queue q)
{
    if(q.front==q.rear)
        return 1;
    return 0;
}

struct Queue * InitQueue(int size)
{
    struct Queue *q=(struct Queue *)malloc(sizeof(struct Queue));

    (*q).front=-1;
    (*q).rear=-1;
    (*q).size=size;
    (*q).Q=(int *)malloc(sizeof(int)*size);

    return q;

}

void Enqueue(struct Queue * q, int value)
{
    if(IsFull(*q))
        printf("Queue is full!\n");
    else
    {
        (*q).Q[++(*q).rear]=value;
    }
}

int Deque(struct Queue *q)
{
    int x=-1;

    if(IsEmpty(*q))
        printf("Queue is empty!\n");
    else
    {
        x=(*q).Q[++(*q).front];
    }
    return x;
}

void Display(struct Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.Q[i]);
    }

    printf("\n");
}


int main()
{
    printf("Queue With Arrays!\n");

    struct Queue *q = InitQueue(7);

    Enqueue(q,1);
    Enqueue(q,2);
    Enqueue(q,3);
    Enqueue(q,4);

    Display(*q);

    printf("Deque %d\n",Deque(q));
    printf("Deque %d\n",Deque(q));

    Display(*q);

    return 0;
}
