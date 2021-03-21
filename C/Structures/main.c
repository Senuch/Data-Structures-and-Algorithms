#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

// We are defining a structure and declaring the variables in the same place.
struct Square
{
    int width;
    int height;
} s1,s2;

int main()
{

    struct Rectangle r;
    struct Rectangle r2={10,5};

    printf("%d\n",r2.length);
    printf("%d\n",r2.breadth);

    printf("Area of rectangle::%d\n",r2.breadth*r2.length);

    struct Rectangle r3[2] = {{1,2}, {3,4}};
    printf("Rectangle%d\n",r3[0].length);

    return 0;
}
