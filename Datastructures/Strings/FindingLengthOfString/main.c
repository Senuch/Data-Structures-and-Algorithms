#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Finding length of string!\n");

    char string[]="";

    int i=0;
    while(string[i]!='\0')
        i++;

    printf("Length of string %d",i);

    return 0;
}
