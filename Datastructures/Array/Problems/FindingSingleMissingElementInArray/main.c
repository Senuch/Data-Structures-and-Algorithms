#include <stdio.h>
#include <stdlib.h>


// For first N natural numbers.
int FindMissingElement(int A[],int elementCount)
{
    int expectedSum=(elementCount*(elementCount+1))/2; // Using formula (n*(n+1))/2
    int sum=0;

    for(int i=0;i<elementCount-1;i++)
        sum+=A[i];

    return expectedSum-sum;

}

// For any N natural numbers with start  .
int FindAnyMissingElement(int A[],int elementCount, int low, int high)
{
    for(int i=0;i<elementCount-1;i++)
        if(A[i]-low!=i) // Simple math. The low-index should always be equal to low in case its not thats the missing element index. Simply return index+low which should be at that index.
            return low+i;

}

// Time complexity O(n) where n-> high-low natural numbers.
void FindMultipleMissingElement(int A[], int elementCount, int low, int high)
{
    int i=0;
    while(i<elementCount)
    {
        if(A[i]-low!=i)
        {
            printf("Missing Element%d \n",low+i);
            low+=1;
        }
        else
            i++;

    }
}

void FindMultipleMissingElementInUnSortedArray(int A[], int elementCount, int low, int high)
{
    int Hash[high+1];

    for(int i=0;i<high+1;i++)
        Hash[i]=0;

    for(int i=0;i<elementCount;i++)
        Hash[A[i]]+=1;

    for(int i=low;i<=high;i++)
        if(Hash[i]==0)
            printf("Missing Element %d\n",i);

}

int main()
{
    //int A[] = {1,2,3,4,5,6,8,9,10,11,12};
    int A[] = {6,7,8,9,11,12,15,16,17,18,19};
    printf("Finding Single Missing Element in Array!\n");

    //printf("%d",FindMissingElement(A, 12));
    //FindMultipleMissingElement(A, 11,6,19);
    FindMultipleMissingElementInUnSortedArray(A, 11,6,19);

    return 0;
}
