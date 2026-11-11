/***************************************************************
* Program to implement double linked list in C using struct    *
* Author: SOORAJ                                               *
* Date: 10-8-26                                                *
* Version: 2                                                   *
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

// function prototypes
void insertFront(int val);              //function that checks if LL is empty and inserts element at first position
void insertBack(int val);               //function that checks if LL is empty and inserts element at last position
void insertAtPosition(int pos, int val);//function that checks if LL is empty and inserts element at a given position
void deleteFirst(void);                 //function that checks if LL is empty and deletes element at first position
void deleteLast(void);                  //function that checks if LL is empty and deletes element at last position
void deleteAtPosition(int pos);         //function that checks if LL is empty and deletes element at a given position
void displayList(void);                 //function that checks if LL is empty and prints elements in order
void updateElement(int old, int new);   //function that checks for a value 'old' and replaces it with value 'new'

int main() {
    int choice=-1, val, pos;
    while (choice!=9) {
        printf("Menu for Double LinkedList\n");
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
                int old,new;
                printf("Enter The element to be replaced:\n");
                scanf("%d", &old);
                printf("Enter The new element:\n");
                scanf("%d", &new);
                updateElement(old,new);
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
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertBack(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void insertAtPosition(int pos, int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (pos == 1) {
        insertFront(val);
        free(newNode); // Avoid memory leak since insertFront allocated its own node
        return;
    }
    struct node *current = head;
    for (int i = 1; i < pos-1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        // Position out of range, insert at the end
        insertBack(val);
        free(newNode);
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *first = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(first);
    printf("First element deleted\n");
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) { //only one element
        free(head);
        head = NULL;
        printf("Last element deleted\n");
        return;
    }
    struct node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    struct node *last = current->next;
    current->next = NULL;
    free(last);
    printf("Last element deleted\n");
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteFirst();
        return;
    }
    struct node *current = head;
    for (int i = 1; i < pos-1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct node *toDelete = current->next;
    current->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = current;
    }
    free(toDelete);
    printf("Element at position %d deleted\n", pos);
}

void displayList(void) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void updateElement(int oldVal, int newVal) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        if (current->data == oldVal) {
            current->data = newVal;
            printf("Element updated successfully\n");
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list\n", oldVal);
}
