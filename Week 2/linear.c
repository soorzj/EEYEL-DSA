/* Program to perform linear search in an array
 * version: 1
 * Date: 27 - 6 -26
 * Author: Sooraj
 */
 #include <stdio.h>
 int lin_search (int a[], int n, int x){
 	for(int i=0; i<n;i++)
 		if(a[i]==x)
 			return i;
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
	printf("Enter element to be found:\n");
	scanf("%d", &x);
	int p=lin_search(a,n,x);
	if (p==-1)
		printf("Element not found in array\n");
	else
		printf("Element found in array at %d\n",p);
	}
