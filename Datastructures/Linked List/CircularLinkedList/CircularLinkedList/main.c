#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void Create(int *A, int n)
{
    int i;
    struct Node *t,*last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    (*Head).data=A[0];
    (*Head).next=Head;
    last=Head;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        (*t).data = A[i];
        (*t).next = (*last).next;
        (*last).next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    do
    {
        printf("%d ",(*p).data);
        p=(*p).next;
    }while(p!=Head);
    printf("\n");
}

void Insert(int position, int x)
{
    struct Node *t;
    int i;

    if(position==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        (*t).data=x;

        if(!Head)
        {
            Head=t;
            (*Head).next=t;
        }
        else
        {
            struct Node *temp=Head;
            while((*temp).next!=Head)temp=(*temp).next;
            (*temp).next=t;
            (*t).next=Head;
            Head=t;
        }
    }
    else
    {
        struct Node *temp=Head;
        for(int i=0;i<position-1;i++)temp=(*temp).next;
        t=(struct Node *)malloc(sizeof(struct Node));
        (*t).data=x;
        (*t).next=(*temp).next;
        (*temp).next=t;
    }

}

void Delete(int position)
{
    if(position<=0)
        return;

    if(position-1==0)
    {
        struct Node *p=Head;
        while((*p).next!=Head)p=(*p).next;
        (*p).next=(*Head).next;
        free(Head);
        Head=(*p).next;
    }
    else
    {
        struct Node *p=Head;
        for(int i=1;i<=position-2;i++)p=(*p).next;
        struct Node *temp=(*p).next;
        (*p).next=(*temp).next;
        free(temp);
    }
}

int main()
{
    printf("Circular Linked List!\n");

    int A[]={1,2,3,4,5,6,7};

    Create(A,7);
    Display(Head);

    //Insert(3,22);
    //Display(Head);

    Delete(7);
    Display(Head);

    return 0;
}
