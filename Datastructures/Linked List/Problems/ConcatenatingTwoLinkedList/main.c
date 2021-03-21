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

// Time Complexity O(n)
void ConcatedLinkedList(struct Node *a, struct Node *b)
{
    while((*a).next!=NULL)
        a=(*a).next;

    (*a).next=b;
    b=NULL;

}

int main()
{
    printf("Concatenating Linked List!\n");

    int A[]={10,20,30,30,40,50,60,70,80,90};
    int B[]={110,120,130,140,150};

    struct Node *first = Create(A,10);
    struct Node *secnd = Create(B,5);

    Display(first);
    Display(secnd);

    ConcatedLinkedList(first,secnd);

    Display(first);

    return 0;
}
