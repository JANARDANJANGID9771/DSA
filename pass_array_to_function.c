#include <stdio.h>
// PASS ARRAY TO FUNCTION

void printArray(int array[5] ,int size)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", array[i]);
    }
}



    int main()
    {
        int arr[5] = {10, 20, 30, 40, 50};
    
int size = 5;
    printArray(arr, size);

    return 0;
}