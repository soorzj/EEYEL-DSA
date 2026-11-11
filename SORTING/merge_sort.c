/****************************************************************
 * Program to implement mergesort in and array in C             *
 * Author: SOORAJ                                               *
 * Date: 12-10-26                                               *
 * Version: 1                                                   *
 ***************************************************************/

#include <stdio.h>
void merge(int[], int, int, int);//Function to sort and merge 2 halves into a bigger array
void merge_sort(int[], int, int);//Function to call merge fucntion recursively

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

void mergesort(int arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right) {
    int a=mid-left+1;
    int b=right-mid;
    int left_arr[a], right_arr[b];
        
    for(int i=0;i<a;i++)
        left_arr[i] = arr[left+i];
        
    for(int j=0;j<b;j++)
        right_arr[j] =arr[mid+j+1];
    
    int i=0,j=0,k=left;
    while(i<a && j<b){
        if(left_arr[i] <= right_arr[j])
            arr[k]=left_arr[i++];
        else
            arr[k]=right_arr[j++];
        k++;
    }
    //copy the remaining back.
    
}               