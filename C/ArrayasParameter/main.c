#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

void fun(int A[], int n)// A[] is a pointer to an array and can be written as int *A. Both are similar.
//*A is more generic and can point to anything, while A[] is limited to array. Arrays are always pass
// by address.
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",A[i]);
    }
}

int * Array(int size){ //Return type int [] can also be written as int * again both are same but the first one is specific and limited to arrays,
    // while the second one is more general.
    int *p;
    p=(int *)malloc(size*sizeof(int));
    return p;
}

// Struct pass by value.
int area(struct Rectangle r)
{
    return r.breadth*r.length;
}

int area_by_address(struct Rectangle *r)
{
    return (*r).length*(*r).breadth; // can also be written in r->length*r->breadth in short form.
}

// Returning the address of structure created on heap memory.
struct Rectangle * returnStructAddress(){
    struct Rectangle *ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    (*ptr).length=212;
    return ptr;
};

int main()
{
    int A[5]={1,2,3,4,5};

    //fun(A, 5);

    //------
    int *A2;
    //A2=Array(3);

    //------

    struct Rectangle r = {10,3};

    printf("%d\n",area(r)); // Call to pass by value.
    printf("%d\n",area_by_address(&r)); // Call to pass by address.

    //NOTE! One important thing to remember is that array encapsulated inside struct will be pass by value

    // Getting address of structure created on heap pointer.
    struct Rectangle *structPtr = returnStructAddress();

    printf("%d\n",structPtr->length);

    return 0;
}
