/************************************************
 * Program to implement queue as an array		*
 * version: 2									*
 * Date: 27 - 7 -26								*
 * Author: Sooraj								*
 ************************************************/

#include <stdio.h>

#define MAX 10
int queue[MAX];
int front=-1, back=-1;

/* function prototypes */
void enqueue(int value);//fucntion that checks for queue full or empty and inserts the element
int dequeue(void);		//fucntion that checks for queue empty and dequeues the element
int seeFront(void);		//fucntion that checks for queue empty and just prints the element
void print_queue(void);	//fucntion that checks for queue empty and prints the elements
int isEmpty(void);		//fucntion that checks for queue empty - if the initial case is triggered or if front > back
int isFull(void);		//fucntion that checks for queue full - if back is one less than MAX, 

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

void enqueue(int value){
	if(front ==-1)
		front++;
	if(isFull()==1)
		printf("Queue is Full\n");
	else{
		back++;
		queue[back]=value;
		printf("Queued\n");
		}
	}

int dequeue(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	else
		return (queue[front++]);
	}

int seeFront(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	else
		return (queue[front]);
	}

void print_queue(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		}
	else{
		for (int i = back; i >= front; --i)
			printf("%d\t", queue[i]);
		printf("\n");
		}
	}
	
int isEmpty(){
	if (front>back)
		return 1;
	else if ((front == -1 && back == -1))
		return 1;
	else
		return 0;
	}
	
int isFull(){
	if(back==MAX-1)
		return 1;
	else
		return 0;
	}
		



