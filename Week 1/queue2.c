/*
 * queue2.c
 * Program to implement queue as an array in C
 * Author: SOORAJ
 * Date: 6-7-26
 * Version: 1
 */

#include <stdio.h>

#define MAX 10
int queue[MAX];
int front=-1, back=-1;

/* function prototypes */
void enqueue(int value);
int dequeue(void);
int seeFront(void);
void print_queue(void);
int isEmpty(void);
int isFull(void);

int main()
{
	int choice = -1;
	printf("Menu for Queue\n");
	printf("1.Enqueue\n2.Dequeue\n3.See First Memeber\n4.See the queue\n5.Exit\n");
	while (choice !=5)
		{
		printf("Current queue:\n");
		print_queue();
		printf("Enter Your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element to be queued:\n");
			int val;
			scanf("%d", &val);
			enqueue(val);
			
			break;
		case 2:
		{
			int dequeued = dequeue();
			if (dequeued != -1)
				printf("Element dequeued: %d\n", dequeued);
			break;
		}
		case 3:
		{
			int topmost = seeFront();
			if (topmost != -1)
				printf("Topmost Element of queue: %d\n", topmost);
			break;
		}
		case 4:
			printf("Displaying the queue:\n");
			print_queue();
			break;
		case 5:
			printf("Exiting the Program\n");
			break;
		default:
			printf("Wrong Choice\n");
			break;
		}
	}
}
