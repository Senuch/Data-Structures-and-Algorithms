#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int *A,int n)
{
    struct Node *t,*last;

    first=(struct Node*)malloc(sizeof(struct Node));

    (*first).data=*(A+0);
    (*first).next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        (*t).data=*(A+i);
        (*t).next=NULL;
        (*last).next=t;
        last=t;
    }

}

// O(n) time complexity.
// O(1) space complexity.
void Display(struct Node *p)
{
    printf("\n");
    while(p!=NULL)
    {
        printf("%d ",(*p).data);
        p=(*p).next;
    }
}

// O(n) time complexity.
// O(n) space complexity.
void RecursiveDisplay(struct Node *node)
{
    if(node==NULL)
        return;
    printf("%d ",(*node).data);
    RecursiveDisplay((*node).next);
}

// O(n) time complexity.
// O(1) space complexity.
int CountingElements(struct Node *node)
{
    int count=0;
    while(node!=NULL)
    {
        count++;
        node=(*node).next;
    }

    printf("\nNodes Count: %d ",count);

    return count;
}

void Insert(struct Node *p,int position, int data)
{
    if(position<0 || position>CountingElements(p))
        return;

    // Create new node.
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    (*t).data=data;

    if(position==0)
    {
        (*t).next=p;
        first=t;
        return;
    }

    for(int i=0;i<position-1;i++)
        p=(*p).next;

    (*t).next=(*p).next;
    (*p).next=t;

}

void InsertInSortedList(struct Node *p,int value)
{
    struct Node *tailPointer=NULL;

    for(;p && (*p).data<value;)
    {
        tailPointer=p;
        p=(*p).next;
    }

    if(tailPointer==NULL)
    {
        printf("executed");
        Insert(first,0,value);
        return;
    }

    struct Node *temp=(struct Node *)(malloc(sizeof(struct Node)));
    (*temp).data=value;
    (*temp).next=(*tailPointer).next;
    (*tailPointer).next=temp;
}

void DeleteNode(struct Node *p,int index)
{
    if(index<0 || CountingElements(p)<index)
        return;

    if(index==0)
    {
        first=(*p).next;
        free(p);
        return;
    }

    struct Node *q=NULL;

    for(int i=0;i<index;i++)
    {
        q=p;
        p=(*p).next;
    }

    (*q).next=(*p).next;
    free(p);

}

void RemoveDuplicateValueFromSortedLinkedList(struct Node *p)
{
    if(!p)
        return;

    struct Node *q=p;
    p=(*p).next;

    while(p)
    {
         if((*p).data==(*q).data)
        {
            //Remove duplicate.
            (*q).next=(*p).next;
            free(p);
            p=(*q).next;
        }
        else{
            q=(*q).next;
            p=(*p).next;
        }
    }
}

int main()
{
    printf("Removing Duplicate Value From Sorted Linked List!\n");

    int A[]={1,10,20,30,30,40,50,60,70,80,90};

    Create(A,11);
    Display(first);
    RemoveDuplicateValueFromSortedLinkedList(first);
    Display(first);
    return 0;
}
