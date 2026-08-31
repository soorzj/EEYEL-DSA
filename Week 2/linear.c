
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
