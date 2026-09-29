
/****************************************************************
* Program to implement circular linked list using tail pointer *
*                                                              *
* Author  : SOORAJ                                             *
* Date    : 10-8-26                                            *
* Version : 2                                                  *
*                                                              *
* Description:                                                  *
* This program implements a circular linked list using a tail  *
* pointer. The last node points back to the first node, and the *
* tail pointer is used to access both the first and last nodes. *
*                                                              *
* The program performs the following operations:               *
* 1. Insert an element at the front                            *
* 2. Insert an element at the back                             *
* 3. Insert an element at a given position                     *
* 4. Delete the first element                                  *
* 5. Delete the last element                                   *
* 6. Delete an element at a given position                     *
* 7. Display the linked list                                   *
* 8. Search and update an element                               *
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *tail = NULL;

// Function prototypes
void insertFront(int val);
void insertBack(int val);
void insertAtPosition(int pos, int val);
void deleteFirst(void);
void deleteLast(void);
void deleteAtPosition(int pos);
void displayList(void);
void updateElement(int oldVal, int newVal);

int main()
{
    int choice = -1, val, pos;

    while (choice != 9)
    {
        printf("\n========================================\n");
        printf("       CIRCULAR LINKED LIST MENU\n");
        printf("========================================\n");
        printf("  1. Add Element at Front\n");
        printf("  2. Add Element at Back\n");
        printf("  3. Insert Element at Position\n");
        printf("  4. Delete First Element\n");
        printf("  5. Delete Last Element\n");
        printf("  6. Delete Element at Position\n");
        printf("  7. Display Linked List\n");
        printf("  8. Search and Update\n");
        printf("  9. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &val);
                insertFront(val);
                break;

            case 2:
                printf("Enter the element: ");
                scanf("%d", &val);
                insertBack(val);
                break;

            case 3:
                printf("Enter the element: ");
                scanf("%d", &val);
                printf("Enter the position: ");
                scanf("%d", &pos);

                if (pos < 1)
                {
                    printf("Invalid position.\n");
                    break;
                }

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
                printf("Enter the position: ");
                scanf("%d", &pos);

                if (pos < 1)
                {
                    printf("Invalid position.\n");
                    break;
                }

                if (pos == 1)
                    deleteFirst();
                else
                    deleteAtPosition(pos);
                break;

            case 7:
                displayList();
                break;

            case 8:
            {
                int oldVal, newVal;

                printf("Enter the element to be replaced: ");
                scanf("%d", &oldVal);
                printf("Enter the new element: ");
                scanf("%d", &newVal);

                updateElement(oldVal, newVal);
                break;
            }

            case 9:
                printf("\nExiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void insertFront(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = val;

    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }

    printf("Element inserted at front successfully.\n");
}

void insertBack(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = val;

    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    printf("Element inserted at back successfully.\n");
}

void insertAtPosition(int pos, int val)
{
    if (pos == 1)
    {
        insertFront(val);
        return;
    }

    if (tail == NULL)
    {
        insertBack(val);
        return;
    }

    struct node *current = tail->next;

    // Traverse to the node before the required position
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;

        if (current == tail->next)
        {
            insertBack(val);
            return;
        }
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = val;
    newNode->next = current->next;
    current->next = newNode;

    if (current == tail)
        tail = newNode;

    printf("Element inserted at position %d successfully.\n", pos);
}

void deleteFirst(void)
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *head = tail->next;

    if (tail == head)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        tail->next = head->next;
        free(head);
    }

    printf("First element deleted successfully.\n");
}

void deleteLast(void)
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *head = tail->next;

    if (tail == head)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        struct node *current = head;

        while (current->next != tail)
            current = current->next;

        current->next = tail->next;
        free(tail);
        tail = current;
    }

    printf("Last element deleted successfully.\n");
}

void deleteAtPosition(int pos)
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1)
    {
        deleteFirst();
        return;
    }

    struct node *current = tail->next;

    // Traverse to the node before the required position
    for (int i = 1; i < pos - 1; i++)
    {
        if (current->next == tail->next)
        {
            printf("Position out of range.\n");
            return;
        }

        current = current->next;
    }

    struct node *toDelete = current->next;

    if (toDelete == tail->next && current != tail)
    {
        printf("Position out of range.\n");
        return;
    }

    current->next = toDelete->next;

    if (toDelete == tail)
        tail = current;

    free(toDelete);

    printf("Element at position %d deleted successfully.\n", pos);
}

void displayList(void)
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = tail->next;

    printf("\nCircular Linked List: ");

    do
    {
        printf("%d", current->data);
        current = current->next;

        if (current != tail->next)
            printf(" -> ");
    }
    while (current != tail->next);

    printf(" -> HEAD\n");
}

void updateElement(int oldVal, int newVal)
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = tail->next;

    do
    {
        if (current->data == oldVal)
        {
            current->data = newVal;
            printf("Element updated successfully.\n");
            return;
        }

        current = current->next;
    }
    while (current != tail->next);

    printf("Element %d not found in the list.\n", oldVal);
}

