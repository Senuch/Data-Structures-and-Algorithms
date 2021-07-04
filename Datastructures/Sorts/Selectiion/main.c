#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Selection(int A[], int n)
{
    int k;
    for(int i=0;i<n-1;i++)
    {
        for(int j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        Swap(&A[k],&A[i]);
    }
}

int main()
{
    int A[]={10,9,8,7,6,5,4,3,2,1}, n=10;

    Selection(A,n);

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}
