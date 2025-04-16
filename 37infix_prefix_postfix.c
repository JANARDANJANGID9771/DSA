
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// infix to postfix and prefix

struct stack
{
    int size;
    int top;
    char *arr;
};

int stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}

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

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}
int isoperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 1;
    else    
        return 0;
}
char * infixToPostfix(char* infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char * postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')  
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = POP(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = POP(sp); // sp = stack pointer
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char * infix = "x-y/z-k*d";// this is fowared ia question  

    printf("postfix is %s", infixToPostfix(infix));

    return 0;
}
