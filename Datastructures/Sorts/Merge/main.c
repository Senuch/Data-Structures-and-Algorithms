#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int l, int mid, int h)
{
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void IMergeSort(int A[], int n)
{
    int p,l,h,mid,i;

    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i+=p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
        printf("%d-%d=%d p/2=%d\n",n,i,n-i,p/2);
        if(n-i>p/2)
         {
             l = i;
             h = i+p-1;
             mid = (l+h)/2;
             Merge(A, l, mid, n-1);
         }
    }
    printf("n=%d P=%d P/2=%d\n",n,p,p/2);
    if(p/2<n) // Ensures to only execute this code when there are odd number of elements in the array.
        Merge(A,0,p/2-1,n-1);

}

void RecursiveMerge(int A[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        RecursiveMerge(A,l,mid);
        RecursiveMerge(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main()
{
    int A[]= {2, 5, 8, 12, 3, 6, 7, 10, 11, 10, 2},n=11,i;

    //IMergeSort(A,n);
    RecursiveMerge(A,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}
