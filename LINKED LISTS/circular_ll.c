/***************************************************************
* Program to implement circular linked list using tail pointer *
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

struct node *tail = NULL;

// function prototypes
void insertFront(int val);              //function that checks if LL is empty and inserts element at first position
void insertBack(int val);               //function that checks if LL is empty and inserts element at last position
void insertAtPosition(int pos, int val);//function that checks if LL is empty and inserts element at a given position
void deleteFirst(void);                 //function that checks if LL is empty and deletes element at first position
void deleteLast(void);                  //function that checks if LL is empty and deletes element at last position
void deleteAtPosition(int pos);         //function that checks if LL is empty and deletes element at a given position
void displayList(void);                 //function that checks if LL is empty and prints elements in order
void updateElement(int oldVal, int newVal); //function that checks for a value 'old' and replaces it with value 'new'

int main() {
    int choice=-1, val, pos;
    while (choice!=9) {
        printf("Menu for Circular LinkedList\n");
        printf("1.Add Element at front\n2.Add Element at back\n3.Insert Element at position\n4.Delete First Element\n5.Delete Last Element\n6.Delete Element at position\n7.Display Linked List\n8.Search and update\n9.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
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
                if (pos < 1) {
                    printf("Invalid position\n");
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
                printf("Enter The position:\n");
                scanf("%d", &pos);
                if (pos < 1) {
                    printf("Invalid position\n");
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
                int oldVal, newVal;
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

void insertFront(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insertBack(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(int pos, int val) {
    if (pos == 1) {
        insertFront(val);
        return;
    }
    if (tail == NULL) {
        // Position out of range for empty list beyond pos 1
        insertBack(val);
        return;
    }
    struct node *current = tail->next; // Start at head
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
        if (current == tail->next) { // Wrapped back to head before reaching pos-1
            insertBack(val);
            return;
        }
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = current->next;
    current->next = newNode;
    if (current == tail) {
        tail = newNode;
    }
}

void deleteFirst() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *head = tail->next;
    if (tail == head) { // Only one element
        free(tail);
        tail = NULL;
    } else {
        tail->next = head->next;
        free(head);
    }
    printf("First element deleted\n");
}

void deleteLast() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *head = tail->next;
    if (tail == head) { // Only one element
        free(tail);
        tail = NULL;
    } else {
        struct node *current = head;
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;
        free(tail);
        tail = current;
    }
    printf("Last element deleted\n");
}

void deleteAtPosition(int pos) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteFirst();
        return;
    }
    struct node *current = tail->next; // Start at head
    for (int i = 1; i < pos - 1; i++) {
        if (current->next == tail->next) { // Reached end before pos
            printf("Position out of range\n");
            return;
        }
        current = current->next;
    }
    struct node *toDelete = current->next;
    if (toDelete == tail->next && current != tail) {
        printf("Position out of range\n");
        return;
    }
    current->next = toDelete->next;
    if (toDelete == tail) {
        tail = current;
    }
    free(toDelete);
    printf("Element at position %d deleted\n", pos);
}

void displayList(void) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = tail->next; // Start at head
    do {
        printf("%d\t", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("\n");
}

void updateElement(int oldVal, int newVal) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = tail->next; // Start at head
    do {
        if (current->data == oldVal) {
            current->data = newVal;
            printf("Element updated successfully\n");
            return;
        }
        current = current->next;
    } while (current != tail->next);
    printf("Element %d not found in the list\n", oldVal);
}