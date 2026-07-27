/****************************************************
 * Program to implement circular queue as an array	*
 * version: 1										*
 * Date: 27 - 7 -26									*
 * Author: Sooraj									*
 ****************************************************/

#include <stdio.h>

#define MAX 10
int queue[MAX];
int front=-1, back=-1;

/* function prototypes */
void enqueue(int value);//fucntion that checks for queue full or empty and inserts the element
int dequeue(void); 		//fucntion that checks for queue empty and dequeues the element
int seeFront(void);		//fucntion that checks for queue empty and just returns the element
void print_queue(void);	//fucntion that checks for queue empty and prints the elements
int isEmpty(void);		//fucntion that checks for queue empty - if the initial case is triggered
int isFull(void);		//fucntion that checks for queue full - if back is one more than front, 
						      //also checks the wrap around case at the end and beggining of the queue.

int main()
{
//menu driven main fucntion to call other fucntions
	int choice = -1;
	printf("Menu for Queue\n");
	printf("1.Enqueue\n2.Dequeue\n3.See First Memeber\n4.See the queue\n5.Exit\n");
	while (choice !=5)
		{
		printf("Enter Your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element to be queued:\n");
			int val;
			scanf("%d", &val);
			enqueue(val);
			printf("Current queue:\n");
			print_queue();
			break;
		case 2:
			int dequeued = dequeue();
			if (dequeued != -1)
				printf("Element dequeued: %d\n", dequeued);
			printf("Current queue:\n");
			print_queue();
			break;
		case 3:
			int topmost = seeFront();
			if (topmost != -1)
				printf("Topmost Element of queue: %d\n", topmost);
			break;
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
	if(isFull()==1){
		printf("Queue is Full\n");
		return;
		}
	if(isEmpty()==1){
		front=0;
		back=0;
		}
	else if(back==MAX-1)
		back=0;
	else
		back++;
		
	queue[back]=value;
	printf("Queued\n");
	}


int dequeue(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	int element=queue[front];
	if(front ==back){
		//queue is exausted, reset
		front=-1;
		back=-1;
		}
	else if(front ==MAX-1)
		//reached the right end of queue, reset to first pos
		front=0;
	else
		front++;
	return element;
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
		return;
		}
	int i=front;
	while (1==1) {
        printf("%d\t", queue[i]);
        if (i == back)
            break;
        if (i == MAX - 1)
            i = 0;
        else 
            i++;
    	}
    printf("\n");
	}
	
int isEmpty(){
	if (front == -1 && back == -1)
		return 1;
	else
		return 0;
	}
	
int isFull(){
	if((front == 0 && back == MAX - 1) || (back + 1 == front))
		return 1;
	else
		return 0;
	}
		

