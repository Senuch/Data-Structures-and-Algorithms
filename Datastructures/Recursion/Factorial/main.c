#include <stdio.h>
#include <stdlib.h>

// Time Complexity => O(n)
// Space Complexity => O(n)
int Factorial(int n)
{
    if(n==0)
        return 1;
    return n*Factorial(n-1);
}

int main()
{
    printf("Factorial!\n");
    printf("%d\n",Factorial(3));
    return 0;
}
