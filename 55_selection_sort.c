
#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionsort(int *A, int n)
{
    int indexofMin, temp;
    printf("Running selection sort ... \n");
    for (int i = 0; i < n - 1; i++)
    {
        indexofMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexofMin])
            {
                indexofMin = j;
            }
        }
        // swap A[i] and A[indexofMin]
        temp = A[i];
        A[i] = A[indexofMin];
        A[indexofMin] = temp;
    }
}

int main()
{
    int A[] = {3, 5, 2, 4, 13, 2};
    int n = 6;
    printArray(A, n);
    selectionsort(A, n);
    printArray(A, n);

    return 0;
}