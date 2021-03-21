#include <stdio.h>
#include <stdlib.h>

// Call by value.
int add(int a, int b)   // Prototype/declaration of function
{ // Definition of function.
    int c;
    c = a+b;
    return c;
}

// Call by address.
void CallByAddreessAdd(int *a, int *b)   // Prototype/declaration of function
{ // Definition of function.
    int c;
    *a = *a+*b;
}

// Call by reference, only in c.
void add(int &a, int &b)   // Prototype/declaration of function
{ // Definition of function.
    a = a+b;
}

int main()
{
    int x,y,z;

    x=12;
    y=5;

    z=add(x,y);

    printf("%d\n",z);

    //-------------

    CallByAddreessAdd(&x,&y);
    printf("Call By Address Add %d\n",x);

    //-------------

    return 0;
}
