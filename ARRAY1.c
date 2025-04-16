#include <stdio.h>

int main()
{
    //syntax 
    //data Type variable Name [size of array ] = {value1, value2, value3 .....}

    int numbers[5] = {10, 20, 30, 40, 50};
   
// outpue is enterd in index 
// Access element in array -> through indexex

    printf("%d \n", numbers[0]);
    printf("%d \n", numbers[1]);
    printf("%d \n", numbers[2]);
    printf("%d \n", numbers[3]);
    printf("%d \n", numbers[4]);

    // using for loop in array 

    // for ( int i = 0; i < 5; i++)
    // {
    //     printf("%d \n",  number [i]);

    // }
     
    // for ( int  i = 4; i >= 0; i--)
    // {
    //      printf("%d \n",  number [i]);

    // }
    
    
    return 0;
}