#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

void Push(struct Node ** s,char value)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    (*t).data=value;
    (*t).next=*s;

    *s=t;
}

char Pop(struct Node ** s)
{
    char x='*';

    struct Node *temp=*s;

    if(!temp)
        return x;
    else
    {
        x=(*temp).data;
        *s=(**s).next;
        free(temp);
    }

    return x;
}

void Display(struct Node *s)
{

    while(s)
    {
        printf("%c ",(*s).data);
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

// Time Complexity O(n)
// Space Complexity O(n)
void ParenthesisMatchUsingStack(char str[])
{
    struct Node *stack = NULL;

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')
            Push(&stack,str[i]);
        else if(str[i] == ')')
        {
            if(Pop(&stack)== '*')
            {
                printf("Not Balanced");
                return;
            }
        }
    }

    printf("%s ",!Count(stack)? "Balanced" : "Not Balanced");

}

int main()
{
    printf("Parenthesis Matching!\n");

    ParenthesisMatchUsingStack(")");

    return 0;
}
