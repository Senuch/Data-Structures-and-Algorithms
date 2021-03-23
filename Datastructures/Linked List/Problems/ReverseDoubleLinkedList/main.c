#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
    struct Node *prev;
}*first=NULL;

void Create(int *A, int n)
{
    struct Node *t,*last;

    first = (struct Node *)malloc(sizeof(struct Node));
    (*first).data=A[0];
    (*first).next=NULL;
    (*first).prev=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        (*t).data=A[i];
        (*t).prev=last;
        (*t).next=NULL;
        (*last).next=t;
        last=t;
    }

}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ",(*p).data);
        p=(*p).next;
    }
    printf("\n");
}

void Insert(int position, int value)
{
    if(position<=0)
        return;
    if(position==1)
    {
        struct Node *t = (struct Node *) malloc(sizeof(struct Node));
        (*t).data=value;
        (*t).next=first;
        (*first).prev=t;
        (*t).prev=NULL;
        first=first;
        return;
    }
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    struct Node *temp = first;
    for(int i=1;i<=position-1;i++)
        temp=(*temp).next;

    (*t).data=value;
    (*t).next=(*temp).next;
    (*t).prev=temp;
    if((*temp).next)
        (*(*temp).next).prev=t;
    (*temp).next=t;


}

void Delete(int position)
{
    if(position<=0)
        return;

    if(position==1)
    {
        struct Node *temp=first;
        first=(*first).next;
        if(first)
            (*first).prev=NULL;
        free(temp);
    }
    else
    {
        struct Node *temp=first;

        for(int i=1;i<=position-1;i++)
            temp=(*temp).next;

        (*(*temp).prev).next=(*temp).next;
        if((*temp).next)
            (*(*temp).next).prev=(*temp).prev;
        free(temp);
    }

}

int CountElements(struct Node *p)
{
    int i=0;

    for(i=0;p;i+=1)
        p=(*p).next;
    return i;
}

void Reverse(struct Node *p)
{
    if(CountElements(p)==0 || CountElements(p)==1)
        return;

    struct Node *temp;

    while(p)
    {
        if(!(*p).next)
            first=p;
        temp=(*p).next;
        (*p).next=(*p).prev;
        (*p).prev=temp;
        p=temp;

    }

}

int main()
{
    printf("Reverse Doubly Linked List!\n");

    int A[]={1,2,3,4,5};

    Create(A,5);
    Display(first);

    Reverse(first);


    return 0;
}
