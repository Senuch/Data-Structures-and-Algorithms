#include <stdio.h>
#include <stdlib.h>

// Time Complexity O(n)
// Space complexity is bit extra which can be reduced easily using loops with multiple pointers.
void FindingDuplicatesInSortedArray(int A[], int count)
{
    int lowestValue = A[0];
    int highestValue = A[count-1];

    int Hash[highestValue+1];
    for(int i=0;i<=highestValue;i+=1)
        Hash[i]=0;

    for(int i=0;i<count; i++)
        Hash[A[i]]+=1;

    for(int i=0;i<=highestValue;i++)
        if(Hash[i]>1)
            printf("Duplicate:%d Count:%d\n",i, Hash[i]);


}

int main()
{
    printf("Finding Duplicates in Sorted Array!\n");

    int A[] = {1,2,3,3,4,5,6,7,7,7,8,9,10};
    FindingDuplicatesInSortedArray(A, 13);
    return 0;
}
