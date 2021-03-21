#include <stdio.h>
#include <stdlib.h>

// Time Complexity => O(2^n) Space Complexity => O(n)
int Fibonacci(int number)
{
    if(number <= 1)
        return number;
    return Fibonacci(number-1)+Fibonacci(number-2);
}

int main()
{
    printf("Fibonacci Series!\n");
    printf("%d\n",Fibonacci(10));

    return 0;
}
