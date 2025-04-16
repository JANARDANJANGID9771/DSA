# include <stdio.h>


// operaction in Array in dsa 
// input array in 200 
// array display





void display(int arr [],int n){
for ( int i = 0; i < n; i++)
{
    printf("%d\n", arr[i]);
}

}

int main(){
    
int arr[200] = { 1, 2, 6, 78};
display(arr,4);


    return 0;
}