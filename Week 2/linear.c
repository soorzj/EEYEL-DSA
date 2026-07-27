/************************************************
 * Program to perform linear search in an array *
 * version: 2									*
 * Date: 27 - 7 -26								*
 * Author: Sooraj								*
 ************************************************/
 
 
 #include <stdio.h>
 //function prototypes
  int lin_search(int *, int , int);  // function to search in a queue called a[] with 
  									//n as number of elements and x is the element to be found
  
  void main(){
  // the main function
 	int n,x; //n to store the number of elements, x to store the element to be found
 	printf("Enter number of elements:\n");
	scanf("%d", &n);
	int a[n]; //to store the array elements
	printf("Enter %d elements:\n", n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("Enter element to be found:\n");
	scanf("%d", &x);
	int p=lin_search(a,n,x);
	if (p==-1)
		printf("Element not found in array\n");
	else
		printf("Element found in array at %d\n",p);
	}
 
 int lin_search (int a[], int n, int x){
 	for(int i=0; i<n;i++)
 		if(a[i]==x)
 			return i;
 		return -1;
 	}
 
