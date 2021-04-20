#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Tree_Node
{
    struct Tree_Node *lchild;
    int data;
    struct Tree_Node *rchild;
};

struct Node
{
    struct Tree_Node *data;
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

void Enqueue(struct Queue ** queue, struct Tree_Node *tNode)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    (*node).data=tNode;
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

struct Tree_Node ** Dequeue(struct Queue ** queue)
{
    struct Tree_Node *x=NULL;
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
    struct Node *temp=(*queue).first;
    while(temp!=NULL)
    {
        printf("%d ",(*(*temp).data).data);
        temp=(*temp).next;
    }
    printf("\n");
}

#endif // QUEUE_H_INCLUDED
