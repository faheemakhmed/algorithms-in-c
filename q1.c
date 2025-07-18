//program to create a 1-D array and display the elements of the array
#include<stdio.h>

int main(){
    int n,i;

    //Ask user for the number of elements
    printf("enter the number of elements in the array");
    scanf("%d",&n);

    //declare the array
    int arr[n];

    //input elements into the array
    printf("enter %d elements: \n ", n);
    for(i=0;i<n;i++){
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    //display the elements of the array
    printf("\nThe elemenyts of the array are: \n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}