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

// O(n) Time Complexity.
int hasLoop(struct Node *node)
{
    struct Node *second=node;

    do
    {
        node=(*node).next;
        second=(*second).next;
        second=(*second).next ? (*second).next : NULL;

        if(node == second)
            return 1;

    }while(node && second);

    return 0;
}

// Helper function to add loop for testing.
void InduceLoop(struct Node *node,int targetIndex)
{
    struct Node *temp=node;

    for(int i=0;i<targetIndex;i++)
        temp=(*temp).next;

    for(;(*node).next!=NULL;)
        node=(*node).next;

    (*node).next=temp;

}

int main()
{
    printf("Loop in Linked List!\n");

    int A[]={10,20,30,30,40,50,60,70,80,90};
    int B[]={110,120,130,140,150};

    struct Node *first = Create(A,10);

    Display(first);

    //InduceLoop(first,4);
    int flag=hasLoop(first);
    printf("\nLoop Status %s",flag ? "Yes" : "False");

    return 0;
}
