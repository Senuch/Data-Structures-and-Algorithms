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

// O(n) time complexity.
void SumNodes(struct Node *node)
{
    int sum=0;
    while(node!=NULL)
    {
        sum=sum+(*node).data;
        node=(*node).next;
    }
    printf("\nNodes Sum: %d ",sum);
}

// 0(n) time complexity.
// 0(1) space complexity.
void MaximumElement(struct Node *node)
{
    int maxmValue=-INFINITY;

    while(node!=NULL)
    {
        if((*node).data>maxmValue)
            maxmValue=(*node).data;
        node=(*node).next;
    }
    printf("\nMax Value:%d ",maxmValue);
}

// O(n) Time Complexity.
// O(1) Space Complexity.
/**
    We cannot use binary search on linked list since
    we can only access the elements of the list
    linearly. However this linear search can be improved
    using two methods as discussed earlier...
    1-> Transposition in which found element is swapped with the last index of the found element. This way most recently access elements are moved to the start of the array.
    2-> Move to HEAD in which found element is directly swapped with the element at the start of the linked list.
*/
void LinearSearch(struct Node *node, int value)
{
    while(node!=NULL)
    {
        if((*node).data==value)
        {
            printf("\nValue %d Found",value);
            return;
        }
        node=(*node).next;
    }
    printf("\nValue %d not found",value);
}

// O(n) Time Complexity
void SwapNodes(struct Node *head, int a, int b)
{
    if(a==b)
        return;

    // Getting pointers to location of a and its following node.
    struct Node *nodeA,*nodeAPrevious;
    nodeAPrevious=NULL;
    nodeA=head;

    while(nodeA!=NULL)
    {
        if((*nodeA).data==a)
            break;
        nodeAPrevious=nodeA;
        nodeA=(*nodeA).next;
    }

    // Getting pointers to location of b and its following node.
    struct Node *nodeB,*nodeBPrevious;
    nodeBPrevious=NULL;
    nodeB=head;

    while(nodeB!=NULL)
    {
        if((*nodeB).data==b)
            break;
        nodeBPrevious=nodeB;
        nodeB=(*nodeB).next;
    }

    // Its the first node.
    if(nodeAPrevious!=NULL)
    {
        (*nodeAPrevious).next=nodeB;
    }

    if(nodeBPrevious!=NULL)
    {
        (*nodeBPrevious).next=nodeA;
    }

    struct Node *temp=(*nodeA).next;
    (*nodeA).next=(*nodeB).next;
    (*nodeB).next=temp;

    //printf("\n%d",first->data);
    first=nodeAPrevious==NULL?nodeB:first;
    first=nodeBPrevious==NULL?nodeA:first;

}

// O(n) Time Complexity.
void LinearSearchTransposition(struct Node *node, int value)
{
    struct Node *followNode=NULL;

    while(node!=NULL)
    {
        if((*node).data==value)
        {
            printf("\nValue %d found!",value);
            followNode?SwapNodes(first,(*followNode).data,value):"Nothing";
            break;
        }
        followNode=node;
        node=(*node).next;
    }
}

// O(n) Time Complexity.
void LinearMoveToHeadSearch(struct Node *node, int value)
{
    while(node!=NULL)
    {
        if((*node).data==value)
        {
            printf("\nValue %d found!",value);
            SwapNodes(first,(*first).data,value);
        }
        node=(*node).next;
    }
}

int main()
{
    printf("Linked List!\n");

    int A[]={1,10,20,30,40,50,60,70,80,90};

    Create(A,10);
    Display(first);
    //RecursiveDisplay(first);
    //CountingElements(first);
    //SumNodes(first);
    //MaximumElement(first);
    //LinearSearch(first,2);
    //SwapNodes(first,3,2);
    //LinearSearchTransposition(first,2);
    //Display(first);
    //LinearMoveToHeadSearch(first,10);
    //Display(first);
    //Insert(first,1,99);
    //InsertInSortedList(first,0);
    //InsertInSortedList(first,2);
    //Display(first);
    DeleteNode(first,0);
    Display(first);
    DeleteNode(first,5);
    Display(first);

    return 0;
}
