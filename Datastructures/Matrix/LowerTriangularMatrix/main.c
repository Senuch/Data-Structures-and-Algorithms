#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int dimension;
};

// Row Major
void Set(struct Matrix *m, int i, int j, int x)
{
    if(i>=j)
        *((*m).A+(i*((i-2)/2)+j-1))=x;

}

int Get(struct Matrix m, int i, int j)
{
    if(i>=j)
        return *(m.A+(i*((i-2)/2)+j-1));
    else
        return 0;
}

void Display(struct Matrix m)
{
    for(int i=1;i<=m.dimension;i++)
    {
        for(int j=1;j<=m.dimension;j++)
           {
                printf("%d ",Get(m,i,j));
           }
        printf("\n");
    }
}

// Column Major
void CSet(struct Matrix *m, int i, int j, int x)
{
    if(i>=j)
        {
            //printf("Index:%d Value:%d i:%d j:%d\n",(m->dimension*(j-1))-((j-2)*(j-1))/2+(i-j),x,i,j);
            *((*m).A+(((*m).dimension*(j-1))-((j-2)*(j-1))/2+(i-j)))=x;
        }
        else
            return 0;

}

int CGet(struct Matrix m, int i, int j)
{
    if(i>=j)
        return *(m.A+((m.dimension*(j-1))-((j-2)*(j-1))/2+(i-j)));
    else
        return 0;
}

void CDisplay(struct Matrix m)
{
    for(int i=1;i<=m.dimension;i++)
    {
        for(int j=1;j<=m.dimension;j++)
           {
                printf("%d ",CGet(m,i,j));
           }
        printf("\n");
    }
}

int main()
{
    printf("Lower Triangular Matrix!\n");

    struct Matrix m;
    m.dimension=4;
    m.A=(int *)malloc(sizeof(int)*(m.dimension*(m.dimension-1)/2));

    for(int i=1;i<=m.dimension;i++)
        for(int j=1;j<=m.dimension;j++)
            if(i>=j)
            {
                CSet(&m,i,j,j);
            }

    CDisplay(m);

    //for(int i=0;i<m.dimension;i++)
    //    printf("%d\n",m.A[i]);

    return 0;
}
