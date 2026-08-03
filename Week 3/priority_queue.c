/********************************************************
 * Program to implement priority queue as an array		*
 * version: 3											*
 * Date: 3-8-26											*
 * Author: Sooraj										*
 ********************************************************/

#include <stdio.h>

#define MAX 10
int queue[MAX][2];
int front=-1, back=-1;

/* function prototypes */
void enqueue(int value,int priority);//fucntion that checks for queue full or empty and inserts the element with its priority
int dequeueHighest(void);			//fucntion that checks for queue empty and dequeues the element with highest priority
int dequeueLowest(void);			//fucntion that checks for queue empty and dequeues the element with lowest prioroity
int seeHighest(void);				//fucntion that checks for queue empty and just prints the element with highest proiotrty 
int seeLowest(void);				//fucntion that checks for queue empty and just prints the element with lowest priority
void print_queue(void);				//fucntion that checks for queue empty and prints the elements in priority order
int isEmpty(void);					//fucntion that checks for queue empty - if the initial case is triggered
int isFull(void);					//fucntion that checks for queue full - if back is one less than MAX, 

int main(){
    for (int i = 0; i < MAX; i++)
        queue[i][1] = -1;
	int choice = -1;
	printf("Menu for Queue\n");
	printf("1.Enqueue\n2.Dequeue Highest Priority\n3.Dequeue Lowest Priority\n4.See Highest Memeber\n5.See Lowest Memeber\n6.See the queue in order of \n7.Exit\n");
	while (choice !=7)
		{
		int dequeued;
		printf("Enter Your choice:\n");
		scanf("%d", &choice);
		switch (choice){
			case 1:
				int val,priority;
				printf("Enter element to be queued:\n");
				scanf("%d", &val);
				printf("Enter its priority:\n");
				scanf("%d", &priority);
				enqueue(val,priority);
				
				break;
			case 2:
			{
				dequeued = dequeueHighest();
				if (dequeued != -1)
					printf("Highest Priority Element dequeued: %d\n", dequeued);
				break;
			}
			case 3:
			{
				dequeued = dequeueLowest();
				if (dequeued != -1)
					printf("Lowest Priority Element dequeued: %d\n", dequeued);
				break;
			}
			case 4:
			{
				int highest = seeHighest();
				if (highest != -1)
					printf("Topmost priority Element of queue: %d\n", highest);
				break;
			}
			case 5:
			{
				int least = seeLowest();
				if (least != -1)
					printf("Least Priority Element of queue: %d\n", least);
				break;
			}
			case 6:
				print_queue();
				break;
			case 7:
				printf("Exiting the Program\n");
				break;
			default:
				printf("Wrong Choice\n");
				break;
			}
		}
	}

void enqueue(int value, int priority){
	if(front ==-1)
		front++;
	if(isFull()==1){
		for(int i=0;i<=back;i++){
			if(queue[i][1]==-1){
				queue[i][0]=value;
				queue[i][1]=priority;
				printf("Queued\n");
				return;
				}
			}
			printf("Queue is Full\n");
			return;
			}
	back++;
	queue[back][0]=value;
	queue[back][1]=priority;
	printf("Queued\n");
	}

int dequeueHighest(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	int largest=-1;
	for (int i=0;i<=back;i++)
		if(queue[i][1]!=-1)
			if(largest==-1 || queue[i][1]>queue[largest][1])
				largest=i;

	if(largest==-1){
		printf("Queue is Empty\n");
		front=back=-1;
		return -1;
		}
		
	queue[largest][1]=-1;
	return queue[largest][0];
	}
	
int dequeueLowest(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	int smallest=-1;
	for (int i=0;i<=back;i++)
		if(queue[i][1]!=-1)
			if(smallest==-1 || queue[i][1]<queue[smallest][1])
				smallest=i;

	if(smallest==-1){
		printf("Queue is Empty\n");
		front=back=-1;
		return -1;
		}
		
	queue[smallest][1]=-1;
	return queue[smallest][0];
	}
	
int seeHighest(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	int largest=-1;
	for (int i=0;i<=back;i++)
		if(queue[i][1]!=-1)
			if(largest==-1 || queue[i][1]>queue[largest][1])
				largest=i;
	if(largest==-1){
		printf("Queue is Empty\n");
		return -1;
		}
	return queue[largest][0];
	}

int seeLowest(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return -1;
		}
	int smallest=-1;
	for (int i=0;i<=back;i++)
		if(queue[i][1]!=-1)
			if(smallest==-1 || queue[i][1]<queue[smallest][1])
				smallest=i;
				
	if(smallest==-1){
		printf("Queue is Empty\n");
		front=back=-1;
		return -1;
		}
	return queue[smallest][0];
	}
	
void print_queue(){
	if(isEmpty()==1){
		printf("Queue is Empty\n");
		return;
		}

	printf("Displaying the queue:\nElement\tPriority\n");
	for(int i=0;i<=back;i++)
		if(queue[i][1]!=-1)
			printf("%d\t%d\n",queue[i][0],queue[i][1]);
	}
	
int isEmpty(){

	if ((front == -1 && back == -1))
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
