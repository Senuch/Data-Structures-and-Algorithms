#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void Create(struct Stack *st,int size)
{
    (*st).size=size;
    (*st).top=-1;
    (*st).s=(int *)malloc(sizeof(int)*((*st).size));
}

void Display(struct Stack s)
{
    for(int i=s.top;i>=0;i--)
        printf("%d ",*(s.s+i));
    printf("\n");

}


int isEmpty(struct Stack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}

int isFull(struct Stack s)
{
    if(s.top==s.size-1)
        return 1;
    return 0;
}

void Push(struct Stack *s,int value)
{
    if(isFull(*s))
        return;
    (*s).top++;
    *((*s).s+(*s).top)=value;

}

int Pop(struct Stack *s)
{
    if(isEmpty(*s))
        return -1;
    return *((*s).s+(((*s).top)--));
}

int Peek(struct Stack s,int index)
{
    if(s.top-index+1<0){
        printf("\nInvalid Index\n");
        return -1;
    }

    return *(s.s+(s.top-index+1));

}

int StackTop(struct Stack st)
{
    if(isEmpty(st))
        return -1;

    return *(st.s+(st.top));

}

int main()
{
    printf("Stack using array!\n");

    struct Stack *stack;

    Create(stack,5);

    Push(stack,1);
    Push(stack,2);
    Push(stack,3);
    Push(stack,4);
    Push(stack,5);

    Display(*stack);

    printf("\n%d\n",Pop(stack));

    Display(*stack);

    printf("\n%d",Peek(*stack,1));
    printf("\n%d",StackTop(*stack));

    return 0;
}
