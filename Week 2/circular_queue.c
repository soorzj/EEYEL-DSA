
/****************************************************
 * Program to implement circular queue as an array  *
 * Version: 2                                        *
 * Date: 31 - 8 - 26                                 *
 * Author: Sooraj                                     *
 ****************************************************/

#include <stdio.h>

#define MAX 10

/* Global array stores the elements of the circular queue. */
int queue[MAX];

/* Front points to the first element and back points to the last element. */
int front = -1, back = -1;


/* Function prototypes. */
void enqueue(int value);    // Checks whether the queue is full and inserts an element at the back.
int dequeue(void);          // Checks whether the queue is empty and removes the front element.
int seeFront(void);         // Checks whether the queue is empty and returns the front element.
void print_queue(void);     // Checks whether the queue is empty and displays all queue elements.
int isEmpty(void);          // Checks whether both front and back are -1.
int isFull(void);           // Checks whether the next position of back would overlap front.


int main()
{
    /* Menu-driven main function used to perform different queue operations. */
    int choice = -1;

    printf("Menu for Queue\n");
    printf("1.Enqueue\n2.Dequeue\n3.See First Memeber\n4.See the queue\n5.Exit\n");

    /* The menu continues to appear until the user chooses the Exit option. */
    while (choice != 5)
    {
        printf("Enter Your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            /* Read an element from the user and insert it at the back of the queue. */
            int value;

            printf("Enter element to be queued:\n");
            scanf("%d", &value);

            enqueue(value);

            printf("Current queue:\n");
            print_queue();

            break;
        }

        case 2:
        {
            /* Remove the element at the front and display it if the queue is not empty. */
            int dequeuedElement = dequeue();

            if (dequeuedElement != -1)
                printf("Element dequeued: %d\n", dequeuedElement);

            printf("Current queue:\n");
            print_queue();

            break;
        }

        case 3:
        {
            /* Display the front element without removing it from the queue. */
            int frontElement = seeFront();

            if (frontElement != -1)
                printf("Topmost Element of queue: %d\n", frontElement);

            break;
        }

        case 4:
            /* Display every element currently present in the circular queue. */
            printf("Displaying the queue:\n");
            print_queue();
            break;

        case 5:
            /* End the program when the user selects the Exit option. */
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
 * Function: enqueue
 * Purpose: Inserts a new element at the back of the circular queue.
 */
void enqueue(int value)
{
    /* An element cannot be inserted when the circular queue is full. */
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    /* For an empty queue, both front and back start at the first array position. */
    if (isEmpty())
    {
        front = 0;
        back = 0;
    }

    /* If back reaches the last position, move it back to the first position. */
    else if (back == MAX - 1)
    {
        back = 0;
    }

    /* Otherwise, move back normally to the next array position. */
    else
    {
        back++;
    }

    /* Store the new element at the updated back position. */
    queue[back] = value;

    printf("Queued\n");
}


/*
 * Function: dequeue
 * Purpose: Removes and returns the element at the front of the queue.
 */
int dequeue()
{
    int dequeuedElement;

    /* An element cannot be removed when the circular queue is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    /* Store the front element before moving the front pointer. */
    dequeuedElement = queue[front];

    /* If front and back are equal, the removed element was the last element. */
    if (front == back)
    {
        front = -1;
        back = -1;
    }

    /* If front reaches the last array position, wrap it around to position zero. */
    else if (front == MAX - 1)
    {
        front = 0;
    }

    /* Otherwise, move front normally to the next array position. */
    else
    {
        front++;
    }

    return dequeuedElement;
}


/*
 * Function: seeFront
 * Purpose: Returns the front element without removing it from the queue.
 */
int seeFront()
{
    /* The front element cannot be viewed when the queue is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    /* Return the element currently pointed to by front. */
    return queue[front];
}


/*
 * Function: print_queue
 * Purpose: Displays all elements from front to back in circular order.
 */
void print_queue()
{
    int i;

    /* There are no elements to display when the queue is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    /* Start displaying from the current front position. */
    i = front;

    /* Continue until the current position reaches the back of the queue. */
    while (1)
    {
        printf("%d\t", queue[i]);

        /* Stop once the last element of the queue has been displayed. */
        if (i == back)
            break;

        /* Wrap around to position zero after reaching the last array position. */
        if (i == MAX - 1)
            i = 0;

        /* Otherwise, move to the next array position normally. */
        else
            i++;
    }

    printf("\n");
}


/*
 * Function: isEmpty
 * Purpose: Checks whether the circular queue contains no elements.
 */
int isEmpty()
{
    /* Both pointers remain -1 when the queue has no elements. */
    if (front == -1 && back == -1)
        return 1;

    return 0;
}


/*
 * Function: isFull
 * Purpose: Checks whether the next position of back is occupied by front.
 */
int isFull()
{
    /* The queue is full when back reaches the last position while front is zero. */
    if ((front == 0 && back == MAX - 1) || (back + 1 == front))
        return 1;

    return 0;
}


