
/****************************************************************
* Program to implement circular queue as an array               *
*                                                              *
* Version : 2                                                  *
* Date    : 31-8-26                                            *
* Author  : SOORAJ                                             *
*                                                              *
* Description:                                                  *
* This program implements a circular queue using an array.     *
* It performs enqueue, dequeue, front element and display       *
* operations using circular indexing.                          *
****************************************************************/

#include <stdio.h>

#define MAX 10
int queue[MAX];

int front = -1, back = -1;

// Function prototypes
void enqueue(int value);
int dequeue(void);
int seeFront(void);
void print_queue(void);
int isEmpty(void);
int isFull(void);

int main()
{
    int choice = -1;

    while (choice != 5)
    {
        printf("\n========================================\n");
        printf("          CIRCULAR QUEUE MENU\n");
        printf("========================================\n");
        printf("  1. Enqueue\n");
        printf("  2. Dequeue\n");
        printf("  3. See Front Element\n");
        printf("  4. Display Queue\n");
        printf("  5. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int value;

                printf("Enter element to be queued: ");
                scanf("%d", &value);

                enqueue(value);

                printf("Current Queue: ");
                print_queue();
                break;
            }

            case 2:
            {
                int dequeuedElement = dequeue();

                if (dequeuedElement != -1)
                    printf("Element dequeued: %d\n", dequeuedElement);

                printf("Current Queue: ");
                print_queue();
                break;
            }

            case 3:
            {
                int frontElement = seeFront();

                if (frontElement != -1)
                    printf("Front Element: %d\n", frontElement);

                break;
            }

            case 4:
                printf("Current Queue: ");
                print_queue();
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full.\n");
        return;
    }

    // Set front and back for the first element
    if (isEmpty())
    {
        front = 0;
        back = 0;
    }
    // Wrap back around when it reaches the end
    else if (back == MAX - 1)
    {
        back = 0;
    }
    else
    {
        back++;
    }

    queue[back] = value;

    printf("Element queued successfully.\n");
}

int dequeue(void)
{
    int dequeuedElement;

    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }

    dequeuedElement = queue[front];

    // Reset the queue when the last element is removed
    if (front == back)
    {
        front = -1;
        back = -1;
    }
    // Wrap front around when it reaches the end
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    return dequeuedElement;
}

int seeFront(void)
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue[front];
}

void print_queue(void)
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    i = front;

    while (1)
    {
        printf("%d", queue[i]);

        if (i == back)
            break;

        printf(" -> ");

        // Wrap around to the beginning of the array
        if (i == MAX - 1)
            i = 0;
        else
            i++;
    }

    printf("\n");
}

int isEmpty(void)
{
    if (front == -1 && back == -1)
        return 1;

    return 0;
}

int isFull(void)
{
    if ((front == 0 && back == MAX - 1) || (back + 1 == front))
        return 1;

    return 0;
}
