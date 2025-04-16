#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void insertionSort(int *A, int n){
    // Look for passes  
    int key , j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){// assending order is (>) greater thane used 
        // desending order used for is (<) lass than order 
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main()
{
//  -1   0   1   2   3   4  5
     // 12, 54, 65, 07, 23, 09
     // 12, 54, 65, 07, 23, 09 --> 1st pass done!
     // 12, 54, 65, 07, 23, 09 
    int A[] = {12,
               54,
               65,
               7,
               23,
               9};
    int n = 6;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);

    return 0;
}
