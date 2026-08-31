
/****************************************************************
 * Program : Queue ADT Implementation Using Singly Linked List
 * Version : 3
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program implements the Queue ADT using a singly linked
 * list. The queue follows the FIFO principle (First In,
 * First Out), where elements are inserted at the rear and
 * removed from the front.
 *
 * Operations:
 * 1. Enqueue       - Insert an element at the rear of the queue
 * 2. Dequeue       - Remove an element from the front
 * 3. Peek          - Display the front element without removing it
 * 4. Display Queue - Display all elements from front to rear
 * 5. Exit          - Terminate the program
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>


// Node structure used to store a queue element and the address of the next node.
struct node
{
    int data;
    struct node *next;
};


// front points to the first node of the queue.
struct node *front = NULL;


// Function prototypes for queue operations.
int isEmpty(void);                  // Checks whether the queue contains any elements.
void enqueue(int value);            // Inserts an element at the rear of the queue.
void dequeue(void);                 // Removes an element from the front of the queue.
void peek(void);                    // Displays the front element without removing it.
void displayQueue(void);            // Displays all elements from front to rear.
void clearQueue(void);              // Frees all dynamically allocated nodes before termination.


int main()
{
    // choice stores the menu option selected by the user.
    int choice = -1;

    // value temporarily stores the element entered for insertion.
    int value;

    // Display the menu repeatedly until the user selects Exit.
    while (choice != 5)
    {
        printf("\nMenu for Queue\n");
        printf("1. Enqueue \n2. Dequeue \n3. Peek \n4. Display Queue\n5. Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Read the element that needs to be inserted into the queue.
            printf("Enter The element:\n");
            scanf("%d", &value);

            // Insert the entered element at the rear of the queue.
            enqueue(value);
            break;

        case 2:
            // Remove the element currently present at the front of the queue.
            dequeue();
            break;

        case 3:
            // Display the front element without modifying the queue.
            peek();
            break;

        case 4:
            // Display all elements currently present in the queue.
            displayQueue();
            break;

        case 5:
            // Release all dynamically allocated nodes before terminating the program.
            clearQueue();
            //Entire thing vibe coded by soorzj
            printf("Exiting Program\n");
            break;

        default:
            // Handle a menu option that is not available.
            printf("Wrong choice\n");
            break;
        }
    }

    return 0;
}


// Check whether the queue contains no nodes.
int isEmpty(void)
{
    // The queue is empty when front does not point to any node.
    if (front == NULL)
        return 1;

    return 0;
}


// Create a new node and insert it at the rear of the queue.
void enqueue(int value)
{
    // Allocate memory dynamically for the new queue node.
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Stop the operation if memory allocation fails.
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Store the supplied value in the new node.
    newNode->data = value;

    // The new node will be the last node, so its next pointer is NULL.
    newNode->next = NULL;

    // If the queue is empty, the new node becomes the first node.
    if (isEmpty())
    {
        front = newNode;
    }
    else
    {
        // current is used to traverse the list until the last node is reached.
        struct node *current = front;

        // Continue moving through the list while another node exists.
        while (current->next != NULL)
            current = current->next;

        // Link the last node to the newly created node.
        current->next = newNode;
    }

    printf("Element enqueued: %d\n", value);
}


// Remove the element currently present at the front of the queue.
void dequeue(void)
{
    // A dequeue operation cannot be performed when the queue is empty.
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    // Store the current front node so its memory can be released.
    struct node *removedNode = front;

    // Store the value before removing the node.
    int removedValue = removedNode->data;

    // Move front to the next node in the queue.
    front = front->next;

    // Release the memory occupied by the removed node.
    free(removedNode);

    printf("Front element dequeued: %d\n", removedValue);
}


// Display the element currently at the front without removing it.
void peek(void)
{
    // A peek operation cannot be performed when the queue is empty.
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    // front directly points to the first element of the queue.
    printf("Front element: %d\n", front->data);
}


// Display all queue elements from front to rear.
void displayQueue(void)
{
    // There are no elements to display when the queue is empty.
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Displaying the queue:\n");

    // current is used to traverse the linked list from front to rear.
    struct node *current = front;

    // Continue traversing until the end of the linked list is reached.
    while (current != NULL)
    {
        printf("%d\t", current->data);

        // Move current to the next node.
        current = current->next;
    }

    printf("\n");
}


// Release all dynamically allocated nodes before the program terminates.
void clearQueue(void)
{
    // current points to the node currently being removed.
    struct node *current = front;

    // Continue until every node has been visited and released.
    while (current != NULL)
    {
        // Store the next node before freeing the current node.
        struct node *nextNode = current->next;

        // Release the memory occupied by the current node.
        free(current);

        // Move to the next node.
        current = nextNode;
    }

    // Reset front after all nodes have been released.
    front = NULL;
}
