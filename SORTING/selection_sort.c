/***************************************************************
 * Program to implement selection sort in and array in C       *
 * Author: SOORAJ                                              *
 * Date: 12-10-26                                              *
 * Version: 1                                                  *
 ***************************************************************/

#include <stdio.h>

void selection_sort(int arr[], int n) {
    int temp, min_i;
    for(int i=0;i<n-1;i++){
        min_i=i;
        for(int j=i+1;j<n;j++)
            if(arr[min_i]>arr[j])
                min_i=j;
        if(min_i!=i){
            temp=arr[i];
            arr[i]=arr[min_i];
            arr[min_i]=temp;
        }    
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
    selection_sort(arr, n);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

