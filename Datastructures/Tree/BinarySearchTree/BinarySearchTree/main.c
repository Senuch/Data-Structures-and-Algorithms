#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Insert(int key)
{
    struct Node *t=root;
    struct Node *r,*p;

    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        (*p).data=key;
        (*p).lchild=NULL;
        (*p).rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<(*t).data)
            t=(*t).lchild;
        else if(key>(*t).data)
            t=(*t).rchild;
        else
            return;
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    (*p).data=key;
    (*p).lchild=NULL;
    (*p).rchild=NULL;

    if(key<(*r).data)(*r).lchild=p;
    else (*r).rchild=p;
}

struct Node * Search(int key)
{
    struct Node *t=root;

    while(t!=NULL)
    {
        if(key==(*t).data)
            break;
        else if(key<(*t).data)
            t=(*t).lchild;
        else
            t=(*t).rchild;
    }

    printf("Found Status: %s",(t? "Yes" : "No"));

    return t;
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder((*p).lchild);
        printf("%d ",(*p).data);
        Inorder((*p).rchild);
    }
}

int main()
{
    printf("Binary Search Tree!\n");

    Insert(10);
    Insert(5);
    Insert(20);

    Inorder(root);
    printf("\n");

    Search(55);

    return 0;
}
