#include <stdio.h>
#include <stdlib.h>

// Time Complexity O(n)
// Space Complexity O(1)
void FindMinMax(int A[], int count)
{
    int min=A[0];
    int max=A[0];

    for(int i=1;i<count;i++)
    {
        if(A[i]<min)
            min=A[i];
        else if(A[i]>max)
            max=A[i];
    }

    printf("Min:%d Max:%d",min,max);

}

int main()
{
    printf("Finding Min/Max!\n");

    int A[]={1,2,3,4,5,6,7,8,9,10};

    FindMinMax(A,10);

    return 0;
}
