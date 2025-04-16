#include<stdio.h>
#include<stdlib.h>

// calloc
// syntax

// pointer = (csat-type *)calloc(n, sizeofElement);
// pointer = (int *)calloc(5, sizeof(int))
 
int main()
{
    int *pointer;
    int n;

    n=5;
    printf("Enter number of element: %d \n", n);

    pointer =(int*)calloc(n, sizeof (int));

     if(pointer == NULL){
        printf("Memory is not allocated \n");
        exit(0);
        
     }
    else{
        printf("Memory is successfully allocate")
    }




    return 0;
}
