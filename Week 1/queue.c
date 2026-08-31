/************************************************
 * Program : Queue Implementation Using Array
 * Version : 3
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program implements a linear queue using an
 * array. The queue follows the FIFO principle
 * (First In, First Out).
 *
 * Operations:
 * 1. Enqueue       - Insert an element into the queue
 * 2. Dequeue       - Remove an element from the queue
 * 3. See Front     - Display the first element
 * 4. Print Queue   - Display all queue elements
 * 5. Exit          - Terminate the program
 ************************************************/

#include <stdio.h>

#define MAX 10

int queue[MAX];             // Array used to store queue elements
int front = -1;             // Index of the first element
int rear = -1;              // Index of the last element


// Adds a value to the rear of the queue
void enqueue(int value);

// Removes and returns the front element of the queue
int dequeue(void);

// Returns the front element without removing it
int seeFront(void);

// Displays all elements from front to rear
void printQueue(void);

// Returns 1 if the queue is empty, otherwise returns 0
int isEmpty(void);

// Returns 1 if the queue is full, otherwise returns 0
int isFull(void);


int main(void)
{
    int choice = 0;         // Stores the user's menu choice

    printf("=================================\n");
    printf("       QUEUE USING ARRAY\n");
    printf("=================================\n");

    // Continue displaying the menu until the user chooses 5
    while (choice != 5)
    {
        printf("\n------------- MENU -------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. See Front Element\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("--------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int value;  // Value to be inserted

                printf("Enter element to enqueue: ");
                scanf("%d", &value);

                enqueue(value);
                break;
            }

            case 2:
            {
                int value;  // Stores the dequeued element

                value = dequeue();

                // -1 indicates that the queue was empty
                if (value != -1)
                {
                    printf("Element dequeued: %d\n", value);
                }

                break;
            }

            case 3:
            {
                int value;  // Stores the front element

                value = seeFront();

                // -1 indicates that the queue was empty
                if (value != -1)
                {
                    printf("Front element: %d\n", value);
                }

                break;
            }

            case 4:
                printQueue();
                break;

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please enter 1-5.\n");
        }
    }

    return 0;
}


// Parameter: value - element to be inserted into the queue
// Action: Checks for a full queue and inserts value at rear
void enqueue(int value)
{
    // Check whether the queue is full
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    // Set front and rear to 0 when inserting the first element
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        // Move rear to the next position
        rear++;
    }

    // Insert the value at the rear
    queue[rear] = value;

    printf("%d enqueued successfully.\n", value);
}


// Parameters: None
// Action: Removes and returns the element at front
int dequeue(void)
{
    int value;  // Stores the element being removed

    // Check whether the queue is empty
    if (isEmpty())
    {
        printf("Queue is empty. Nothing to dequeue.\n");
        return -1;
    }

    // Store the front element before removing it
    value = queue[front];

    // Move front to the next element
    front++;

    // Reset the queue when the last element is removed
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }

    return value;
}


// Parameters: None
// Action: Returns the front element without removing it
int seeFront(void)
{
    // Check whether the queue is empty
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }

    // Return the element at front
    return queue[front];
}


// Parameters: None
// Action: Displays all queue elements from front to rear
void printQueue(void)
{
    int i;  // Loop variable for traversing the queue

    // Check whether the queue is empty
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    // Traverse the queue from front to rear
    for (i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);

        // Print separator between elements
        if (i < rear)
        {
            printf(" <- ");
        }
    }

    printf("\n");
}


// Parameters: None
// Action: Checks whether the queue contains no elements
// Return: 1 if empty, 0 otherwise
int isEmpty(void)
{
    return (front == -1 && rear == -1);
}


// Parameters: None
// Action: Checks whether rear has reached the last array position
// Return: 1 if full, 0 otherwise
int isFull(void)
{
    return (rear == MAX - 1);
}
