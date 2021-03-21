#include <stdio.h>
#include <stdlib.h>

// Time/Space Complexity => O(n)
double TaylorSeries(double x, double n)
{
    // Static variables are declared and initialized only once.
    static double power=1, factorial=1;

    if(n==0)
        return 1;
    double result = TaylorSeries(x,n-1);
    power = power*x;
    factorial=factorial*n;

    return result+(power/factorial);


}

int main()
{
    printf("Taylor Series!\n");
    printf
    ("%lf\n",TaylorSeries(4,10));
    return 0;
}
