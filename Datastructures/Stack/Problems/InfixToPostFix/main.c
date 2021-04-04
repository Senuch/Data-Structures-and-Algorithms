#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char oper;
    int presc;
    struct Node *next;
};

void Push(struct Node ** s, char oper, int presc)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    (*t).oper=oper;
    (*t).presc=presc;
    (*t).next=*s;

    *s=t;
}

char Pop(struct Node ** s)
{
    char x='\O';

    struct Node *temp=*s;

    if(!temp)
        return x;
    else
    {
        x=(*temp).oper;
        *s=(**s).next;
        free(temp);
    }

    return x;
}

void Display(struct Node *s)
{

    while(s)
    {
        printf("%c ",(*s).oper);
        s=(*s).next;
    }
    printf("\n");
}

int Count(struct Node *s)
{
    if(!s)
        return 0;

    int count=0;

    while(s)
    {
        s=(*s).next;
        count+=1;
    }

    return count;
}

void HandleOperator(struct Node ** stack, char oper, int presc)
{
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    (*temp).oper=oper;
    (*temp).presc=presc;

    while(*stack && (**stack).presc >= presc)
    {
        char popped=Pop(stack);
        if(popped)
            printf("%c",popped);
        else
            break;
    }

    (*temp).next=*stack;
    *stack=temp;

}

void InfixToPostFix(char str[])
{
    struct Stack *stack=NULL;

    for(int i=0;str[i]!='\0';i++)
    {
        switch(str[i])
        {
            case '+':
            case '-':
                HandleOperator(&stack,str[i],1);
                break;
            case '/':
            case '*':
                HandleOperator(&stack,str[i],2);
                break;
            default:
                printf("%c",str[i]);
                break;
        }

    }

    while(stack)
        printf("%c",Pop(&stack));

}

int main()
{
    printf("Infix to Postfix!\n");

    InfixToPostFix("a+b*c+d");

    return 0;
}
