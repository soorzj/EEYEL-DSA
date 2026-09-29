/***************************************************************
* Program to implement Doubly Linked List in C using struct   *
*                                                             *
* Author  : SOORAJ                                            *
* Date    : 10-8-26                                           *
* Version : 2                                                 *
*                                                             *
* Description:                                                 *
* This program implements a Doubly Linked List using a         *
* structure containing data, next pointer and previous        *
* pointer. It provides operations for insertion, deletion,    *
* display and updating of elements through a menu-driven      *
* interface.                                                   *
*                                                             *
* Operations performed:                                        *
* 1. Insert an element at the front                            *
* 2. Insert an element at the back                             *
* 3. Insert an element at a specified position                *
* 4. Delete the first element                                  *
* 5. Delete the last element                                   *
* 6. Delete an element at a specified position                *
* 7. Display the linked list                                   *
* 8. Search and update an element                              *
* 9. Exit the program                                          *
*                                                             *
* Each node contains three fields:                             *
* data - stores the value of the node                          *
* next - points to the next node                               *
* prev - points to the previous node                           *
***************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

// Function prototypes
void insertFront(int val);
void insertBack(int val);
void insertAtPosition(int pos, int val);
void deleteFirst(void);
void deleteLast(void);
void deleteAtPosition(int pos);
void displayList(void);
void updateElement(int oldVal, int newVal);

int main(void)
{
    int choice = -1;
    int val, pos;
    int oldVal, newVal;

    while (choice != 9)
    {
        printf("Menu for Doubly Linked List\n");
        printf("1.Add Element at front\n");
        printf("2.Add Element at back\n");
        printf("3.Insert Element at position\n");
        printf("4.Delete First Element\n");
        printf("5.Delete Last Element\n");
        printf("6.Delete Element at position\n");
        printf("7.Display Linked List\n");
        printf("8.Search and update\n");
        printf("9.Exit\n");

        printf("Enter Your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter The element:\n");
                scanf("%d", &val);

                insertFront(val);
                break;

            case 2:
                printf("Enter The element:\n");
                scanf("%d", &val);

                insertBack(val);
                break;

            case 3:
                printf("Enter The element:\n");
                scanf("%d", &val);

                printf("Enter The position:\n");
                scanf("%d", &pos);

                // Check whether the position is valid
                if (pos < 1)
                {
                    printf("Invalid position\n");
                    break;
                }

                // Position 1 is handled by insertFront
                if (pos == 1)
                    insertFront(val);
                else
                    insertAtPosition(pos, val);

                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                printf("Enter The position:\n");
                scanf("%d", &pos);

                // Check whether the position is valid
                if (pos < 1)
                {
                    printf("Invalid position\n");
                    break;
                }

                // Position 1 is handled by deleteFirst
                if (pos == 1)
                    deleteFirst();
                else
                    deleteAtPosition(pos);

                break;

            case 7:
                displayList();
                break;

            case 8:
                printf("Enter The element to be replaced:\n");
                scanf("%d", &oldVal);

                printf("Enter The new element:\n");
                scanf("%d", &newVal);

                updateElement(oldVal, newVal);
                break;

            case 9:
                printf("Exiting Program\n");
                break;

            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}

void insertFront(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Store the value in the new node
    newNode->data = val;

    // Connect the new node to the current head
    newNode->next = head;
    newNode->prev = NULL;

    // Update the previous pointer of the old head
    if (head != NULL)
        head->prev = newNode;

    // Make the new node the head
    head = newNode;

    printf("Element inserted at front\n");
}

void insertBack(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Initialize the new node
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL)
    {
        head = newNode;
        printf("Element inserted at back\n");
        return;
    }

    struct node *current = head;

    // Traverse to the last node
    while (current->next != NULL)
        current = current->next;

    // Connect the new node to the last node
    current->next = newNode;
    newNode->prev = current;

    printf("Element inserted at back\n");
}

void insertAtPosition(int pos, int val)
{
    struct node *current = head;

    // Position 1 is handled by insertFront
    if (pos == 1)
    {
        insertFront(val);
        return;
    }

    // Move to the node before the required position
    for (int i = 1; i < pos - 1 && current != NULL; i++)
        current = current->next;

    // Insert at the end if position is beyond the list
    if (current == NULL)
    {
        insertBack(val);
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Store the value and connect the new node
    newNode->data = val;
    newNode->next = current->next;
    newNode->prev = current;

    // Update the previous pointer of the next node
    if (current->next != NULL)
        current->next->prev = newNode;

    // Connect the current node to the new node
    current->next = newNode;

    printf("Element inserted at position %d\n", pos);
}

void deleteFirst(void)
{
    // Check whether the list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *first = head;

    // Move the head to the next node
    head = head->next;

    // Remove the previous link of the new head
    if (head != NULL)
        head->prev = NULL;

    // Free the old first node
    free(first);

    printf("First element deleted\n");
}

void deleteLast(void)
{
    // Check whether the list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Handle the single-node case
    if (head->next == NULL)
    {
        free(head);
        head = NULL;

        printf("Last element deleted\n");
        return;
    }

    struct node *current = head;

    // Move to the second-last node
    while (current->next->next != NULL)
        current = current->next;

    struct node *last = current->next;

    // Remove the link to the last node
    current->next = NULL;

    // Free the last node
    free(last);

    printf("Last element deleted\n");
}

void deleteAtPosition(int pos)
{
    // Check whether the list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Position 1 is handled by deleteFirst
    if (pos == 1)
    {
        deleteFirst();
        return;
    }

    struct node *current = head;

    // Move to the node before the required position
    for (int i = 1; i < pos - 1 && current != NULL; i++)
        current = current->next;

    // Check whether the position exists
    if (current == NULL || current->next == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    struct node *toDelete = current->next;

    // Connect the previous node to the next node
    current->next = toDelete->next;

    // Update the previous pointer of the next node
    if (toDelete->next != NULL)
        toDelete->next->prev = current;

    // Free the node to be deleted
    free(toDelete);

    printf("Element at position %d deleted\n", pos);
}

void displayList(void)
{
    // Check whether the list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;

    // Traverse and display the list
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }

    printf("\n");
}

void updateElement(int oldVal, int newVal)
{
    // Check whether the list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;

    // Search for the first occurrence of oldVal
    while (current != NULL)
    {
        if (current->data == oldVal)
        {
            current->data = newVal;
            printf("Element updated successfully\n");
            return;
        }

        current = current->next;
    }

    // Display message if the element was not found
    printf("Element %d not found in the list\n", oldVal);
}
