#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *first;
    struct Node *last;
};

int IsEmpty(struct Queue *queue)
{

    if((*queue).first==NULL && (*queue).last==NULL)
        return 1;
    return 0;
}

int IsFull(struct Queue *queue)
{
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));

    if(node==NULL)
        return 1;
    return 0;
}

struct Node * Init()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    (*queue).first=NULL;
    (*queue).last=NULL;

    return queue;
};

void Enqueue(struct Queue ** queue, int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    (*node).data=value;
    (*node).next=NULL;

    if(node==NULL)
        printf("Queue is full.\n");
    else
    {
        if(IsEmpty(*queue))
        {
            (*(*queue)).first=node;
            (*(*queue)).last=node;
        }
        else
        {
            (*(*(*queue)).last).next=node;
            (*(*queue)).last=node;
        }
    }
}

int Dequeue(struct Queue ** queue)
{
    int x=-1;
    if(IsEmpty(*queue))
        printf("Is Empty\n");
    else
    {
        struct Node *temp=(*(*queue)).first;
        if(temp==(*(*queue)).last)
        {
            (*(*queue)).last=NULL;
        }
        x=(*temp).data;
        (*(*queue)).first=(*temp).next;
        free(temp);
    }

    return x;
}

void Display(struct Queue *queue)
{
    while((*queue).first!=NULL)
    {
        printf("%d ",(*(*queue).first).data);
        (*queue).first=(*(*queue).first).next;
    }
    printf("\n");
}

int main()
{
    printf("Queue using Linked List!\n");

    struct Queue *queue=Init();

    //Display(queue);

    printf("%d\n", Dequeue(&queue));

    Enqueue(&queue,1);
    Enqueue(&queue,2);
    Enqueue(&queue,3);

    //Display(queue);
    printf("%d\n", Dequeue(&queue));
    printf("%d\n", Dequeue(&queue));
    printf("%d\n", Dequeue(&queue));

    Dequeue(&queue);

    Enqueue(&queue,3);

    printf("%d\n", Dequeue(&queue));

    Enqueue(&queue,1);
    Enqueue(&queue,2);
    Enqueue(&queue,3);

    Display(queue);

    return 0;
}
