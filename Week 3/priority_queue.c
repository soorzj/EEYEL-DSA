
/********************************************************
 * Program : Priority Queue Implementation Using Array
 * Version : 4
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program implements a priority queue using a
 * two-dimensional array. Each element is stored along
 * with its priority, and elements can be accessed or
 * removed based on their priority.
 *
 * Operations:
 * 1. Enqueue         - Insert an element with its priority
 * 2. Dequeue Highest - Remove the element with highest priority
 * 3. Dequeue Lowest  - Remove the element with lowest priority
 * 4. See Highest     - Display the highest priority element
 * 5. See Lowest      - Display the lowest priority element
 * 6. Print Queue     - Display all elements with priorities
 * 7. Exit            - Terminate the program
 *******************************************************/

#include <stdio.h>

#define MAX 10

/* Each row stores one element: [0] stores the value and [1] stores its priority. */
int queue[MAX][2];

/* Front marks whether the queue contains elements and back stores the last used position. */
int front = -1, back = -1;


/* Function prototypes for all priority queue operations. */
void enqueue(int value, int priority);   // Inserts an element along with its priority.
int dequeueHighest(void);                // Removes and returns the highest priority element.
int dequeueLowest(void);                 // Removes and returns the lowest priority element.
int seeHighest(void);                    // Returns the highest priority element without removing it.
int seeLowest(void);                     // Returns the lowest priority element without removing it.
void print_queue(void);                  // Displays all active elements along with their priorities.
int isEmpty(void);                       // Checks whether the priority queue contains no elements.
int isFull(void);                        // Checks whether all array positions have been used.


int main()
{
    /* Mark every priority as -1 so that unused positions can be identified. */
    for (int i = 0; i < MAX; i++)
        queue[i][1] = -1;

    /* Menu-driven main function used to perform different priority queue operations. */
    int choice = -1;
    int value, priority, dequeued;

    printf("Menu for Queue\n");
    printf("1.Enqueue\n2.Dequeue Highest Priority\n3.Dequeue Lowest Priority\n4.See Highest Memeber\n5.See Lowest Memeber\n6.See the queue in order of \n7.Exit\n");

    /* Continue displaying the menu until the user chooses Exit. */
    while (choice != 7)
    {
        printf("Enter Your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            /* Read the element and its priority before inserting it into the queue. */
            printf("Enter element to be queued:\n");
            scanf("%d", &value);

            printf("Enter its priority:\n");
            scanf("%d", &priority);

            enqueue(value, priority);

            break;
        }

        case 2:
        {
            /* Remove and display the element having the highest priority. */
            dequeued = dequeueHighest();

            if (dequeued != -1)
                printf("Highest Priority Element dequeued: %d\n", dequeued);

            break;
        }

        case 3:
        {
            /* Remove and display the element having the lowest priority. */
            dequeued = dequeueLowest();

            if (dequeued != -1)
                printf("Lowest Priority Element dequeued: %d\n", dequeued);

            break;
        }

        case 4:
        {
            /* Display the highest priority element without removing it. */
            int highestPriorityElement = seeHighest();

            if (highestPriorityElement != -1)
                printf("Topmost priority Element of queue: %d\n", highestPriorityElement);

            break;
        }

        case 5:
        {
            /* Display the lowest priority element without removing it. */
            int lowestPriorityElement = seeLowest();

            if (lowestPriorityElement != -1)
                printf("Least Priority Element of queue: %d\n", lowestPriorityElement);

            break;
        }

        case 6:
            /* Display all currently active elements along with their priorities. */
            print_queue();
            break;

        case 7:
            /* Terminate the program when the user selects Exit. */
            printf("Exiting the Program\n");
			// Program done by sooraj
            break;

        default:
            /* Handle any menu option that is not available. */
            printf("Wrong Choice\n");
            break;
        }
    }

    return 0;
}


/*
 * Function : enqueue
 * Purpose  : Inserts an element and its priority into the priority queue.
 */
void enqueue(int value, int priority)
{
    /* Check whether there is an unused position before inserting the element. */
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    /* Find the first unused position in the array for storing the new element. */
    for (int i = 0; i < MAX; i++)
    {
        /* A priority of -1 indicates that this position is currently unused. */
        if (queue[i][1] == -1)
        {
            queue[i][0] = value;
            queue[i][1] = priority;

            /* Update back to the highest position that has been used. */
            if (i > back)
                back = i;

            /* Set front to the first valid position when inserting the first element. */
            if (front == -1)
                front = i;

            printf("Queued\n");
            return;
        }
    }

    printf("Queue is Full\n");
}


/*
 * Function : dequeueHighest
 * Purpose  : Removes and returns the element with the highest priority.
 */
