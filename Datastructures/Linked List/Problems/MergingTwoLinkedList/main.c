#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * Create(int *A,int n)
{
    struct Node *first,*t,*last;

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

    return first;

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

// O(m+n) Time Complexity
// O(1) Space Complexity
struct Node * MergeLinkedList(struct Node *a, struct Node *b)
{
    struct Node *first=NULL,*last=NULL;

    if((*a).data<(*b).data)
    {
        first=last=a;
        a=(*a).next;
        (*last).next=NULL;
    }
    else
    {
        first=last=b;
        b=(*b).next;
        (*last).next=NULL;
    }

    while(a && b)
    {
        if((*a).data<(*b).data)
        {
            (*last).next=a;
            last=a;
            a=(*a).next;
            (*last).next=NULL;
        }
        else
        {
            (*last).next=b;
            last=b;
            b=(*b).next;
            (*last).next=NULL;
        }
    }

    if(a)
        (*last).next=a;
    else
        (*last).next=b;

    return first;

}

int main()
{
    printf("Merging Linked List!\n");

    int A[]={10,20,30,30,40,50,60,70,80,90};
    int B[]={0,110,120,130,140,150};

    struct Node *first = Create(A,10);
    struct Node *secnd = Create(B,5);

    Display(first);
    Display(secnd);

    struct Node *temp=MergeLinkedList(first,secnd);

    Display(temp);

    return 0;
}
