/***************************************************************
* Program to implement Queue ADT using Single Linked List in C *
* Author: SOORAJ                                               *
* Date: 10-8-26                                                *
* Version: 2                                                   *
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// function prototypes
int isEmpty(void);                     // checks if queue is empty
void enqueue(int val);                 // inserts element at last position (back)
void dequeue(void);                    // deletes element at first position (front)
void peek(void);                       // views element at first position without removing
void displayQueue(void);               // prints elements in order

int main() {
    int choice = -1, val;
    while (choice != 5) {
        printf("\nMenu for Queue ADT\n");
        printf("1. Enqueue (Add Element at back)\n2. Dequeue (Delete Element from front)\n3. Peek (View Front Element)\n4. Display Queue\n5. Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter The element:\n");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("Exiting Program\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

int isEmpty() {
    return (head == NULL);
}

void enqueue(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (isEmpty()) {
        head = newNode;
        return;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow / Queue is empty\n");
        return;
    }
    struct node *first = head;
    head = head->next;
    free(first);
    printf("Front element dequeued\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", head->data);
}

void displayQueue(void) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}
