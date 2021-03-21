#include <stdio.h>
#include <stdlib.h>

// Time complexity O(N)
int main()
{
    printf("Finding duplicates in string!\n");

    char string[] = "finding";

    int x,h;
    x=h=0;

    for(int i=0;string[i]!='\0';i++)
    {
        x=1;
        x=x<<string[i]-97;
        if((x&h)>0)
            printf("%c is a duplicate value\n",string[i]);
        else
            h=x|h;
    }

    return 0;
}
