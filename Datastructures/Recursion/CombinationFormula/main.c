#include <stdio.h>
#include <stdlib.h>

// We can easily solve this problem using the factorial function we coded earlier with O(n)
// time complexity. The formula is n!/r!(n-r)!

// We can also use pascal triangle.

int CombinationFormula(int n, int r)
{
    if(n==r || r==0)
        return 1;
    return CombinationFormula(n-1,r-1)+CombinationFormula(n-1,r);
}

int main()
{
    printf("Combination Formula!\n");
    printf("%d\n",CombinationFormula(4,2));
    return 0;
}
