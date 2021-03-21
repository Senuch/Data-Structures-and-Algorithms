#include <stdio.h>
#include <stdlib.h>

// Time&Space Complexity O(n)
int Power(int m,int n)
{
    if(n==0)
        return 1;
    return m*Power(m,n-1);
}

int main()
{
    printf("Power Function!\n");
    printf("%d\n",Power(0,5));
    return 0;
}
