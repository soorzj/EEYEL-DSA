/***************************************************************
* Program to implement Stack ADT using Single Linked List in C *
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

struct node *top = NULL;

// function prototypes
void push(int val);                     // inserts element at top of the stack
void pop(void);                         // deletes element from top of the stack
void displayStack(void);                // prints elements in stack order
void peek()								// displays the element at the top of the stack(
int isEmpty()							// checks if the stack is empty (if top=NULL)

int main() {
    int choice = -1, val;
    while (choice != 5) {
        printf("\nMenu for Stack ADT\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display the Stack\n5. Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter The element:\n");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                displayStack();
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

void push(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *first = top;
    printf("Top element popped:%d\n",temp->data);
    top = top->next;
    free(first);
    
}

void peek() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = top;
    printf("Top element peeked: %d\n",temp->data);
}

void displayStack(void) {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return;
    }
    struct node *current = top;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

int isEmpty(){
	if (top == NULL) 
        return 1;
    else
    	return 0;
}
