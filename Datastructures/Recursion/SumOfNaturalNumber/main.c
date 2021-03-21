#include <stdio.h>
#include <stdlib.h>


//Time Complexity => O(n)
// Space Complexity => O(n)
int SumNaturalNumbers(int n)
{
    if(n==0)
        return 0;
    return n+SumNaturalNumbers(n-1);

}

int main()
{
    printf("Recursive sum of natural numbers!\n");
    printf("%d\n",SumNaturalNumbers(3));
    return 0;
}
