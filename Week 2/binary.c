/* Program to perform binary search in an array
 * version: 1
 * Date: 27 - 6 -26
 * Author: Sooraj
 */
 #include <stdio.h>
 void sort(int a[], int n){
	 for (int x=0; x<n-1; x++)
	 	for(int y=0;y<n-x-1;y++)
	 		if(a[y]>a[y+1]){
	 			int temp=a[y];
	 			a[y]=a[y+1];
	 			a[y+1]=temp;
	 			}
	 }
	 
 int bin_search (int a[], int n, int x){
 	int low=0,high=n-1;
 	while(low<=high){
 		int mid=(low+high)/2;
 		if(a[mid]==x)
 			return mid;
 		else if(a[mid] < x)
 			low=mid+1;
 		else
 			high=mid-1;
 		}
 		return -1;
	}
 	
 void main(){
 	int n,x;
 	printf("Enter number of elements:\n");
	scanf("%d", &n);
	int a[n];
	printf("Enter %d elements:\n", n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	sort(a,n);
	printf("Sorted Array\n");
	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
	printf("Enter element to be found:\n");
	scanf("%d", &x);
	int p=bin_search(a,n,x);
	if (p==-1)
		printf("Element not found in array\n");
	else
		printf("Element found in array at %d\n",p);
	}
