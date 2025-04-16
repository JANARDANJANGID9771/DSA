# include <stdio.h>

// create function

void printArrayofArray(int array [3] [3]) {

    printf("%d", array[2] [0]);

}

int main(){

    int arr[3] [3] = {{1,2,3}, {10}, {100,200}};

// call to function 

printArrayofArray(arr);

    return 0;
}