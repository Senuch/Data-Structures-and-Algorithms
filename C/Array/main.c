#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5];

    A[0]=12;
    A[1]=15;
    A[2]=25;

    printf("%d\n",A[2]);
    printf("%d\n",sizeof(A)); // Length of an array is 5*4 bytes is the size of each int

    int B[] = {1,2,3,4,5};
    int C[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i=0;i<10;i+=1){
        printf("%d\n",C[i]);
    }

    int n;
    scanf("%d",&n);
    int DynamicArray[n];

    return 0;
}
