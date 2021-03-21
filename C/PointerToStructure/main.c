#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

int main()
{

    // Creating pointer of struct.
    struct Rectangle *pointer;

    // Creating struct.
    struct Rectangle rect = {1,2};

    printf("%d\n",rect.length);
    printf("%d\n",rect.breadth);

    // Assigning address of structure to pointer.
    pointer = &rect;

    // Printing values of struct using pointer...
    //1: Dereference the pointer first and then access the value.
    printf("%d\n",(*pointer).length);
    //2: We can skip the hectic syntax above and directly use `->` to access the value.
    printf("%d\n",pointer->length);

    // Creating struct on heap.

    // Creating pointer for struct.
    struct Rectangle *pHeap;

    // Creating struct on heap and assigning its address to the pointer.
    pHeap = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    // Setting value of struct.
    pHeap->breadth=2;
    pHeap->length=3;

    printf("%d\n",pHeap->breadth);
    printf("%d\n",pHeap->length);

    // Similar to the line above with syntactic sugar.
    printf("%d\n",(*pHeap).length);

    return 0;
}
