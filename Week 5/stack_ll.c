
/****************************************************************
 * Program : Stack ADT Implementation Using Singly Linked List
 * Version : 3
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program implements the Stack ADT using a singly linked
 * list. The stack follows the LIFO principle (Last In, First
 * Out), where elements are inserted and removed from the top.
 *
 * Operations:
 * 1. Push          - Insert an element at the top of the stack
 * 2. Pop           - Remove the top element from the stack
 * 3. Peek          - Display the top element without removing it
 * 4. Display Stack - Display all elements from top to bottom
 * 5. Exit          - Terminate the program
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>


// Node structure stores the stack element and the address of the next node.
struct node
{
    int data;
    struct node *next;
};


// top points to the first node, which represents the top of the stack.
struct node *top = NULL;


// Function prototypes for stack operations.
void push(int value);          // Inserts an element at the top of the stack.
void pop(void);                // Removes the top element from the stack.
void peek(void);               // Displays the top element without removing it.
void displayStack(void);       // Displays all stack elements from top to bottom.
int isEmpty(void);             // Checks whether the stack is empty.
void clearStack(void);         // Frees all nodes before program termination.


int main()
{
    // choice stores the menu option selected by the user.
    int choice = -1;

    // value temporarily stores the element entered by the user.
    int value;

    // Display the menu repeatedly until the user chooses Exit.
    while (choice != 5)
    {
        printf("\nMenu for Stack\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display the Stack\n5. Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Read the value and insert it at the top of the stack.
            printf("Enter The element:\n");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            // Remove the element currently present at the top of the stack.
            pop();
            break;

        case 3:
            // Display the top element without modifying the stack.
            peek();
            break;

        case 4:
            // Display all elements currently present in the stack.
            displayStack();
            break;

        case 5:
            // Free all dynamically allocated nodes before terminating the program.
            clearStack();

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


// Create a new node and insert it at the top of the stack.
void push(int value)
{
    // Allocate memory for the new stack node.
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Store the supplied value in the new node.
    newNode->data = value;

    // Connect the new node to the current top node.
    newNode->next = top;

    // Make the new node the new top of the stack.
    top = newNode;

    printf("Element pushed: %d\n", value);
}


// Remove the element currently present at the top of the stack.
void pop(void)
{
    // A pop operation cannot be performed when the stack is empty.
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }

    // Store the top node temporarily so its memory can be released.
    struct node *removedNode = top;

    // Store the value before removing the node.
    int removedValue = removedNode->data;

    // Move top to the next node in the stack.
    top = top->next;

    // Release the memory occupied by the removed node.
    free(removedNode);

    printf("Top element popped: %d\n", removedValue);
}


// Display the element currently at the top without removing it.
void peek(void)
{
    // A peek operation cannot be performed when the stack is empty.
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }

    // top directly points to the element at the top of the stack.
    printf("Top element peeked: %d\n", top->data);
}


// Display all stack elements from top to bottom.
void displayStack(void)
{
    // There are no elements to display when the stack is empty.
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Displaying the stack:\n");

    // current is used to traverse the stack from top to bottom.
    struct node *current = top;

    // Continue traversing until the end of the linked list is reached.
    while (current != NULL)
    {
        printf("%d\t", current->data);

        // Move current to the next node in the stack.
        current = current->next;
    }

    printf("\n");
}


// Check whether the stack contains no elements.
int isEmpty(void)
{
    // The stack is empty when top does not point to any node.
    if (top == NULL)
        return 1;
    else
        return 0;
}


// Release all dynamically allocated nodes before the program terminates.
void clearStack(void)
{
    // current points to the node currently being removed.
    struct node *current = top;

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

    // Reset top after all nodes have been released.
    top = NULL;
}
