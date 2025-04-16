#include <stdio.h>


int main()
{
 int rows ,cols,i,j;
 printf("Enter no of row and col\n");
 scanf("%d",&rows);
 scanf("%d",&cols);
 int array[rows][cols];
 printf("enter elements\n");
 for( i=0; i<rows; i++)
 {
 for(j=0; j<cols; j++)
 {
 scanf("%d",&array[i][j]);
 }
 }

printf("Array contents:\n");
 for (int i = 0; i < rows; i++)
 {
 for (int j = 0; j < cols; j++)
 {
 printf("%5d ", array[i][j]);
 }
 printf("\n");
 }

 printf("\n");
 printf("Row-major order:\n");
 for (int i = 0; i < rows; i++)
 {
 for (int j = 0; j < cols; j++)
 {
 printf("%2d ", array[i][j]);
 }
 printf("\n");
 }
 
 printf("Column-major order:\n");
 for (int j = 0; j < cols; j++)
 {
 for (int i = 0; i < rows; i++)
 {
 printf("%2d ", array[i][j]);
 }
 printf("\n");
 }

 printf("\n");
 return 0;
}
