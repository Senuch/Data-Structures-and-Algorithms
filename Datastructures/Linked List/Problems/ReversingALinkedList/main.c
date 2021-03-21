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

// Time Complexity O(n)
// Space Complexity O(n)
void ReverseLinkedListUsingAuxilaryArray(struct Node *p)
{
    if(CountingElements(p)==0)
        return;

    int auxArray[CountingElements(p)];

    for(int i=0;p!=NULL;i++)
    {
        auxArray[i]=(*p).data;
        p=(*p).next;
    }

    p=first;

    for(int i=CountingElements(p)-1;p!=NULL;i--)
    {
        (*p).data=auxArray[i];
        p=(*p).next;
    }

}

// Time Complexity O(n)
// Space Complexity O(1)
/*
    This approach is preferred over the auxilary one because of the data.
    Right now our data is simple integer which is quick copy but with bigger
    data in memory this can get really slow thus its preffered to switch links
    instead of data.
*/
void ReverseLinkedListViaLinks(struct Node *p)
{

    if(CountingElements(p)<=1)
        return;


    struct Node *q,*r;
    q=r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=(*p).next;
        (*q).next=r;
    }
    first=q;
}

// Time Complexity O(n)
// Space Complexity O(n) because of call stack
void RecursiveReverseViaLinks(struct Node *p)
{
    static struct Node *q=NULL,*r=NULL;

    if(p==NULL)
    {
        first=q;
        return;
    }

    r=q;
    q=p;
    p=(*p).next;
    (*q).next=r;
    RecursiveReverseViaLinks(p);
}

int main()
{
    printf("Reversing Linked List!\n");

    int A[]={1,10,20,30,30,40,50,60,70,80,90};

    Create(A,11);
    Display(first);

    //ReverseLinkedListUsingAuxilaryArray(first);
    RecursiveReverseViaLinks(first);
    Display(first);

    return 0;
}
