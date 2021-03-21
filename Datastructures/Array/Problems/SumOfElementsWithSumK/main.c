#include <stdio.h>
#include <stdlib.h>

// Time Complexity O(n).
// Space Complexity is O(n).
void FindPairWithSumK(int A[], int count, int maxValue, int targetSum)
{
    int Hash[maxValue+1];

    for(int i=0;i<maxValue+1;i++)
        Hash[i]=0;

    for(int i=0;i<count;i++)
    {
        printf("Taking Difference %d-%d=%d Hash:%d\n",targetSum,A[i],(targetSum-A[i]),Hash[(targetSum-A[i])]);
        if(Hash[(targetSum-A[i])]>0)
        {
            printf("%d+%d=10\n",A[i],abs(targetSum-A[i]));
            return;
        }
        else
            Hash[A[i]]+=1;
    }
}

// Time Complexity O(n)
// Space Complexity O(1)
void FindPairWithSumKInSortedArray(int A[], int count, int targetSum)
{
    int i=0;
    int j=count-1;

    while(i<j)
    {
        int sum=A[i]+A[j];
        if(sum==targetSum)
        {
            printf("%d+%d=%d",A[i],A[j],targetSum);
            break;
        }
        else if(sum>targetSum)
            j--;
        else
            i++;
    }

}

int main()
{
    printf("Pair of elements with sum K!\n");

    //int A[]={6,3,8,10,16,7,5,1,9,14};
    int A[]={2,3,4,5,6,7,9,10,14,16};
    //FindPairWithSumK(A,10,16,10);
    FindPairWithSumKInSortedArray(A,10,10);
    return 0;
}
