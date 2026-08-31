
/****************************************************************
 * Program : Singly Linked List Implementation Using Structure
 * Version : 3
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program implements a singly linked list using a
 * structure and dynamic memory allocation. Each node stores
 * an integer value and a pointer to the next node.
 *
 * Operations:
 * 1. Add Element at Front       - Insert an element at the beginning
 * 2. Add Element at Back        - Insert an element at the end
 * 3. Insert Element at Position - Insert an element at a given position
 * 4. Delete First Element       - Remove the first element
 * 5. Delete Last Element        - Remove the last element
 * 6. Delete Element at Position - Remove an element at a given position
 * 7. Display Linked List        - Display all elements in order
 * 8. Search and Update          - Find and replace an element
 * 9. Exit                       - Terminate the program
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>


// Node structure stores the data and the address of the next node.
struct node
{
    int data;
    struct node *next;
};


// head points to the first node of the linked list.
struct node *head = NULL;


// Function prototypes for linked list operations.
void insertFront(int value);                   // Inserts an element at the beginning of the list.
void insertBack(int value);                    // Inserts an element at the end of the list.
void insertAtPosition(int position, int value);// Inserts an element at the specified position.
void deleteFirst(void);                        // Deletes the first element of the list.
void deleteLast(void);                         // Deletes the last element of the list.
void deleteAtPosition(int position);           // Deletes the element at the specified position.
void displayList(void);                        // Displays all elements of the linked list.
void updateElement(int oldValue, int newValue);// Searches for and replaces an element.
void clearList(void);                          // Frees all nodes before program termination.


int main()
{
    // choice stores the menu option selected by the user.
    int choice = -1;

    // value stores an element entered by the user.
    int value;

    // position stores the position specified for insertion or deletion.
    int position;

    // Display the menu repeatedly until the user chooses Exit.
    while (choice != 9)
    {
        printf("Menu for Single LinkedList\n");
        printf("1.Add Element at front\n2.Add Element at back\n3.Insert Element at position\n4.Delete First Element\n5.Delete Last Element\n6.Delete Element at position\n7.Display Linked List\n8.Search and update\n9.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Read the value and insert it at the beginning of the list.
            printf("Enter The element:\n");
            scanf("%d", &value);
            insertFront(value);
            break;

        case 2:
            // Read the value and insert it at the end of the list.
            printf("Enter The element:\n");
            scanf("%d", &value);
            insertBack(value);
            break;

        case 3:
            // Read the value and position required for insertion.
            printf("Enter The element:\n");
            scanf("%d", &value);

            printf("Enter The position:\n");
            scanf("%d", &position);

            // Positions start from 1, so zero and negative positions are invalid.
            if (position < 1)
            {
                printf("Invalid position\n");
                break;
            }

            // Position 1 represents insertion at the beginning of the list.
            if (position == 1)
                insertFront(value);
            else
                insertAtPosition(position, value);

            break;

        case 4:
            // Delete the first node from the linked list.
            deleteFirst();
            break;

        case 5:
            // Delete the last node from the linked list.
            deleteLast();
            break;

        case 6:
            // Read the position of the element that needs to be deleted.
            printf("Enter The position:\n");
            scanf("%d", &position);

            // Positions smaller than 1 are not valid linked list positions.
            if (position < 1)
            {
                printf("Invalid position\n");
                break;
            }

            // Position 1 represents the first node of the list.
            if (position == 1)
                deleteFirst();
            else
                deleteAtPosition(position);

            break;

        case 7:
            // Display all elements currently present in the linked list.
            displayList();
            break;

        case 8:
        {
            // oldValue stores the value to be searched and newValue stores its replacement.
            int oldValue, newValue;

            printf("Enter The element to be replaced:\n");
            scanf("%d", &oldValue);

            printf("Enter The new element:\n");
            scanf("%d", &newValue);

            // Search for the old value and replace it with the new value.
            updateElement(oldValue, newValue);
            break;
        }

        case 9:
            // Free all dynamically allocated nodes before terminating the program.
            clearList();

            printf("Exiting Program\n");
            break;

        default:
            // Handle any menu option that is not available.
            printf("Wrong choice\n");
            break;
        }
    }

    return 0;
}


// Create a new node and insert it at the beginning of the list.
void insertFront(int value)
{
    // Allocate memory for the new node.
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Store the supplied value in the new node.
    newNode->data = value;

    // Connect the new node to the current first node.
    newNode->next = head;

    // Make the new node the first node of the list.
    head = newNode;

    printf("Element inserted at front\n");
}


// Create a new node and insert it at the end of the list.
void insertBack(int value)
{
    // Allocate memory for the new node.
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Store the supplied value and mark the new node as the last node.
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, the new node becomes the first node.
    if (head == NULL)
    {
        head = newNode;
        printf("Element inserted at back\n");
        return;
    }

    // current is used to traverse the list until the last node is reached.
    struct node *current = head;

    // Continue moving through the list while another node exists.
    while (current->next != NULL)
        current = current->next;

    // Link the last existing node to the new node.
    current->next = newNode;

    printf("Element inserted at back\n");
}


// Insert a new node at the specified position in the list.
void insertAtPosition(int position, int value)
{
    // current is used to reach the node immediately before the insertion position.
    struct node *current = head;

    // Move current to the node before the required position.
    for (int i = 1; i < position - 1; i++)
    {
        // Stop if the requested position is beyond the end of the list.
        if (current == NULL || current->next == NULL)
        {
            printf("Position out of range\n");
            return;
        }

        current = current->next;
    }

    // Allocate memory for the new node only after confirming that the position is valid.
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    // Store the value and connect the new node to the following node.
    newNode->data = value;
    newNode->next = current->next;

    // Connect the previous node to the newly inserted node.
    current->next = newNode;

    printf("Element inserted at position %d\n", position);
}


// Delete the first node of the linked list.
void deleteFirst(void)
{
    // The operation cannot be performed when the list is empty.
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Store the first node temporarily so its memory can be released.
    struct node *removedNode = head;

    // Move head to the second node in the list.
    head = head->next;

    // Release the memory occupied by the removed node.
    free(removedNode);

    printf("First element deleted\n");
}


// Delete the last node of the linked list.
void deleteLast(void)
{
    // The operation cannot be performed when the list is empty.
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Handle the special case where the list contains only one node.
    if (head->next == NULL)
    {
        free(head);
        head = NULL;

        printf("Last element deleted\n");
        return;
    }

    // current is used to reach the second-last node.
    struct node *current = head;

    // Stop when current points to the node immediately before the last node.
    while (current->next->next != NULL)
        current = current->next;

    // Store the last node before disconnecting and deleting it.
    struct node *removedNode = current->next;

    // The second-last node becomes the new last node.
    current->next = NULL;

    // Release the memory occupied by the old last node.
    free(removedNode);

    printf("Last element deleted\n");
}


// Delete the node present at the specified position.
void deleteAtPosition(int position)
{
    // The operation cannot be performed when the list is empty.
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // current is used to reach the node immediately before the target node.
    struct node *current = head;

    // Move current to the node before the requested position.
    for (int i = 1; i < position - 1; i++)
    {
        // Stop if the requested position does not exist.
        if (current->next == NULL)
        {
            printf("Position out of range\n");
            return;
        }

        current = current->next;
    }

    // Check whether the target node actually exists.
    if (current->next == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    // Store the node that needs to be removed.
    struct node *removedNode = current->next;

    // Connect the previous node directly to the node after the removed node.
    current->next = removedNode->next;

    // Release the memory occupied by the removed node.
    free(removedNode);

    printf("Element at position %d deleted\n", position);
}


// Display all elements of the linked list from beginning to end.
void displayList(void)
{
    // There are no elements to display when the list is empty.
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Displaying the linked list:\n");

    // current is used to traverse the list from the first node to the last node.
    struct node *current = head;

    // Continue traversing until the end of the linked list is reached.
    while (current != NULL)
    {
        printf("%d\t", current->data);

        // Move current to the next node.
        current = current->next;
    }

    printf("\n");
}


// Search for the first occurrence of an old value and replace it with a new value.
void updateElement(int oldValue, int newValue)
{
    // An update cannot be performed when the list is empty.
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // current is used to traverse the list while searching for the old value.
    struct node *current = head;

    // Continue searching until the value is found or the end of the list is reached.
    while (current != NULL)
    {
        // Replace the first node containing the requested old value.
        if (current->data == oldValue)
        {
            current->data = newValue;
            printf("Element updated successfully\n");
            return;
        }

        // Move to the next node.
        current = current->next;
    }

    // Report that the requested value does not exist in the list.
    printf("Element %d not found in the list\n", oldValue);
}


// Release all dynamically allocated nodes before program termination.
void clearList(void)
{
    // current points to the node currently being removed.
    struct node *current = head;

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

    // Reset head after all nodes have been released.
    head = NULL;
}
