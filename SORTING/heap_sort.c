/***************************************************************
 * Program to implement heapsort in an array in C              *
 * Author: SOORAJ                                              *
 * Date: 12-10-26                                               *
 * Version: 1                                                  *
 ***************************************************************/

#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    int temp=0;
    if(left<n && arr[left]>arr[largest])
        largest=left;
    if(right<n && arr[right]>arr[largest])
        largest=right;
    if(largest!=i){
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    int temp=0;
    for(int i=n/2-1;i>=0;i--)
        heapify(arr, n, i);
    for(int i=n-1;i>0;i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr, i, 0);
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
    heap_sort(arr, n);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
