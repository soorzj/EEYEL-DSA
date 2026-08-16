/***************************************************************
* Program to implement doubly linked list in C using struct    *
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
void insertFront(int val);              // function that checks if LL is empty and inserts element at first position
void insertBack(int val);               // function that checks if LL is empty and inserts element at last position
void insertAtPosition(int pos, int val);// function that checks if LL is empty and inserts element at a given position
void deleteFirst(void);                 // function that checks if LL is empty and deletes element at first position
void deleteLast(void);                  // function that checks if LL is empty and deletes element at last position
void deleteAtPosition(int pos);         // function that checks if LL is empty and deletes element at a given position
void displayList(void);                 // function that checks if LL is empty and prints elements in order

int main() {
    int choice=-1, val, pos;
    while (choice!=8) {
        printf("Menu for Doubly Linked List (without tail pointer)\n");
        printf("1.Add Element at front\n2.Add Element at back\n3.Insert Element at position\n4.Delete First Element\n5.Delete Last Element\n6.Delete Element at position\n7.Display Linked List\n8.Exit\n");
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
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) 
        head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
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
    
    struct node *last = head;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void insertAtPosition(int pos, int val) {
    if (head == NULL) {
        insertFront(val);
        return;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    struct node *current = head;
    int i = 1;
    while (i < pos-1 && current->next != NULL) {
        current = current->next;
        i++;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *toDelete = head;
    if (head->next == NULL) // only one node
        head = NULL;
    else {
        head = head->next;
        head->prev = NULL;
    }
    free(toDelete);
    printf("First element deleted\n");
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (head->next == NULL) { // only one node
        free(head);
        head = NULL;
        printf("Last element deleted\n");
        return;
    }
    
    struct node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    struct node *toDelete = current->next;
    current->next = NULL;
    free(toDelete);
    printf("Last element deleted\n");
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;
    int i = 1;
    while (i < pos && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    current->prev->next = current->next;
    if (current->next != NULL) 
        current->next->prev = current->prev;
    free(current);
    printf("Element at position %d deleted\n", pos);
}

void displayList(void) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *current = head;
    while (current != NULL) {
        printf("%d \t", current->data);
        current = current->next;
    }
    printf("\n");
}
