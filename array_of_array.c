# include <stdio.h>

// passing array of array 
void printArrayofArray(int array [3] [3])
{
     printf("%d", array [2] [1]);     
}

int main ()
{
    int arr[3] [3] = {{1,2, 3}, {10}, {100, 200}};

    printArrayofArray(arr);

    return 0;

}