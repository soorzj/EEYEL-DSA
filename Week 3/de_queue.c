/****************************************************
 * Program to implement circular queue as an array	*
 * version: 1										*
 * Date: 3-8-26										*
 * Author: Sooraj									*
 ****************************************************/

#include <stdio.h>

#define MAX 10
int queue[MAX];
int front=-1, back=-1;

/* function prototypes */
void enqueueFront(int value);	//fucntion that checks for queue full or empty and inserts the element
void enqueueBack(int value);	//fucntion that checks for queue full or empty and inserts the element
int dequeueFront(void); 		//fucntion that checks for queue empty and dequeues the element
int dequeueBack(void); 			//fucntion that checks for queue empty and dequeues the element
int seeFront(void);				//fucntion that checks for queue empty and just returns the element
int seeBack(void);				//fucntion that checks for queue empty and just returns the element
void print_queue(void);			//fucntion that checks for queue empty and prints the elements
int isEmpty(void);				//fucntion that checks for queue empty - if the initial case is triggered
int isFull(void);				//fucntion that checks for queue full - if back is one more than front, 
								//also checks the wrap around case at the end and beggining of the queue.

int main()
{
//menu driven main fucntion to call other fucntions
	int choice = -1;
	int val,dequeued;
	printf("Menu for Queue\n");
	printf("1.Enqueue(front)\n2.Enqueue(back)\n3.Dequeue(front)\n4.Dequeue(back\n5.See First Memeber\n6.See Last Memeber\n7.See the queue\n8.Exit\n");
	while (choice !=8)
		{
		printf("Enter Your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element to be queued at front:\n");
			scanf("%d", &val);
			enqueueFront(val);
			print_queue();
			break;
		case 2:
			printf("Enter element to be queued at back:\n");
			scanf("%d", &val);
			enqueueBack(val);
			print_queue();
			break;
		case 3:
			dequeued = dequeueFront();
			if (dequeued != -1)
				printf("Element dequeued from front: %d\n", dequeued);
			print_queue();
			break;
		case 4:
			dequeued = dequeueBack();
			if (dequeued != -1)
				printf("Element dequeued from back: %d\n", dequeued);
			print_queue();
			break;
		case 5:
			int top = seeFront();
			if (top != -1)
				printf("Topmost Element of queue: %d\n", top);
			break;
		case 6:
			int bottom = seeBack();
			if (bottom != -1)
				printf("Bottom-most Element of queue: %d\n", bottom);
			break;
		case 7:
			print_queue();
			break;
		case 8:
			printf("Exiting the Program\n");
			break;
		default:
			printf("Wrong Choice\n");
			break;
		}
	}
}


void enqueueBack(int value){
	if(isFull()==1){
		printf("Queue is Full\n");
		return;
		}
	if(isEmpty()==1){
		front=0;
		back=0;
		}
	else if(back==MAX-1)
		//reached the rear end of array with space in front, circular wrap around
		back=0;
	else
		back++;
		
	queue[back]=value;
	printf("Queued at back\n");
	}
	
void enqueueFront(int value){
	if(isFull()==1){
		printf("Queue is Full\n");
		return;
		}
	if(isEmpty()==1){
		front=0;
		back=0;
		}
	else if(front==0)
		front=MAX-1;
	else
		front--;
		
	queue[front]=value;
	printf("Queued at front\n");
	}


int dequeueFront(){
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

int dequeueBack(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	int element=queue[back];
	if(front == back){
		//queue is exausted, reset
		front=-1;
		back=-1;
		}
	else if(back==0)
		//reached the right end of queue, reset to first pos
		back=MAX-1;
	else
		back--;
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
	
int seeBack(){

	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	else
		return (queue[back]);
	}

void print_queue(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return;
		}
	printf("Displaying the current queue:\n");
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
		