int dequeueHighest()
{
    int highestPriorityPosition = -1;

    /* An element cannot be removed when the priority queue is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    /* i represents the current array position being checked for its priority. */
    for (int i = 0; i <= back; i++)
    {
        /* Ignore positions that have already been removed. */
        if (queue[i][1] != -1)
        {
            /* Store the position of the first valid element or a higher priority element. */
            if (highestPriorityPosition == -1 ||
                queue[i][1] > queue[highestPriorityPosition][1])
            {
                highestPriorityPosition = i;
            }
        }
    }

    /* Return an empty status if no active element was found. */
    if (highestPriorityPosition == -1)
    {
        printf("Queue is Empty\n");
        front = -1;
        back = -1;
        return -1;
    }

    /* Store the element before marking its position as unused. */
    int dequeuedElement = queue[highestPriorityPosition][0];

    queue[highestPriorityPosition][1] = -1;

    /* Reset the queue pointers when the removed element was the last active element. */
    if (isEmpty())
    {
        front = -1;
        back = -1;
    }

    return dequeuedElement;
}


/*
 * Function : dequeueLowest
 * Purpose  : Removes and returns the element with the lowest priority.
 */
int dequeueLowest()
{
    int lowestPriorityPosition = -1;

    /* An element cannot be removed when the priority queue is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    /* i represents the current array position being checked for its priority. */
    for (int i = 0; i <= back; i++)
    {
        /* Ignore positions that have already been removed. */
        if (queue[i][1] != -1)
        {
            /* Store the position of the first valid element or a lower priority element. */
            if (lowestPriorityPosition == -1 ||
                queue[i][1] < queue[lowestPriorityPosition][1])
            {
                lowestPriorityPosition = i;
            }
        }
    }

    /* Return an empty status if no active element was found. */
    if (lowestPriorityPosition == -1)
    {
        printf("Queue is Empty\n");
        front = -1;
        back = -1;
        return -1;
    }

    /* Store the element before marking its position as unused. */
    int dequeuedElement = queue[lowestPriorityPosition][0];

    queue[lowestPriorityPosition][1] = -1;

    /* Reset the queue pointers when the removed element was the last active element. */
    if (isEmpty())
    {
        front = -1;
        back = -1;
    }

    return dequeuedElement;
}


/*
 * Function : seeHighest
 * Purpose  : Returns the element with the highest priority without removing it.
 */
int seeHighest()
{
    int highestPriorityPosition = -1;

    /* The highest priority cannot be viewed when the queue is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    /* i represents the current array position being checked for its priority. */
    for (int i = 0; i <= back; i++)
    {
        /* Ignore positions that have already been removed. */
        if (queue[i][1] != -1)
        {
            /* Store the position of the first valid element or a higher priority element. */
            if (highestPriorityPosition == -1 ||
                queue[i][1] > queue[highestPriorityPosition][1])
            {
                highestPriorityPosition = i;
            }
        }
    }

    /* Return -1 if no active element exists in the queue. */
    if (highestPriorityPosition == -1)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return queue[highestPriorityPosition][0];
}


/*
 * Function : seeLowest
 * Purpose  : Returns the element with the lowest priority without removing it.
 */
int seeLowest()
{
    int lowestPriorityPosition = -1;

    /* The lowest priority cannot be viewed when the queue is empty. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    /* i represents the current array position being checked for its priority. */
    for (int i = 0; i <= back; i++)
    {
        /* Ignore positions that have already been removed. */
        if (queue[i][1] != -1)
        {
            /* Store the position of the first valid element or a lower priority element. */
            if (lowestPriorityPosition == -1 ||
                queue[i][1] < queue[lowestPriorityPosition][1])
            {
                lowestPriorityPosition = i;
            }
        }
    }

    /* Return -1 if no active element exists in the queue. */
    if (lowestPriorityPosition == -1)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return queue[lowestPriorityPosition][0];
}


/*
 * Function : print_queue
 * Purpose  : Displays all active elements and their priorities.
 */
void print_queue()
{
    /* Check whether there are any elements available to display. */
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Displaying the queue:\nElement\tPriority\n");

    /* i represents the current array position while checking active queue elements. */
    for (int i = 0; i <= back; i++)
    {
        /* Display only positions that have not been removed. */
        if (queue[i][1] != -1)
            printf("%d\t%d\n", queue[i][0], queue[i][1]);
    }
}


/*
 * Function : isEmpty
 * Purpose  : Checks whether the priority queue contains no active elements.
 */
int isEmpty()
{
    /* Check every used position for at least one active element. */
    for (int i = 0; i <= back; i++)
    {
        /* A priority other than -1 indicates an active queue element. */
        if (queue[i][1] != -1)
            return 0;
    }

    return 1;
}


/*
 * Function : isFull
 * Purpose  : Checks whether every position in the array is occupied.
 */
int isFull()
{
    /* back reaching MAX - 1 means all array positions have been used. */
    if (back == MAX - 1)
    {
        /* Search for an unused position in case an earlier element was removed. */
        for (int i = 0; i < MAX; i++)
        {
            if (queue[i][1] == -1)
                return 0;
        }

        return 1;
    }

    return 0;
}
