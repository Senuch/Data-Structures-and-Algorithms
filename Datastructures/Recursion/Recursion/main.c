#include <stdio.h>
#include <stdlib.h>

// Head Recursion
void fun1(int n)
{
    if(n>0)
    {
        fun1(n-1);
        printf("%d\n",n);
    }
}

// Tail Recursion
void fun2(int n)
{
    if(n>0)
    {
        printf("%d\n",n);
        fun2(n-1);
    }
}

// Tree Recursion O(2^n) time complexity.
void TreeRecursion(n)
{
    if(n>0)
    {
        printf("%d\n",n);
        TreeRecursion(n-1);
        TreeRecursion(n-1);
    }
}

// Indirect Recursion.

// Need to define function to avoid errors.
void IndirectB(int n);

void IndirectA(int n)
{
    if (n>0)
    {
        printf("%d",n);
        IndirectB(n-1);
    }
}

void IndirectB(int n)
{
    if(n>0)
    {
        printf("%d",n);
        IndirectA(n-1);
    }
}

// Nested recursion.
int NestedRecursion(int n)
{
    if(n>100)
        return n-10;
    return NestedRecursion(NestedRecursion(n+11));
}

int main()
{
    //int x=3;
    //fun1(x);

    //TreeRecursion(3);
    //IndirectA(3);
    printf("%d",NestedRecursion(95));
    return 0;
}
