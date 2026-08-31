```c
/************************************************
 * Program to perform linear search in an array *
 * Version: 3                                   *
 * Date: 31 - 8 - 26                            *
 * Author: Sooraj                               *
 ************************************************/

#include <stdio.h>


/* Function prototype for searching an element in an array. */
int linearSearch(int array[], int numberOfElements, int searchElement);


int main()
{
    int numberOfElements, searchElement;

    /* Read the number of elements that will be stored in the array. */
    printf("Enter number of elements:\n");
    scanf("%d", &numberOfElements);

    /* Create an array with the required number of elements. */
    int array[numberOfElements];

    /* Read each element of the array from the user. */
    printf("Enter %d elements:\n", numberOfElements);

    for (int i = 0; i < numberOfElements; i++)
        scanf("%d", &array[i]);

    /* Read the element that needs to be searched in the array. */
    printf("Enter element to be found:\n");
    scanf("%d", &searchElement);

    /* Perform linear search and store the position returned by the function. */
    int position = linearSearch(array, numberOfElements, searchElement);

    /* A return value of -1 indicates that the element was not found. */
    if (position == -1)
        printf("Element not found in array\n");

    /* Otherwise, display the position at which the element was found. */
    else
        printf("Element found in array at %d\n", position);

    return 0;
}


/*
 * Function: linearSearch
 * Purpose: Searches the array from beginning to end for the required element.
 */
int linearSearch(int array[], int numberOfElements, int searchElement)
{
    /* Check every array element sequentially until the required element is found. */
    for (int i = 0; i < numberOfElements; i++)
    {
        /* Return the index immediately when the search element is found. */
        if (array[i] == searchElement)
            return i;
    }

    /* Return -1 after checking the entire array without finding the element. */
    return -1;
}
```
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
 
