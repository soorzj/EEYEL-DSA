
/****************************************************************
* Program to implement singly linked list in C using struct    *
*                                                              *
* Author  : SOORAJ                                             *
* Date    : 10-8-26                                            *
* Version : 2                                                  *
*                                                              *
* Description:                                                  *
* This program implements a singly linked list using structure *
* and performs insertion, deletion, display, update and        *
* sorting operations on the linked list.                       *
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
* 9. Sort the linked list using bubble sort                    *
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
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
void updateElement(int old, int new);
void bubbleSort(void);

int main()
{
    int choice = -1, val, pos;

    while (choice != 10)
    {
        printf("\n========================================\n");
        printf("          SINGLY LINKED LIST MENU\n");
        printf("========================================\n");
        printf("  1. Add Element at Front\n");
        printf("  2. Add Element at Back\n");
        printf("  3. Insert Element at Position\n");
        printf("  4. Delete First Element\n");
        printf("  5. Delete Last Element\n");
        printf("  6. Delete Element at Position\n");
        printf("  7. Display Linked List\n");
        printf("  8. Search and Update\n");
        printf("  9. Bubble Sort\n");
        printf(" 10. Exit\n");
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
                int old, newVal;

                printf("Enter the element to be replaced: ");
                scanf("%d", &old);
                printf("Enter the new element: ");
                scanf("%d", &newVal);

                updateElement(old, newVal);
                break;
            }

            case 9:
                bubbleSort();
                break;

            case 10:
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
    newNode->next = head;
    head = newNode;

    printf("Element inserted at front successfully.\n");
}

void insertBack(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        printf("Element inserted at back successfully.\n");
        return;
    }

    struct node *current = head;

    while (current->next != NULL)
        current = current->next;

    current->next = newNode;

    printf("Element inserted at back successfully.\n");
}

void insertAtPosition(int pos, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;

    for (int i = 1; i < pos - 1; i++)
    {
        if (current->next == NULL)
            break;

        current = current->next;
    }

    newNode->data = val;
    newNode->next = current->next;
    current->next = newNode;

    printf("Element inserted at position %d successfully.\n", pos);
}

void deleteFirst(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *first = head;

    head = head->next;
    free(first);

    printf("First element deleted successfully.\n");
}

void deleteLast(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last element deleted successfully.\n");
        return;
    }

    struct node *secondLast = head;

    while (secondLast->next->next != NULL)
        secondLast = secondLast->next;

    struct node *last = secondLast->next;

    free(last);
    secondLast->next = NULL;

    printf("Last element deleted successfully.\n");
}

void deleteAtPosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = head;

    for (int i = 1; i < pos - 1; i++)
    {
        if (current->next == NULL)
        {
            printf("Position out of range.\n");
            return;
        }

        current = current->next;
    }

    struct node *toDelete = current->next;

    current->next = toDelete->next;
    free(toDelete);

    printf("Element at position %d deleted successfully.\n", pos);
}

void displayList(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = head;

    printf("\nLinked List: ");

    while (current != NULL)
    {
        printf("%d", current->data);

        if (current->next != NULL)
            printf(" -> ");

        current = current->next;
    }

    printf(" -> NULL\n");
}

void updateElement(int old, int newVal)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = head;

    while (current != NULL)
    {
        if (current->data == old)
        {
            current->data = newVal;
            printf("Element updated successfully.\n");
            return;
        }

        current = current->next;
    }

    printf("Element %d not found in the list.\n", old);
}

void bubbleSort(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current;
    struct node *last = NULL;
    int swapped;
    int temp;

    do
    {
        swapped = 0;
        current = head;

        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }

            current = current->next;
        }

        last = current;

    } while (swapped);

    printf("List sorted successfully.\n");
}
