/***************************************************************
 * Program to implement bubblesort in and array in C           *
 * Author: SOORAJ                                              *
 * Date: 12-10-26                                               *
 * Version: 1                                                  *
 ***************************************************************/

#include <stdio.h>

void bubblesort(int arr[], int n) {
    int temp=0;
    int flag=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break; //no swap - fully sorted
     }
}               

int main() {
    int n, i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

