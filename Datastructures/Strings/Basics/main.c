#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Strings!\n");

    //Declaring a string
    char name[]="Uzair Tariq";
    printf("%s\n",name);

    char *anotherName="SecondName";

    char input_first_name[20];
    printf("Enter first name:");
    fgets(input_first_name,20,stdin);
    printf("%s",input_first_name);

    char input_full_name_with_space[20];
    printf("\nEnter full name:");
    gets(input_full_name_with_space);
    printf("%s\n",input_full_name_with_space);

    return 0;
}
