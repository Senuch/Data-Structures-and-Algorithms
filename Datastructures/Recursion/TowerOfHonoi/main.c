#include <stdio.h>
#include <stdlib.h>

// Time Complexity => O(2^n) Space Complexity => O(n)
void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("from %d to %d",A,C);
        TOH(n-1,B,A,C);
    }
}

int main()
{
    printf("Tower of Honoi!\n");

    int i=0;
    printf("%d",++i);

    return 0;
}
