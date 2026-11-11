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
void peek(void);                       // views element at first position without dequeuing
void displayQueue(void);               // prints elements in order

int main() {
    int choice = -1, val;
    while (choice != 5) {
        printf("\nMenu for Queue\n");
        printf("1. Enqueue \n2. Dequeue \n3. Peek \n4. Display Queue\n5. Exit\n");
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
    if (head == NULL)
    	return 1;
    else
    	return 0;
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
        printf("Queue is empty\n");
        return;
    }
    struct node *first = head;
    printf("Front element dequeued: %d\n",first->data);
    head = head->next;
    free(first);
    
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
