
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

char stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int match(char a, char b)
{

    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesismatch(char *exp)
{
    // create and initalize the stack
    // this meane is || = or
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char POPed_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            POPed_ch = POP(sp);
            if (!match( POPed_ch,  exp[i]))
            {
                return 0;
            }
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
    char *exp = " {[((8)( 9-8))]}";

 
    if (parenthesismatch(exp))
    {
        printf("The  parenthesis is  balanced");
    }
    else
    {
        printf("The parenthesis is not   balanced");
    }

    return 0;
}