#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Static vs Dynamic!\n");

    int A[10]; //Created in stack;
    int *p;
    p = (int *)malloc(5*sizeof(int));
    p[0] = 3;
    printf("%d\n",p[0]);

    free(p);

    return 0;
}
