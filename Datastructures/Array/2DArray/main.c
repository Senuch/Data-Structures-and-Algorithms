#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("2D Array!\n");

    // 1st method;

    int A[2][2]={{1,2},{3,4}};

    // 2nd Method with pointer array in stack but array itself in heap.
    int *B[2];
    B[0] = (int *)malloc(2*sizeof(int));
    B[1] = (int *)malloc(2*sizeof(int));

    B[0][1]=1;
    B[0][2]=2;
    B[1][1]=3;
    B[1][2]=4;

    // 3rd Method with array pointer in stack only.
    int **C;
    C = (int **)malloc(2*sizeof(int));
    C[0]=(int *)malloc(2*sizeof(int));
    C[1]=(int *)malloc(2*sizeof(int));

    C[0][1]=1;
    C[0][2]=2;
    C[1][1]=3;
    C[1][2]=4;

    printf("%d\n",C[1][2]);

    free(B[0]);
    free(B[1]);
    free(C[0][1]);
    free(C[0][2]);
    free(C[0]);
    free(C[1]);

    return 0;
}
