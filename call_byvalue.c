#include<stdio.h>

void printSomething(int *num)
{
   *num =20;
    printf("Number in function is %d \n", *num);

}
int main()
{
int data = 10;

//pass the by value 
    printSomething(&data);

// pass by reference

printf("Number in main function is %d \n", data );

    return 0;
}