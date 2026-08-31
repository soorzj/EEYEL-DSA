/****************************************************
 * Program : Double-Ended Circular Queue Using Array
 * Version : 2
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program implements a double-ended queue (deque)
 * using a circular array. A deque allows insertion and
 * deletion of elements from both the front and back.
 *
 * Operations:
 * 1. Enqueue Front  - Insert an element at the front
 * 2. Enqueue Back   - Insert an element at the back
 * 3. Dequeue Front  - Remove an element from the front
 * 4. Dequeue Back   - Remove an element from the back
 * 5. See Front      - Display the front element
 * 6. See Back       - Display the back element
 * 7. Print Queue    - Display all queue elements
 * 8. Exit           - Terminate the program
 ****************************************************/

#include <stdio.h>

#define MAX 10

/* Array used to store the elements of the circular deque. */
int queue[MAX];

/* Front points to the first element and back points to the last element. */
int front = -1, back = -1;


/* Function prototypes for all deque operations. */
void enqueueFront(int value);   // Inserts an element at the front of the deque.
void enqueueBack(int value);    // Inserts an element at the back of the deque.
int dequeueFront(void);         // Removes and returns the front element.
int dequeueBack(void);          // Removes and returns the back element.
int seeFront(void);             // Returns the front element without removing it.
int seeBack(void);              // Returns the back element without removing it.
void print_queue(void);         // Displays all elements in their current deque order.
int isEmpty(void);              // Checks whether the deque contains no elements.
int isFull(void);               // Checks whether all positions in the circular array are occupied.


int main()
{
    /* Menu-driven main function used to perform different deque operations. */
    int choice = -1;
    int value, dequeued;

    printf("Menu for Queue\n");
    printf("1.Enqueue(front)\n2.Enqueue(back)\n3.Dequeue(front)\n4.Dequeue(back)\n5.See First Memeber\n6.See Last Memeber\n7.See the queue\n8.Exit\n");

    /* Continue displaying the menu until the user chooses Exit. */
    while (choice != 8)
    {
        printf("Enter Your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            /* Read an element and insert it at the front of the deque. */
            printf("Enter element to be queued at front:\n");
            scanf("%d", &value);

            enqueueFront(value);
            print_queue();

            break;
        }

        case 2:
        {
            /* Read an element and insert it at the back of the deque. */
            printf("Enter element to be queued at back:\n");
            scanf("%d", &value);

            enqueueBack(value);
            print_queue();

            break;
        }

        case 3:
        {
            /* Remove the front element and display it if the deque is not empty. */
            dequeued = dequeueFront();

            if (dequeued != -1)
                printf("Element dequeued from front: %d\n", dequeued);

            print_queue();

            break;
        }

        case 4:
        {
            /* Remove the back element and display it if the deque is not empty. */
            dequeued = dequeueBack();

            if (dequeued != -1)
                printf("Element dequeued from back: %d\n", dequeued);

            print_queue();

            break;
        }

        case 5:
        {
            /* Display the front element without removing it from the deque. */
            int frontElement = seeFront();

            if (frontElement != -1)
                printf("Topmost Element of queue: %d\n", frontElement);

            break;
        }

        case 6:
        {
            /* Display the back element without removing it from the deque. */
            int backElement = seeBack();

            if (backElement != -1)
                printf("Bottom-most Element of queue: %d\n", backElement);

            break;
        }

        case 7:
            /* Display all elements starting from front and following circular order. */
            print_queue();
            break;

        case 8:
            /* Terminate the program when the user selects Exit. */
            printf("Exiting the Program\n");
            break;

        default:
            /* Handle any menu option that is not available. */
            printf("Wrong Choice\n");
            break;
        }
    }

    return 0;
}


/*
 * Function : enqueueBack
 * Purpose  : Inserts a new element at the back of the deque.
 */
