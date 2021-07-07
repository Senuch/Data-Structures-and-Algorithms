#include <stdio.h>
#include <stdlib.h>

int FindMax(int A[],int n)
{
    int max=-1;
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

void Count(int A[], int n)
{
    int i,j,max,*C;

    max=FindMax(A,n);

    C=(int *)malloc(sizeof(int)*max+1);

    for(i=0;i<max+1;i++)
        *(C+i)=0;

    for(i=0;i<n;i++)
        (*(C+A[i]))++;

    i=0;j=0;

    while(j<max+1)
    {
        if(C[j]>0)
        {
            A[i++]=j;
            (*(C+j))--;
        }
        else
            j++;
    }


}

int main()
{
    int A[]={20,1,22,5,4,2,2,9,0,1}, n=10;

    Count(A,n);

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);

    return 0;
}
