#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int A[], int l, int h)
{
    int pivot=A[l];
    int i=l,j=h;

    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i<j)
            swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);

    return j;
}

void Quick(int A[], int l, int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        Quick(A,l,j);
        Quick(A,j+1,h);
    }
}

int main()
{
    int A[]={80,20,10,40,90,50,30,60,70,100,65535}, n=11;

    Quick(A,0,n-1);

    for(int i=0;i<n-1;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}
