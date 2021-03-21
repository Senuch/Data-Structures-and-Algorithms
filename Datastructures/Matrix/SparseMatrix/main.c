#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

/*

Matrix we are creating...

    0 0 3 0 0
A=  4 0 0 0 7
    0 0 5 0 8
    0 6 0 0 0

Sparse matrix will be as follows...

Row Count->4
Col Count->5
Val Count->6

Row->1 2 2 3 3 4
Col->3 1 5 3 5 2
Val->3 4 7 5 8 6

*/

void Create(struct Sparse *e)
{
    // Start with taking number of rows and columns for sparse matrix.
    // Values can be dynamic, we are taking const input.
    (*e).m=4;
    (*e).n=5;

    // Taking number of non-zero elements.
    (*e).num=5;

    // Allocating memory in heap for sparse element array.
    (*e).ele=(struct Element*)malloc((*e).num*(sizeof(struct Element)));

    // These values are dummy and don't reflect the values reflected in maxtrix above.
    (*((*e).ele+0)).i=0;
    (*((*e).ele+0)).j=2;
    (*((*e).ele+0)).x=7;

    (*((*e).ele+1)).i=1;
    (*((*e).ele+1)).j=0;
    (*((*e).ele+1)).x=2;

    (*((*e).ele+2)).i=1;
    (*((*e).ele+2)).j=3;
    (*((*e).ele+2)).x=5;

    (*((*e).ele+3)).i=2;
    (*((*e).ele+3)).j=0;
    (*((*e).ele+3)).x=9;

    (*((*e).ele+4)).i=3;
    (*((*e).ele+4)).j=4;
    (*((*e).ele+4)).x=4;

}

void Sum(struct Sparse a, struct Sparse b)
{
    if(a.m!=b.m && a.n!=b.n)
        return 0;

    struct Sparse sum;
    sum.m=a.m;
    sum.n=a.n;
    sum.num=a.num+b.num;

    // Don't know the maxm number but can predict the maxm space as sum of number
    // of elements in a and b.
    sum.ele=(struct Element*)malloc((a.num+b.num)*sizeof(struct Sparse));

    int i=0,j=0,k=0;

    while(i<a.num && j<b.num)
    {
        if(a.ele[i].i<b.ele[j].i)
            sum.ele[k++]=a.ele[i++];
        else if(a.ele[i].i>b.ele[j].i)
            sum.ele[k++]=b.ele[j++];
        else
        {
            if(a.ele[i].j<b.ele[j].j)
                sum.ele[k++]=a.ele[i++];
            else if(a.ele[i].j>b.ele[j].j)
                sum.ele[k++]=b.ele[j++];
            else
            {
                sum.ele[k]=a.ele[i++];
                sum.ele[k++].x+=b.ele[j++].x;
            }
        }
    }
    for(;i<a.num;i++)sum.ele[k++]=a.ele[i];
    for(;j<a.num;j++)sum.ele[k++]=a.ele[j];

    sum.num=k+1;

    Display(sum);

}

void Display(struct Sparse s)
{
    for(int i=0,k=0;i<s.m;i++)
    {
        for(int j=0;j<s.n;j++)
        {   // Ensuring values whose rows and columns are stored in sparse are only displayed.
            if(i==(*(s.ele+k)).i && j==(*(s.ele+k)).j)
                printf("%d ",(*(s.ele+k++)).x);
            else
                printf("%d ",0);
        }
        printf("\n");
    }
}

int main()
{
    printf("Sparse Matrix!\n");

    struct Sparse a,b;
    Create(&a);
    Create(&b);
    //Display(a);

    Sum(a,b);

    return 0;
}
