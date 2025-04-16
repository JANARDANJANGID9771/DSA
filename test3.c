
#include <stdio.h>

// operaction in Array in dsa
// input array in 200
// array display
/*FOR VISITE IN ARRAY  C
arr[200] = { 1, 2, 6, 78}; this mean is syntax is 200 element used for 4 arr yaa for element
*/

// TRAVERSAL

void display(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// INSERTION
int indInsertion(int arr[], int size, int element, int capacity, int index)
{

    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88}; // this is time complixy is 0(n) of inseration
    int size = 5, element = 45, index = 1;
    display(arr, size);
    indInsertion(arr, size, element, 100, index);
    size += 1;
    display(arr, size);

    return 0;
}