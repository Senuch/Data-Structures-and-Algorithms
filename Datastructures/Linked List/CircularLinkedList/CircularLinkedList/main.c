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

int main()
{
    printf("Circular Linked List!\n");

    int A[]={1,2,3,4,5,6,7};

    Create(A,7);
    Display(Head);

    return 0;
}
