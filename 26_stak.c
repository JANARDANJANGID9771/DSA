 #include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
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

int isFull(struct stack *ptr)
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
    if (isFull(ptr))
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

int main()
{
    // SP = STRUCT POINTER
    /* thias calulate the size ,arr, top value difinde   */
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(sp, 1);
    push(sp, 12);
    push(sp, 56);
    push(sp, 46);
    push(sp, 46);
    push(sp, 69);
    push(sp, 66);
    push(sp, 76);
    push(sp, 86);
    push(sp, 6);  //--> pushed10 values
    push(sp, 46); // stack overflow since the size of the

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
    // that output is = 0, 1;
    printf("popped %d from the stack\n", POP(sp));//-->Last in first out 
    printf("popped %d from the stack\n", POP(sp));//-->Last in first out 
    printf("popped %d from the stack\n", POP(sp));//-->Last in first out
    printf("popped %d from the stack\n", POP(sp));//-->Last in first out
    
    return 0;
}