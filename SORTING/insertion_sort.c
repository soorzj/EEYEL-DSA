/***************************************************************
 * Program to implement insertion sort in and array in C       *
 * Author: SOORAJ                                              *
 * Date: 12-10-26                                              *
 * Version: 1                                                  *
 ***************************************************************/

#include <stdio.h>

void insertionsort(int arr[], int n) {
    int key;
    for(int i=0; i<n;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
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
    insertionsort(arr, n);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

