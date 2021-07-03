#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Insertion(int A[], int n)
{
    for(int i=1;i<n;i++)
    {
        int x=A[i];
        int j=i-1;

        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main()
{
    int A[]={4,5,2,1,6,7,8,9,22,11}, n=10;

    Insertion(A,n);

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);

    printf("\n");

    return 0;
}
