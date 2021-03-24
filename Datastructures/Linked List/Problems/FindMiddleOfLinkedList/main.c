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

// O(n) Time Complexity
// O(1) Space Complexity
void FindingMiddleElement(struct Node *p)
{
    if(CountingElements(p)==0)
    {
        printf("\nList is empty!\n");
    }
    struct Node *temp=p;

    int skip=0;

    while(p && temp)
    {
        skip=0;
        while(skip<2)
        {
            if(!temp)break;
            temp=(*temp).next;
            skip++;
        }

        if(temp)
            p=(*p).next;
    }
    printf("%d\n",(*p).data);
}

int main()
{
    printf("Middle of Linked List!\n");

    int A[]={0,10,20,30,40,50,60,70,80,90};

    Create(A,10);
    //Display(first);

    FindingMiddleElement(first);

    return 0;
}
