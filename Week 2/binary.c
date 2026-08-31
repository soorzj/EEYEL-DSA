
/************************************************
 * Program : Binary Search in an Array
 * Version : 3
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program performs binary search on an array.
 * The array is first sorted using bubble sort because
 * binary search requires the elements to be arranged
 * in sorted order.
 *
 * Operations:
 * 1. Input Array   - Read elements into the array
 * 2. Sort Array    - Arrange elements using bubble sort
 * 3. Display Array - Display the sorted array
 * 4. Binary Search - Search for the required element
 ************************************************/

#include <stdio.h>


/* Function prototype for sorting the array using bubble sort. */
void sort(int array[], int numberOfElements);

/* Function prototype for searching an element using binary search. */
int binarySearch(int array[], int numberOfElements, int searchElement);


int main()
{
    int numberOfElements, searchElement;

    /* Read the number of elements that will be stored in the array. */
    printf("Enter number of elements:\n");
    scanf("%d", &numberOfElements);

    /* Create an array with the required number of elements. */
    int array[numberOfElements];

    /* Read all the elements of the array from the user. */
    printf("Enter %d elements:\n", numberOfElements);

    for (int i = 0; i < numberOfElements; i++)
        scanf("%d", &array[i]);

    /* Sort the array because binary search requires sorted elements. */
    sort(array, numberOfElements);

    /* Display the array after sorting. */
    printf("Sorted Array\n");

    for (int i = 0; i < numberOfElements; i++)
        printf("%d\t", array[i]);

    printf("\n");

    /* Read the element that needs to be searched. */
    printf("Enter element to be found:\n");
    scanf("%d", &searchElement);

    /* Perform binary search and store the returned position. */
    int position = binarySearch(array, numberOfElements, searchElement);

    /* A return value of -1 indicates that the element was not found. */
    if (position == -1)
        printf("Element not found in array\n");

    /* Otherwise, display the position at which the element was found. */
    else
        printf("Element found in array at %d\n", position);

    return 0;
}


/*
 * Function : sort
 * Purpose  : Sorts the array in ascending order using bubble sort.
 * From Sooraj's Github
 */
void sort(int array[], int numberOfElements)
{
    /* Each pass moves the largest unsorted element towards the end. */
    for (int x = 0; x < numberOfElements - 1; x++)
    {
        /* Compare adjacent elements in the unsorted portion of the array. */
        for (int y = 0; y < numberOfElements - x - 1; y++)
        {
            /* Swap the elements when they are in the wrong order. */
            if (array[y] > array[y + 1])
            {
                int temporaryValue = array[y];

                array[y] = array[y + 1];
                array[y + 1] = temporaryValue;
            }
        }
    }
}


/*
 * Function : binarySearch
 * Purpose  : Searches the sorted array using binary search.
 */
int binarySearch(int array[], int numberOfElements, int searchElement)
{
    int low = 0;
    int high = numberOfElements - 1;

    /* Continue searching while the valid search range is not empty. */
    while (low <= high)
    {
        /* Calculate the middle position of the current search range. */
        int middle = (low + high) / 2;

        /* Return the position when the middle element matches the search element. */
        if (array[middle] == searchElement)
            return middle;

        /* Search the right half when the middle element is smaller. */
        else if (array[middle] < searchElement)
            low = middle + 1;

        /* Search the left half when the middle element is larger. */
        else
            high = middle - 1;
    }

    /* Return -1 when the search element does not exist in the array. */
    return -1;
}
