#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int A[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(A[j]>A[j+1])
                Swap(&A[j],&A[j+1]);
}

void AdaptiveBubble(int A[], int n)
{
    int flag=0; //Ensures that if the bubble sort is already in sorted form don't spend computation on it.
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                Swap(&A[j],&A[j+1]);
                flag=1;
            }
            if(flag==0)break;
        }
    }
}

int main()
{
    int A[]={4,5,2,1,6,7,8,9,22,11}, n=10;
    int B[]={1,2,3,4,5,6,7,8,9,10};

    Bubble(A,n);

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);

    printf("\n");

    AdaptiveBubble(A, n);

    for(int i=0;i<n;i++)
        printf("%d ",B[i]);

    printf("\n");

    return 0;
}
