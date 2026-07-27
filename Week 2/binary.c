/************************************************
 * Program to perform binary search in an array	*
 * version: 2									*
 * Date: 27 - 7 -26								*
 * Author: Sooraj								*
 ************************************************/
 
 #include <stdio.h>
 //function prototypes
void sort(int *, int);				//function to sort the elements using bubble sort
int bin_search(int*, int, int);	 	// the binary search fucntion that accpets the array a[], 
									//element count n anf search element x and returns the position of element
 
 void main(){
 // the main function
 	int n,x; //n to store the number of elements, x to store the element to be found
 	printf("Enter number of elements:\n");
	scanf("%d", &n);
	int a[n]; //to store the array elements
	printf("Enter %d elements:\n", n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	sort(a,n);  //sort using bubble sort becuase its binary search
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
 	
 