void enqueueBack(int value)
{
    /* A new element cannot be inserted when every position is occupied. */
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    /* For an empty deque, both front and back start at the first position. */
    if (isEmpty())
    {
        front = 0;
        back = 0;
    }

    /* If back reaches the last array position, wrap it around to position zero. */
    else if (back == MAX - 1)
    {
        back = 0;
    }

    /* Otherwise, move back one position towards the end of the array. */
    else
    {
        back++;
    }

    /* Store the new element at the updated back position. */
    queue[back] = value;

    printf("Queued at back\n");
}


/*
 * Function : enqueueFront
 * Purpose  : Inserts a new element at the front of the deque.
 */
void enqueueFront(int value)
{
    /* A new element cannot be inserted when every position is occupied. */
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    /* For an empty deque, both front and back start at the first position. */
    if (isEmpty())
    {
        front = 0;
        back = 0;
    }

    /* If front reaches position zero, wrap it around to the last position. */
    else if (front == 0)
    {
        front = MAX - 1;
    }

    /* Otherwise, move front one position towards the beginning of the array. */
    else
    {
        front--;
    }

    /* Store the new element at the updated front position. */
    queue[front] = value;

    printf("Queued at front\n");
}


/*
 * Function : dequeueFront
 * Purpose  : Removes and returns the element currently at the front.
 */
int dequeueFront()
{
    int dequeuedElement;

    /* An element cannot be removed when the deque is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    /* Store the front element before changing the front position. */
    dequeuedElement = queue[front];

    /* If front and back are equal, the removed element was the last element. */
    if (front == back)
    {
        front = -1;
        back = -1;
    }

    /* If front is at the last array position, wrap it around to position zero. */
    else if (front == MAX - 1)
    {
        front = 0;
    }

    /* Otherwise, move front one position towards the back. */
    else
    {
        front++;
    }

    return dequeuedElement;
}


/*
 * Function : dequeueBack
 * Purpose  : Removes and returns the element currently at the back.
 */
int dequeueBack()
{
    int dequeuedElement;

    /* An element cannot be removed when the deque is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    /* Store the back element before changing the back position. */
    dequeuedElement = queue[back];

    /* If front and back are equal, the removed element was the last element. */
    if (front == back)
    {
        front = -1;
        back = -1;
    }

    /* If back reaches position zero, wrap it around to the last position. */
    else if (back == 0)
    {
        back = MAX - 1;
    }

    /* Otherwise, move back one position towards the beginning of the array. */
    else
    {
        back--;
    }

    return dequeuedElement;
}


/*
 * Function : seeFront
 * Purpose  : Returns the front element without removing it.
 */
int seeFront()
{
    /* The front element cannot be viewed when the deque is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return queue[front];
}


/*
 * Function : seeBack
 * Purpose  : Returns the back element without removing it.
 */
int seeBack()
{
    /* The back element cannot be viewed when the deque is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return queue[back];
}


/*
 * Function : print_queue
 * Purpose  : Displays all elements from front to back in circular order.
 */
void print_queue()
{
    /* Check whether there are any elements available to display. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Displaying the current queue:\n");

    /* i represents the current array position while traversing the circular queue. */
    int i = front;

    /* Continue printing until the current position reaches the back. */
    while (1)
    {
        printf("%d\t", queue[i]);

        /* Stop once the last element of the deque has been displayed. */
        if (i == back)
            break;

        /* Wrap around to the first array position after reaching the last position. */
        if (i == MAX - 1)
            i = 0;

        /* Otherwise, move to the next array position. */
        else
            i++;
    }

    printf("\n");
}


/*
 * Function : isEmpty
 * Purpose  : Checks whether the deque contains no elements.
 */
int isEmpty()
{
    /* Both front and back are -1 when the deque contains no elements. */
    if (front == -1 && back == -1)
        return 1;

    return 0;
}


/*
 * Function : isFull
 * Purpose  : Checks whether the circular array has no free position.
 */
int isFull()
{
    /* The deque is full when back is immediately before front in circular order. */
    if ((front == 0 && back == MAX - 1) || (back + 1 == front))
        return 1;

    return 0;
}
    /* Return -1 when the search element does not exist in the array. */
    return -1;
}
```
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
 	
 


    /* Return -1 when the search element does not exist in the array. */
    return -1;
}
```
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
 	
