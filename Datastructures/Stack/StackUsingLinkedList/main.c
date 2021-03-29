#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void Push(int x)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    if(!t)
        printf("\nStack is full!!!");
    else
    {
        (*t).data=x;
        (*t).next=top;
        top=t;
    }
}

int Pop()
{
    int x=-1;

    if(!top)
        printf("\nStack is empty!!!");
    else
    {
        struct Node *t=top;
        top=(*top).next;
        x=(*t).data;
        free(t);
    }

    return x;
}

void Display()
{
    struct Node *t=top;

    while(t)
    {
        printf("%d ",(*t).data);
        t=(*t).next;
    }
    printf("\n");
}

int main()
{
    printf("Stack using Linked List!\n");

    Push(10);
    Push(20);
    Push(30);

    Display();

    printf("\n%d\n",Pop());

    Display();

    return 0;
}
