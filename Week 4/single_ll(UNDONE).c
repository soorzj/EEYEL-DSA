/***************************************************************
* Program to implement single linked list in C using struct    *
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
void insertFront(int val);              //fucntion that checks if LL is empty and inserts element at first position
void insertBack(int val);               //fucntion that checks if LL is empty and inserts element at last position
void insertAtPosition(int pos, int val);//fucntion that checks if LL is empty and inserts element at a given position
void deleteFirst(void);                 //fucntion that checks if LL is empty and delets element at first position
void deleteLast(void);                  //fucntion that checks if LL is empty and delets element at last position
void deleteAtPosition(int pos);         //fucntion that checks if LL is empty and delets element at a given position
void displayList(void);                 //fucntion that checks if LL is empty and prints elements in order

int main() {
    int choice=-1, val, pos;
    while (choice!=8) {
        printf("Menu for Single LinkedList\n");
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
    newNode->next = head;
    head = newNode;
}

void insertBack(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(int pos, int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *current = head;
    for (int i = 1; i < pos-1; i++) {
        if (current->next == NULL)
            break; //given position out of range, we just insert at last position
        current = current->next;
    }
    newNode->data = val;
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *first = head;
    head = head->next;
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
    struct node *secondLast = head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }
    struct node *last=secondLast->next;
    free(last);
    secondLast->next = NULL;
    printf("Last element deleted\n");
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;
    for (int i = 1; i < pos-1; i++) {
        current = current->next;
        if (current == NULL) {
            printf("Position out of range\n");
            return;
        }
    }
    
    struct node *toDelete = current->next;
    current->next = toDelete->next;
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
}
