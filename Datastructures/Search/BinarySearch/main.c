#include <stdio.h>
#include <stdlib.h>

// Time Complexity -> O(log(n))
// Space Complexity -> O(1)
int BinarySearchIterative(int array[], int length,int key)
{
    if(length==0)
        return -1;
    int l=0;
    int h=length-1;
    int mid = 0;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(key == array[mid])
            return mid;
        if(key > array[mid])
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}

// Time Complexity -> O(log(n))
// Space Complexity -> O(log(n))
int BinarySearchRecursive(int array[], int length, int key, int l, int h)
{
    if(length==0)
        return -1;
    int mid = (l+h)/2;
    if(key==array[mid])
        return mid;
    if(l>h)
        return -1;
    return BinarySearchRecursive(array, length, key, key>mid?mid+1:l,key<mid?mid-1:h);
}

//MODE=0 -> Iterative.
//MODE=1 -> Recursive.
int BinarySearch(int array[], int length,int key, int MODE)
{
    return MODE==0 ? BinarySearchIterative(array, length, key) : BinarySearchRecursive(array, length, key, 0, length);
}

int main()
{
    int data[] = {1,2,3,4,5,6,7,8,9,10};

    //printf("Binary Search Iterative!\n");
    //printf("%d\n",BinarySearch(data, 10, 10,0));

    printf("Binary Search Recursive!\n");
    printf("%d\n",BinarySearch(data, 10, 2,1));

    return 0;
}
