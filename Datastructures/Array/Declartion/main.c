#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Array Declartion!\n");

    int A[5]; //Creates array with garbage.
    int B[5]={1,2,3,4,5};   // Creates array with explicit initialized values.
    int C[10]={2,4,6};  // Creates an array with first three as explicit initialized and last will default to false.
    int D[5]={0};   // All default to 0;
    int E[]={1,2,3,4,5};    // Dynamic sized array depends on the init values.

    for(int i=0;i<5;i+=1)
    {
        printf("%u \n",&A[i]);  // Will prints the address of array indexes which are continous in nature with each address consuming 4 bytes(depending on OS and compiler).
    }

    return 0;
}
