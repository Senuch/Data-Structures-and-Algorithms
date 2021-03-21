#include <stdio.h>
#include <stdlib.h>

// Pointer is used to access resources external to program like printer, filesystem and stuff like that and for accessing heap memory.
// Size of pointer is independent of the data type, i.e. int, float, double all of these different pointer types take 8 bytes regardless of their type.

int main()
{
    int a = 10;
    printf("%d\n",a);

    int *pointer; // Declaring pointer.
    pointer = &a;   // Assigning address to pointer.
    printf("%d\n",pointer); // Printing address of pointer.
    printf("%d\n",*pointer); // Dereferencing pointer to display the value it is pointing to.
    printf("%d,%d\n",*pointer,&a); // We are displaying the address of a and the address pointer points too, both should be same.

    int A[5]={1,2,3,4,5};
    int *p;
    p=A;
    int *p2;
    p2=&A[0];

    int *heapArray;
    heapArray = (int *)malloc(5*sizeof(int));

    for(int i=0;i<5;i++)
    {
        heapArray[i]=i;
    }

    for(int i=0;i<5;i++)
    {
        printf("%d\n",heapArray[i]);
    }

    free(p);

    return 0;
}
