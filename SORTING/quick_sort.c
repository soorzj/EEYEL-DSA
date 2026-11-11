/***************************************************************
 * Program to implement quicksort in an array in C             *
 * Author: SOORAJ                                              *
 * Date: 12-10-26                                               *
 * Version: 1                                                  *
 ***************************************************************/

#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=low-1;
    int temp=0;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}

void quicksort(int arr[], int low, int high) {
    if(low<high){
        int i=partition(arr, low, high);
        quicksort(arr, low, i-1);
        quicksort(arr, i+1, high);
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
    quicksort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
