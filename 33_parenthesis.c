
#include <stdio.h>
#include <stdlib.h>

// this is char number are using
struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// PUSH
void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("stack overFlow! cannot  Push %d  to the stack \n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// POP
int POP(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack underFlow! cannot pop from to the stack \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesismatch(char *exp)
{
    // create and initalize the stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            POP(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
}

int main()
{
    // this syntax is matching 
    // this is serial wise matching 
    char *exp = " ((8)*(9))";
 
    // check if stack is empty
    if (parenthesismatch(exp))
    {
        printf("The  parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }

    return 0;
}
 