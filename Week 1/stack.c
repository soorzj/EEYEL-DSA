/************************************************
 * Program : Stack Implementation Using Array
 * Author  : SOORAJ
 * Date    : 06-07-2026
 * Version : 3
 *
 * Description:
 * This program implements a stack using an array.
 * The stack follows the LIFO principle
 * (Last In, First Out).
 *
 * Operations:
 * 1. Push  - Insert an element into the stack
 * 2. Pop   - Remove the top element
 * 3. Peek  - View the top element
 * 4. See all - Display all stack elements
 * 5. Exit  - Terminate the program
 ************************************************/

#include <stdio.h>

#define MAX 10

int stack[MAX];             // Array used to store stack elements
int top = -1;               // Index of the top element


// Parameter: value - element to be inserted
// Action: Checks for overflow and pushes value onto the stack
void push(int value);

// Parameters: None
// Action: Removes and returns the top element
int pop(void);

// Parameters: None
// Action: Returns the top element without removing it
int peek(void);

// Parameters: None
// Action: Displays all elements from top to bottom
void printStack(void);

// Parameters: None
// Action: Checks whether the stack is empty
// Return: 1 if empty, 0 otherwise
int isEmpty(void);


int main(void)
{
    int choice = -1;        // Stores the user's menu choice

    while (choice != 5)
    {
        // Original menu display
        printf("Menu for stack\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.See all\n5.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int value;  // Value to be pushed

                printf("Enter element to push to stack:\n");
                scanf("%d", &value);

                push(value);
                break;
            }

            case 2:
            {
                int popped; // Stores the popped element

                popped = pop();

                // -1 indicates that the stack was empty
                if (popped != -1)
                {
                    printf("Element Popped: %d\n", popped);
                }

                break;
            }

            case 3:
            {
                int topmost; // Stores the top element

                topmost = peek();

                // -1 indicates that the stack was empty
                if (topmost != -1)
                {
                    printf("Topmost Element peeked: %d\n", topmost);
                }

                break;
            }

            case 4:
                printf("Displaying the stack:\n");
                printStack();
                break;

            case 5:
                printf("Exiting the Program\n");
                break;

            default:
                printf("Wrong Choice\n");
                break;
        }
    }

    return 0;
}


// Parameter: value - element to be pushed onto the stack
// Action: Adds value at the top of the stack
void push(int value)
{
    // Check whether the stack is full
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    // Move top to the next position
    top++;

    // Store the value at the top
    stack[top] = value;
}


// Parameters: None
// Action: Removes and returns the top element
int pop(void)
{
    // Check whether the stack is empty
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }

    // Return the top element and move top down
    return stack[top--];
}


// Parameters: None
// Action: Returns the top element without removing it
int peek(void)
{
    // Check whether the stack is empty
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }

    // Return the element at the top
    return stack[top];
}


// Parameters: None
// Action: Displays stack elements from top to bottom
void printStack(void)
{
    int i;  // Loop variable for traversing the stack

    // Check whether the stack is empty
    if (isEmpty())
    {
        printf("Stack Empty\n");
        return;
    }

    // Print elements starting from the top
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}


// Parameters: None
// Action: Checks whether the stack contains no elements
// Return: 1 if empty, 0 otherwise
int isEmpty(void)
{
    return (top == -1);
}
