#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int *array, int length)
{

    struct Node *last,*temp = (struct Node *)malloc(sizeof(struct Node));
    (*temp).data=array[0];
    (*temp).next=temp;
    (*temp).prev=temp;
    first=temp;
    last=temp;

    for(int i=1;i<length;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        (*temp).data=array[i];
        (*temp).next=first;
        (*temp).prev=last;
        (*last).next=temp;
        (*first).prev=temp;
        last=temp;
    }
}

int CountElements(struct Node *p)
{
    int i=0;
    if(!p)
    {
        return i;
    }

    do
    {
        p=(*p).next;
        i+=1;
    }while(p && p!=first);

    return i;
}

void Insert(int value, int position)
{

    if(CountElements(first)==0)
    {
        printf("\nNo linked list found!\n");
        return;
    }

    struct Node *temp;
    if(position==0)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        (*temp).data=value;
        (*temp).prev=(*first).prev;
        (*temp).next=first;
        (*(*first).prev).next=temp;
        (*first).prev=temp;
        first=temp;
        return;
    }
    else
    {
        struct Node *p=first;
        temp = (struct Node *)malloc(sizeof(struct Node));

        for(int i=1;i<=position-1;i++)
            p=(*p).next;

        (*temp).data=value;
        (*temp).prev=p;
        (*temp).next=(*p).next;
        (*(*p).next).prev=temp;
        (*p).next=temp;
        return;

    }
}

void Delete(int position)
{
    if(CountElements(first)==0 || position > CountElements(first))
    {
        return;
    }

    if(position==1)
    {
        struct Node *temp=first;

        (*(*temp).next).prev=(*temp).prev;
        (*(*temp).prev).next=(*temp).next;
        first=(*temp).next;
        free(temp);
    }
    else
    {
        struct Node *temp=first;
        for(int i=1;i<=position-1;i++)
            temp=(*temp).next;
        (*(*temp).next).prev=(*temp).prev;
        (*(*temp).prev).next=(*temp).next;
        free(temp);
    }
}

void Display(struct Node *p)
{
    if(!p)
        return;

    do
    {
        printf("%d ",(*p).data);
        p=(*p).next;
    }while(p && p!=first);
    printf("\n");
}

int main()
{
    printf("Circular Doubly Linked List!\n");

    int A[] = {1,2,3,4,5};

    Create(A,5);
    Display(first);

    Insert(99,0);
    Display(first);

    Insert(88,2);
    Display(first);

    Delete(3);
    Display(first);

    Delete(1);
    Display(first);

    return 0;
}
