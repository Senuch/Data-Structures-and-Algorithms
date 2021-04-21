#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Tree_Node *root=NULL;

void CreateTree()
{
    struct Queue *q=Init();
    struct Tree_Node *p, *t;
    int x;

    printf("Enter root value ");
    scanf("%d",&x);

    root=(struct Tree_Node *)malloc(sizeof(struct Node));

    (*root).data=x;
    (*root).lchild=NULL;
    (*root).rchild=NULL;
    Enqueue(&q,root);

    while(!IsEmpty(q))
    {
        p=Dequeue(&q);
        printf("Enter left child of %d: ",(*p).data);
        scanf("%d",&x);

        if(x!=-1)
        {
            t=(struct Tree_Node *)malloc(sizeof(struct Node));
            (*t).data=x;
            (*t).lchild=(*t).rchild=NULL;
            (*p).lchild=t;
            Enqueue(&q,t);
        }

        printf("Enter right child of %d: ",(*p).data);
        scanf("%d",&x);

        if(x!=-1)
        {
            t=(struct Tree_Node *)malloc(sizeof(struct Node));
            (*t).data=x;
            (*t).lchild=(*t).rchild=NULL;
            (*p).rchild=t;
            Enqueue(&q,t);
        }
    }

}

void PreOrder(struct Tree_Node *p)
{
    if(p)
    {
        printf("%d ",(*p).data);
        PreOrder((*p).lchild);
        PreOrder((*p).rchild);
    }
}

// Time Complexity O(n)
// Space Complexity O(n) Because of memory stack
int CountNodes(struct Tree_Node *p)
{
    if(p)
    {
        int x=CountNodes((*p).lchild);
        int y=CountNodes((*p).rchild);
        return x+y+1;
    }
    return 0;
}

// Time Complexity O(n)
// Space Complexity O(n) Because of memory stack
int Height(struct Tree_Node *p)
{
    if(p)
    {
        int x=Height((*p).lchild);
        int y=Height((*p).rchild);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return -1;
}

int main()
{
    CreateTree();

    PreOrder(root);

    printf("\n");

    printf("Nodes count %d\n",CountNodes(root));

    printf("Height %d\n",Height(root));

    return 0;
}
