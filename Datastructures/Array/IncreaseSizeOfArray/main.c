#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Increasing size of array!\n");

    int *p = (int *)malloc(5*sizeof(int));
    p[0]=1;
    p[1]=2;
    p[2]=3;
    p[3]=4;
    p[4]=5;

    for(int i=0;i<5;i++)
    {
        printf("%d\n",p[i]);
    }

    int *q = (int *)malloc(10*sizeof(int));

    for(int i=0;i<5;i++)
        q[i]=p[i];

    free(p);
    p=q;
    q=NULL;

    p[5]=99;

    for(int i=0;i<=5;i++)
        printf("%d\n",p[i]);

    return 0;
}
