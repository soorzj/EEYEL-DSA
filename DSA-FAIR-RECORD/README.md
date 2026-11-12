# DSA FAIR RECORD
> [!WARNING]
> THIS RECORD HAS ALREADY BEEN SUBMITTED BY ME AND LOGGED, RESUBMITTING THE SAME PROGRAMS
> WILL LIKELY CAUSE YOUR FAIR RECORD TO BE REJECTED BY THE EXAMINER



# Table of Contents

| Expt No. | Experiment |
| :--- | :--- |
| 1 | Implementation of linear search and binary search. |
| 2 | Implementation of Stack and linear Queue using arrays. |
| 3 | Implementation of Priority Queues, DEQUEUE and Circular Queues using arrays. |
| 4 | Conversion of expression from one notation to another notation. |
| 5 | Implementation of various linked list operations. |
| 6 | Implementation of stack and queue using linked list. |
| 7 | Polynomial addition using linked list. |
| 8 | Polynomial multiplication using linked list. |
| 9 | Implementation of doubly linked list operations. |
| 10 | Implementation of circular linked list operations. | 
| 11 | Implementation of binary search tree - creation, insertion, deletion, search. | 
| 12 | Implementation of tree traversals - inorder, preorder, postorder. |
| 13 | Implementation of sorting algorithms- bubble sort, insertion sort and selection sort. | 
| 14 | Implementation of Merge sort. |
| 15 | Implementation of Quick sort. |
| 16 | Implementation of BFS and DFS on graph. |
| 17 | Implementation of hash table using own mapping functions and observe collisions and overflow resolving schemes. |

---



# Experiment 1: Implementation of linear search and binary search

## Program 1: Implementation of linear search in an array

```c
/***********************************************************************************
 * Program to perform linear search in an array 					*
 * version: 2									*
 * Date: 27 - 7 -26								*
 * Author: Sooraj								*
 ***********************************************************************************/
 
 #include <stdio.h>
  //function prototypes
  int lin_search(int *, int , int);  // function to search in a queue called a[] with n as number of elements and x is the element to be found
  
  void main(){
  // the main function
 	int n,x; //n to store the number of elements, x to store the element to be found
 	printf("Enter number of elements:\n");
	scanf("%d", &n);
	int a[n]; //to store the array elements
	printf("Enter %d elements:\n", n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("Enter element to be found:\n");
	scanf("%d", &x);
	int p=lin_search(a,n,x);
	if (p==-1)
		printf("Element not found in array\n");
	else
		printf("Element found in array at %d\n",p);
	}
 
 int lin_search (int a[], int n, int x){
 	for(int i=0; i<n;i++)
 		if(a[i]==x)
 			return i;
 		return -1;
 	}
```

### Sample Output
```text
Enter number of elements:
5
Enter 5 elements:
10 25 30 45 50
Enter element to be found:
30
Element found in array at 2
```

## Program 2: Implementation of Binary search in array

```c
/***********************************************************************************
 * Program to perform binary search in an array					*
 * version: 2									*
 * Date: 27 - 7 -26								*
 * Author: Sooraj								*
 ***********************************************************************************/
 
 #include <stdio.h>
 //function prototypes
void sort(int *, int);			//function to sort the elements using bubble sort
int bin_search(int*, int, int);	 	// the binary search function that accpets the array a[],
element count n and search element x and returns the position of element
 
 void main(){
 // the main function
 	int n,x; //n to store the number of elements, x to store the element to be found
 	printf("Enter number of elements:\n");
	scanf("%d", &n);
	int a[n]; //to store the array elements
	printf("Enter %d elements:\n", n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	sort(a,n);  //sort using bubble sort becuase its binary search
	printf("Sorted Array\n");
	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
	printf("Enter element to be found:\n");
	scanf("%d", &x);
	int p=bin_search(a,n,x);
	if (p==-1)
		printf("Element not found in array\n");
	else
		printf("Element found in array at %d\n",p);
	}
 
 void sort(int a[], int n){
	 for (int x=0; x<n-1; x++)
	 	for(int y=0;y<n-x-1;y++)
	 		if(a[y]>a[y+1]){
	 			int temp=a[y];
	 			a[y]=a[y+1];
	 			a[y+1]=temp;
	 			}
	 }
	 
 int bin_search (int a[], int n, int x){
 	int low=0,high=n-1;
 	while(low<=high){
 		int mid=(low+high)/2;
 		if(a[mid]==x)
 			return mid;
 		else if(a[mid] < x)
 			low=mid+1;
 		else
 			high=mid-1;
 		}
 		return -1;
	}
```

### Sample Output
```text
Enter number of elements:
6
Enter 6 elements:
45 12 78 23 56 10
Sorted Array
10	12	23	45	56	78	
Enter element to be found:
45
Element found in array at 3
```

# Experiment 2: Implementation of Stack and linear Queue using arrays

## Program 3: Implementation of Stack using arrays

```c
/*
 * Program to implement stack as an array in C
 * Author: SOORAJ
 * Date: 6-7-26
 * Version: 2
 */
#include <stdio.h>
int MAX =10;
int stack[MAX];
int top = -1;
/* function prototypes */
void push(int value);
int pop(void);
int peek(void);
void print_stack(void);
int isEmpty(void);
void push(int value)
{
	if (top == MAX - 1)
		printf("Stack Overflow\n");
	else
	{
		top++;
		stack[top] = value;
	}
}
int pop()
{
	if (isEmpty() == 1)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
		return stack[top--];
}
int peek()
{
	if (isEmpty() == 1)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
		return stack[top];
}
void print_stack()
{
	if (isEmpty() == 1)
	{
		printf("Stack Empty\n");
		return;
	}
	for (int i = top; i >= 0; --i)
		printf("%d\n", stack[i]);
}
int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
int main()
{
	int choice = -1;
	while (choice != 5)
	{
		printf("Menu for stack\n");
		printf("1.Push\n2.Pop\n3.Peek\n4.See all\n5.Exit\n");
		printf("Enter Your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element to push to stack:\n");
			int val;
			scanf("%d", &val);
			push(val);
			break;
		case 2:
		{
			int popped = pop();
			if (popped != -1)
				printf("Element Popped: %d\n", popped);
			break;
		}
		case 3:
		{
			int topmost = peek();
			if (topmost != -1)
				printf("Topmost Element peeked: %d\n", topmost);
			break;
		}
		case 4:
			printf("Displaying the stack:\n");
			print_stack();
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
```

### Sample Output
```text
Menu for stack
1.Push
2.Pop
3.Peek
4.See all
5.Exit
Enter Your choice:
1
Enter element to push to stack:
10
Enter Your choice:
1
Enter element to push to stack:
20
Enter Your choice:
1
Enter element to push to stack:
30
Enter Your choice:
4
Displaying the stack:
30
20
10
Enter Your choice:
3
Topmost Element peeked: 30
Enter Your choice:
2
Element Popped: 30
Enter Your choice:
4
Displaying the stack:
20
10
Enter Your choice:
5
Exiting the Program
```

## Program 4: Implementation of Queue using arrays

```c
/****************************************************************************
 * Program to implement queue as an array					*
 * version: 2									*
 * Date: 27 - 7 -26								*
 * Author: Sooraj								*
 ****************************************************************************/
#include <stdio.h>
#define MAX 10
int queue[MAX];
int front=-1, back=-1;
/* function prototypes */
void enqueue(int value);//function that checks for queue full or empty and inserts the element
int dequeue(void);		//function that checks for queue empty and dequeues the element
int seeFront(void);		//function that checks for queue empty and just prints the element
void print_queue(void);	//function that checks for queue empty and prints the elements
int isEmpty(void);		//function that checks for queue empty - if the initial case is triggered or if front > back
int isFull(void);		//function that checks for queue full - if back is one less than MAX, 
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
```

### Sample Output
```text
Menu for Queue
1.Enqueue
2.Dequeue
3.See First Memeber
4.See the queue
5.Exit
Current queue:
Queue is Empty
Enter Your choice:
1
Enter element to be queued:
10
Queued
Current queue:
10
Enter Your choice:
1
Enter element to be queued:
20
Queued
Current queue:
20	10
Enter Your choice:
1
Enter element to be queued:
30
Queued
Current queue:
30	20	10
Enter Your choice:
3
Topmost Element of queue: 10
Current queue:
30	20	10
Enter Your choice:
4
Displaying the queue:
30	20	10
Current queue:
30	20	10
Enter Your choice:
2
Element dequeued: 10
Current queue:
30	20
Enter Your choice:
2
Element dequeued: 20
Current queue:
30
Enter Your choice:
5
Exiting the Program
```

# Experiment 3: Implementation of Priority Queues, DEQUEUE and Circular Queues using arrays

## Program 5: Implementation of Priority Queues using arrays

```c
/****************************************************************************************************
 * Program to implement priority queue as an array						*
 * version: 3											*
 * Date: 3-8-26											*
 * Author: Sooraj										*
 ****************************************************************************************************/
#include <stdio.h>
#define MAX 10
int queue[MAX][2];
int front=-1, back=-1;
/* function prototypes */
void enqueue(int value,int priority);//function that checks for queue full or empty and inserts the element with its priority
int dequeueHighest(void);//function that checks for queue empty and dequeues the element with highest priority
int dequeueLowest(void); //function that checks for queue empty and dequeues the element with lowest prioroity
int seeHighest(void);	//function that checks for queue empty and just prints the element with highest proiotrty 
int seeLowest(void);	//function that checks for queue empty and just prints the element with lowest priority
void print_queue(void);	//function that checks for queue empty and prints the elements in priority order
int isEmpty(void);	//function that checks for queue empty - if the initial case is triggered
int isFull(void);		//function that checks for queue full - if back is one less than MAX, 
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
```

### Sample Output
```text
Menu for Queue
1.Enqueue
2.Dequeue Highest Priority
3.Dequeue Lowest Priority
4.See Highest Memeber
5.See Lowest Memeber
6.See the queue in order of 
7.Exit
Enter Your choice:
1
Enter element to be queued:
10
Enter its priority:
2
Queued
Enter Your choice:
1
Enter element to be queued:
20
Enter its priority:
5
Queued
Enter Your choice:
1
Enter element to be queued:
30
Enter its priority:
1
Queued
Enter Your choice:
6
Displaying the queue:
Element	Priority
10	2
20	5
30	1
Enter Your choice:
4
Topmost priority Element of queue: 20
Enter Your choice:
5
Least Priority Element of queue: 30
Enter Your choice:
2
Highest Priority Element dequeued: 20
Enter Your choice:
3
Lowest Priority Element dequeued: 30
Enter Your choice:
6
Displaying the queue:
Element	Priority
10	2
Enter Your choice:
7
Exiting the Program
```

## Program 6: Implementation of Double-ended Queues using arrays

```c
/*********************************************************
 * Program to implement circular queue as an array	*
 * version: 1						*
 * Date: 3-8-26						*
 * Author: Sooraj					*
 **********************************************************/
#include <stdio.h>
#define MAX 10
int queue[MAX];
int front=-1, back=-1;
/* function prototypes */
void enqueueFront(int value);	//function that checks for queue full or empty and inserts the element
void enqueueBack(int value);	//function that checks for queue full or empty and inserts the element
int dequeueFront(void); 		//function that checks for queue empty and dequeues the element
int dequeueBack(void); 		//function that checks for queue empty and dequeues the element
int seeFront(void);		//function that checks for queue empty and just returns the element
int seeBack(void);		//function that checks for queue empty and just returns the element
void print_queue(void);		//function that checks for queue empty and prints the elements
int isEmpty(void);		//function that checks for queue empty - if the initial case is triggered
int isFull(void);			//function that checks for queue full - if back is one more than front, 
				
int main()
{
//menu driven main function to call other functions
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
```

### Sample Output
```text
Menu for Queue
1.Enqueue(front)
2.Enqueue(back)
3.Dequeue(front)
4.Dequeue(back
5.See First Memeber
6.See Last Memeber
7.See the queue
8.Exit
Enter Your choice:
1
Enter element to be queued at front:
10
Queued at front
Displaying the current queue:
10
Enter Your choice:
2
Enter element to be queued at back:
20
Queued at back
Displaying the current queue:
10	20
Enter Your choice:
2
Enter element to be queued at back:
30
Queued at back
Displaying the current queue:
10	20	30
Enter Your choice:
1
Enter element to be queued at front:
5
Queued at front
Displaying the current queue:
5	10	20	30
Enter Your choice:
5
Topmost Element of queue: 5
Enter Your choice:
6
Bottom-most Element of queue: 30
Enter Your choice:
3
Element dequeued from front: 5
Displaying the current queue:
10	20	30
Enter Your choice:
4
Element dequeued from back: 30
Displaying the current queue:
10	20
Enter Your choice:
7
Displaying the current queue:
10	20
Enter Your choice:
8
Exiting the Program
```

## Program 7: Implementation of Circular Queues using arrays

```c
/**********************************************************
 * Program to implement circular queue as an array	*
 * version: 1						*
 * Date: 27 - 7 -26					*
 * Author: Sooraj					*
 **********************************************************/
#include <stdio.h>
#define MAX 10
int queue[MAX];
int front=-1, back=-1;
/* function prototypes */
void enqueue(int value);//fucntion that checks for queue full or empty and inserts the element
int dequeue(void); 		//fucntion that checks for queue empty and dequeues the element
int seeFront(void);		//fucntion that checks for queue empty and just returns the element
void print_queue(void);		//fucntion that checks for queue empty and prints the elements
int isEmpty(void);		//fucntion that checks for queue empty - if the initial case is triggered
int isFull(void);			//fucntion that checks for queue full - if back is one more than front, 
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
```

### Sample Output
```text
Menu for Queue
1.Enqueue
2.Dequeue
3.See First Memeber
4.See the queue
5.Exit
Enter Your choice:
1
Enter element to be queued:
10
Queued
Current queue:
10
Enter Your choice:
1
Enter element to be queued:
20
Queued
Current queue:
10	20
Enter Your choice:
1
Enter element to be queued:
30
Queued
Current queue:
10	20	30
Enter Your choice:
3
Topmost Element of queue: 10
Enter Your choice:
4
Displaying the queue:
10	20	30
Enter Your choice:
2
Element dequeued: 10
Current queue:
20	30
Enter Your choice:
2
Element dequeued: 20
Current queue:
30
Enter Your choice:
1
Enter element to be queued:
40
Queued
Current queue:
30	40
Enter Your choice:
5
Exiting the Program
```

# Experiment 4: Conversion of expression from one notation to another notation

## Program 8: Conversion of infix notation expression to postfix expression

```c
/***********************************************************
* Program to implement infix to postfix as an stack in C       *
* Author: SOORAJ                                              		  *
* Date: 10-8-26                                               		  *
* Version: 2                                                  		  *
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
char infix[MAX];
char symbol[MAX];
int topSymbol = -1;
/* function prototypes */
void pushSymbol(char value);    	//Checks if the stack is full and pushes the symbols
char popSymbol(void);           	//checks if the stack is emplty and pops out the last symbol
char peekSymbol(void);          	//checks if the stack is emplty and just displays the last symbol
void print_stack(void);         	//prints the stack until the end or a bracket is reached
int priority(char c);           	//returns a numeric code for the priority of the passed symbol
int isSymbol(char c);           	//return 1 if symbol else 0
int isEmpty(void);              	//return 1 is stack empty else 0
int isSpace(char c);           	//return 1 if c is whitespace els 0
int isDigit(char c);           	//return 1 if c is a digit else 0
int main()
{
	printf("Enter the expression: ");
	fgets(infix, MAX, stdin);
	printf("Postfix Expression: ");
	for (int i = 0; infix[i] != '\0'; i++)
	{
		char ch = infix[i];
		if (isSpace(ch))
			continue;
		if (isDigit(ch)){
			while (isDigit(infix[i])){
				printf("%c", infix[i]);  //continous digits without space
				i++;
			}
			printf(" ");
			i--;
		}
		else if (isSymbol(ch) == 0)
			printf("%c ", ch);
		else if (ch == '(')
			pushSymbol(ch);
		else if (ch == ')'){
			while (!isEmpty() && peekSymbol() != '(')
				printf("%c ", popSymbol());
            if (!isEmpty() && peekSymbol() == '(')
				popSymbol();
		}
		else{
			while (!isEmpty() && peekSymbol() != '(' && priority(peekSymbol()) >= priority(ch))
				printf("%c ", popSymbol());
			pushSymbol(ch);
		}
	}
	while (!isEmpty())
		printf("%c ", popSymbol());
	printf("\n");
	return 0;
}
void pushSymbol(char value){
	if (topSymbol == MAX - 1)
		printf("Stack Overflow\n");
	else{
		topSymbol++;
		symbol[topSymbol] = value;
	}
}
char popSymbol(){
	if (topSymbol == -1)
		return -1;
	else
		return symbol[topSymbol--];
}
char peekSymbol(){
	if (topSymbol == -1)
		return -1;
	else
		return symbol[topSymbol];
}
int priority(char c){
	switch (c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}
int isSpace(char c){
    if(c == ' ' || c == '\n' || c == '\t')
        return 1;
    else
        return 0;
}
int isDigit(char c){
    if (c >= '0' && c <= '9')
        return 1;
    else 
        return 0;
}
int isSymbol(char c){
	switch (c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return 1;
		case '(':
		case ')':
			return 2;
		default:
			return 0;
	}
}
int isEmpty(){
	if (topSymbol == -1)
		return 1;
	else
		return 0;
}
void print_stack(){
	if (isEmpty() == 1){
		printf("Stack Empty\n");
		return;
	}
	for (int i = topSymbol; i >= 0; --i)
		printf("%c ", symbol[i]);
}
```

### Sample Output
```text
Enter the expression: (12+5)*3-8/2
Postfix Expression: 12 5 + 3 * 8 2 / -
Enter the expression: (2+3)^4*5-6
Postfix Expression: 2 3 + 4 ^ 5 * 6 -
```

# Experiment 5: Implementation of various linked list operations

## Program 9: Implementation of a single linked list ADT in C and its various operations

```c
/**********************************************************
* Program to implement single linked list in C using struct *
* Author: SOORAJ                                               		*
* Date: 10-8-26                                                		*
* Version: 2                                                  		*
***********************************************************/
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
void deleteAtPosition(int pos);    //fucntion that checks if LL is empty and delets element at a given position
void displayList(void);                 //fucntion that checks if LL is empty and prints elements in order
void updateElement(int old, int new);   //fucntion that checks for a value 'old' and replaces it with value 'new'
int main() {
    int choice=-1, val, pos;
    while (choice!=9) {
        printf("Menu for Single LinkedList\n");
        printf("1.Add Element at front\n2.Add Element at back\n3.Insert Element at position\n4.Delete First Element\n5.Delete Last Element\n6.Delete Element at position\n7.Display Linked List\n8.Search and update\n9.Exit\n");
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
            	int old,new;
                printf("Enter The element to be replaced:\n");
                scanf("%d", &old);
                printf("Enter The new element:\n");
                scanf("%d", &new);
                updateElement(old,new);
                break;
            case 9:
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
        if (current->next == NULL) {
            printf("Position out of range\n");
            return;
        }
        current = current->next;
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
    printf("\n");
}
void updateElement(int oldVal, int newVal) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        if (current->data == oldVal) {
            current->data = newVal;
            printf("Element updated successfully\n");
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list\n", oldVal);
}
```

### Sample Output
```text
Menu for Single LinkedList
1.Add Element at front
2.Add Element at back
3.Insert Element at position
4.Delete First Element
5.Delete Last Element
6.Delete Element at position
7.Display Linked List
8.Search and update
9.Exit
Enter Your choice:
1
Enter The element:
10
Enter Your choice:
2
Enter The element:
20
Enter Your choice:
2
Enter The element:
30
Enter Your choice:
7
10	20	30	
Enter Your choice:
3
Enter The element:
15
Enter The position:
2
Enter Your choice:
7
10	15	20	30	
Enter Your choice:
8
Enter The element to be replaced:
20
Enter The new element:
25
Element updated successfully
Enter Your choice:
7
10	15	25	30	
Enter Your choice:
4
First element deleted
Enter Your choice:
5
Last element deleted
Enter Your choice:
7
15	25	
Enter Your choice:
6
Enter The position:
2
Element at position 2 deleted
Enter Your choice:
7
15	
Enter Your choice:
9
Exiting Program
```

# Experiment 6: Implementation of stack and queue using linked list

## Program 10: Implementation of queue using linked list

```c
/*******************************************************************
* Program to implement Queue ADT using Single Linked List in C *
* Author: SOORAJ                                               			*
* Date: 10-8-26                                                			*
* Version: 2                                                   			*
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
// function prototypes
int isEmpty(void);                     	// checks if queue is empty
void enqueue(int val);                 	// inserts element at last position (back)
void dequeue(void);                    	// deletes element at first position (front)
void peek(void);                      	// views element at first position without dequeuing
void displayQueue(void);           	// prints elements in order
int main() {
    int choice = -1, val;
    while (choice != 5) {
        printf("\nMenu for Queue\n");
        printf("1. Enqueue \n2. Dequeue \n3. Peek \n4. Display Queue\n5. Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter The element:\n");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                displayQueue();
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
int isEmpty() {
    if (head == NULL)
    	return 1;
    else
    	return 0;
}
void enqueue(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (isEmpty()) {
        head = newNode;
        return;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct node *first = head;
    printf("Front element dequeued: %d\n",first->data);
    head = head->next;
    free(first);
    
}
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", head->data);
}
void displayQueue(void) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}
```

### Sample Output
```text
Menu for Queue
1. Enqueue 
2. Dequeue 
3. Peek 
4. Display Queue
5. Exit
Enter Your choice:
1
Enter The element:
10
Enter Your choice:
1
Enter The element:
20
Enter Your choice:
1
Enter The element:
30
Enter Your choice:
3
Front element: 10
Enter Your choice:
4
10	20	30	
Enter Your choice:
2
Front element dequeued: 10
Enter Your choice:
4
20	30	
Enter Your choice:
2
Front element dequeued: 20
Enter Your choice:
2
Front element dequeued: 30
Enter Your choice:
4
Queue is empty
Enter Your choice:
5
Exiting Program
```

## Program 11: Implementation of stack using linked list

```c
/*******************************************************************
* Program to implement Stack ADT using Single Linked List in C 	*
* Author: SOORAJ                                               			*
* Date: 10-8-26                                                			*
* Version: 2                                                  			*
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
// function prototypes
void push(int val);                     	// inserts element at top of the stack
void pop(void);                         	// deletes element from top of the stack
void displayStack(void);                // prints elements in stack order
void peek();			// displays the element at the top of the stack
int isEmpty();			// checks if the stack is empty (if top=NULL)
int main() {
    int choice = -1, val;
    while (choice != 5) {
        printf("\nMenu for Stack\n");
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
    printf("Top element popped:%d\n",first->data);
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
	if (top == NULL)  return 1;
    	else	return 0;
}
```

### Sample Output
```text
Menu for Stack
1. Push
2. Pop
3. Peek
4. Display the Stack
5. Exit
Enter Your choice:
1
Enter The element:
10
Enter Your choice:
1
Enter The element:
20
Enter Your choice:
1
Enter The element:
30
Enter Your choice:
4
30	20	10	
Enter Your choice:
2
Top element popped:30
Enter Your choice:
4
20	10	
Enter Your choice:
2
Top element popped:20
Enter Your choice:
3
Top element peeked: 10
Enter Your choice:
2
Top element popped:10
Enter Your choice:
4
Stack underflow
Enter Your choice:
5
Exiting Program
```

# Experiment 7: Polynomial addition using linked list

## Program 12: Adding 2 user inputted polynomials and displaying the result using linked lists

```c
/**********************************************************
* Program to add two polynomials using singly linked list   *
* Author: SOORAJ                                               		*
* Date: 10-8-26                                                		*
* Version: 3                                                   		*
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int coeff;   // coefficient of term
    int exp;     // exponent of term
    struct node *next;
};
struct node *poly1 = NULL;
struct node *poly2 = NULL;
struct node *result = NULL;
// function prototypes
void insertBack(int c, int e, struct node **headRef);// inserts term at end of list
void insertSorted(int c, int e);                       	 // inserts term in descending order of exponent
void displayList(struct node *head);                   	 // displays polynomial
void addPolynomials();                                 	 // adds poly1 and poly2, stores in result
int main() {
    int deg1, deg2, i, coeff;
    
    printf("Enter the highest degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients from x^%d to constant:\n", deg1);
    for (i = deg1; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {  // skip zero terms
            insertBack(coeff, i, &poly1);
        }
    }
    printf("\nFirst polynomial Entered: ");
    displayList(poly1);
    
    printf("\nEnter the highest degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients from x^%d to constant:\n", deg2);
    for (i = deg2; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {
            insertBack(coeff, i, &poly2);
        }
    }
    
    printf("\nSecond polynomial Entered:");
    displayList(poly2);
    addPolynomials();
    printf("Resultant polynomial: ");
    displayList(result);
    return 0;
}
void insertBack(int c, int e, struct node **headRef) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    
    if (*headRef == NULL) {
        *headRef = newNode;
    } 
    else {
        struct node *temp = *headRef;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void insertSorted(int c, int e) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->exp = e;
    if (result == NULL) {
        newNode->next = NULL;
        result = newNode;
        return;
    }
    if (e > result->exp) {
        newNode->next = result;
        result = newNode;
        return;
    }
    if (e == result->exp) {
        result->coeff += c;
        free(newNode);
        return;
    }
    struct node *current = result;
    while (current->next != NULL && current->next->exp > e)
        current = current->next;
    if (current->next != NULL && current->next->exp == e) {
        current->next->coeff += c;
        free(newNode);
    }
    else {
        newNode->next = current->next;
        current->next = newNode;
    }
}
void displayList(struct node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    
    struct node *current = head;
    while (current != NULL) {
    	if(current->exp==0){
    		if(current->coeff!=0)
    			printf("%d\n", current->coeff);
    		}
    		
    	else{
        	if(current->coeff!=0){
        		printf("%dx^%d ",current->coeff,current->exp);
        		if(current->next!=NULL && current->next->coeff>0)
        			printf("+ ");
				}
        	}        	
       current = current->next;
    }
    printf("\n");
}
void addPolynomials() {
    struct node *p1 = poly1;
    struct node *p2 = poly2;
    
    while (p1 != NULL) {
        insertSorted(p1->coeff, p1->exp);
        p1 = p1->next;
    }
    
    while (p2 != NULL) {
        insertSorted(p2->coeff, p2->exp);
        p2 = p2->next;
    }
}
```

### Sample Output
```text
Enter the highest degree of first polynomial: 3
Enter coefficients from x^3 to constant:
Coefficient of x^3: 2
Coefficient of x^2: 0
Coefficient of x^1: 3
Coefficient of x^0: 4
First polynomial Entered: 2x^3 + 3x^1 + 4
Enter the highest degree of second polynomial: 2
Enter coefficients from x^2 to constant:
Coefficient of x^2: 5
Coefficient of x^1: 2
Coefficient of x^0: 1
Second polynomial Entered:5x^2 + 2x^1 + 1
Resultant polynomial: 2x^3 + 5x^2 + 5x^1 + 5
```

# Experiment 8: Polynomial multiplication using linked list.

## Program 13: Multiplying 2 user inputted polynomials and displaying the result using linked lists

```c
/*******************************************************************
* Program to multiply two polynomials using singly linked list 	*
* Author: SOORAJ                                               			*
* Date: 10-8-26                                                			*
* Version: 3                                                  			*
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int coeff;   // coefficient of term
    int exp;     // exponent of term
    struct node *next;
};
struct node *poly1 = NULL;
struct node *poly2 = NULL;
struct node *result = NULL;
// function prototypes
void insertBack(int c, int e, struct node **headRef);   	// inserts term at end of list
void insertSorted(int c, int e);            			// inserts term in descending order of exponent
void displayList(struct node *head);         			// displays polynomial
void multiplyPolynomials();             		     	// multiplies poly1 and poly2, stores in result
void combineLikeTerms();                  			// combines adjacent nodes with same exponent in result list
int main() {
    int deg1, deg2, i, coeff;
    printf("Enter the highest degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients from x^%d to constant:\n", deg1);
    for (i = deg1; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {  // skip zero terms
            insertBack(coeff, i, &poly1);
        }
    }
    printf("\nFirst polynomial Entered: ");
    displayList(poly1);
    printf("\nEnter the highest degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients from x^%d to constant:\n", deg2);
    for (i = deg2; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {
            insertBack(coeff, i, &poly2);
        }
    }
    printf("\nSecond polynomial Entered:");
    displayList(poly2);
    multiplyPolynomials();
    printf("Resultant polynomial: ");
    displayList(result);
    return 0;
}
void insertBack(int c, int e, struct node **headRef) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    
    if (*headRef == NULL) {
        *headRef = newNode;
    } 
    else {
        struct node *temp = *headRef;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void insertSorted(int c, int e) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->exp = e;
    if (result == NULL) {
        newNode->next = NULL;
        result = newNode;
        return;
    }
    if (e > result->exp) {
        newNode->next = result;
        result = newNode;
        return;
    }
    if (e == result->exp) {
        result->coeff += c;
        free(newNode);
        return;
    }
    struct node *current = result;
    while (current->next != NULL && current->next->exp > e)
        current = current->next;
    if (current->next != NULL && current->next->exp == e) {
        current->next->coeff += c;
        free(newNode);
    }
    else {
        newNode->next = current->next;
        current->next = newNode;
    }
}
void displayList(struct node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
    	if(current->exp==0){
    		if(current->coeff!=0)
    			printf("%d\n", current->coeff);
    		}
    	else{
        	if(current->coeff!=0){
        		printf("%dx^%d ",current->coeff,current->exp);
        		if(current->next!=NULL && current->next->coeff>0)
        			printf("+ ");
				}
        	}        	
       current = current->next;
    }
    printf("\n");
}
// Multiply two polynomials poly1 and poly2, store result in result list
void multiplyPolynomials() {
    struct node *p1 = poly1;
    struct node *p2;
    while (p1 != NULL) {
        p2 = poly2;
        while (p2 != NULL) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            insertSorted(coeff, exp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}
```

### Sample Output
```text
Enter the highest degree of first polynomial: 2
Enter coefficients from x^2 to constant:
Coefficient of x^2: 2
Coefficient of x^1: 3
Coefficient of x^0: 1
First polynomial Entered: 2x^2 + 3x^1 + 1
Enter the highest degree of second polynomial: 2
Enter coefficients from x^2 to constant:
Coefficient of x^2: 1
Coefficient of x^1: 2
Coefficient of x^0: 3
Second polynomial Entered:1x^2 + 2x^1 + 3
Resultant polynomial: 2x^4 + 7x^3 + 13x^2 + 11x^1 3
```

# Experiment 9: Implementation of doubly linked list operations.

## Program 14: Implementation of a doubly linked list ADT and its operations in C

```c
/******************************************************************
* Program to implement double linked list in C using struct    	*
* Author: SOORAJ                                              			*
* Date: 10-8-26                                                			*
* Version: 2                                                   			*
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
// function prototypes
void insertFront(int val);                 //function that checks if LL is empty and inserts element at first position
void insertBack(int val);                  //function that checks if LL is empty and inserts element at last position
void insertAtPosition(int pos, int val);//function that checks if LL is empty and inserts element at a given position
void deleteFirst(void);                   //function that checks if LL is empty and deletes element at first position
void deleteLast(void);                   //function that checks if LL is empty and deletes element at last position
void deleteAtPosition(int pos);     //function that checks if LL is empty and deletes element at a given position
void displayList(void);                  //function that checks if LL is empty and prints elements in order
void updateElement(int old, int new);   //function that checks for a value 'old' and replaces it with value 'new'
int main() {
    int choice=-1, val, pos;
    while (choice!=9) {
        printf("Menu for Double LinkedList\n");
        printf("1.Add Element at front\n2.Add Element at back\n3.Insert Element at position\n4.Delete First Element\n5.Delete Last Element\n6.Delete Element at position\n7.Display Linked List\n8.Search and update\n9.Exit\n");
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
                int old,new;
                printf("Enter The element to be replaced:\n");
                scanf("%d", &old);
                printf("Enter The new element:\n");
                scanf("%d", &new);
                updateElement(old,new);
                break;
            case 9:
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
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}
void insertBack(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}
void insertAtPosition(int pos, int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (pos == 1) {
        insertFront(val);
        free(newNode); // Avoid memory leak since insertFront allocated its own node
        return;
    }
    struct node *current = head;
    for (int i = 1; i < pos-1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        // Position out of range, insert at the end
        insertBack(val);
        free(newNode);
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *first = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
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
    struct node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    struct node *last = current->next;
    current->next = NULL;
    free(last);
    printf("Last element deleted\n");
}
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteFirst();
        return;
    }
    struct node *current = head;
    for (int i = 1; i < pos-1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct node *toDelete = current->next;
    current->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = current;
    }
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
    printf("\n");
}
void updateElement(int oldVal, int newVal) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        if (current->data == oldVal) {
            current->data = newVal;
            printf("Element updated successfully\n");
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list\n", oldVal);
}
```

### Sample Output
```text
Menu for Double LinkedList
1.Add Element at front
2.Add Element at back
3.Insert Element at position
4.Delete First Element
5.Delete Last Element
6.Delete Element at position
7.Display Linked List
8.Search and update
9.Exit
Enter Your choice:
1
Enter The element:
10
Enter Your choice:
2
Enter The element:
20
Enter Your choice:
2
Enter The element:
30
Enter Your choice:
7
10	20	30	
Enter Your choice:
3
Enter The element:
15
Enter The position:
2
Enter Your choice:
7
10	15	20	30	
Enter Your choice:
8
Enter The element to be replaced:
20
Enter The new element:
25
Element updated successfully
Enter Your choice:
7
10	15	25	30	
Enter Your choice:
4
First element deleted
Enter Your choice:
5
Last element deleted
Enter Your choice:
7
15	25	
Enter Your choice:
6
Enter The position:
2
Element at position 2 deleted
Enter Your choice:
7
15	
Enter Your choice:
9
Exiting Program
```

# Experiment 10: Implementation of circular linked list operations.

## Program 15: Implementation of a circular linked list ADT and its operations in C

```c
/*******************************************************************
* Program to implement circular linked list using tail pointer     	*
* Author: SOORAJ                                               			*
* Date: 10-8-26                                                			*
* Version: 2                                                   			*
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *tail = NULL;
// function prototypes
void insertFront(int val);                     //function that checks if LL is empty and inserts element at first position
void insertBack(int val);                     //function that checks if LL is empty and inserts element at last position
void insertAtPosition(int pos, int val);//function that checks if LL is empty and inserts element at a given position
void deleteFirst(void);                         //function that checks if LL is empty and deletes element at first position
void deleteLast(void);                         //function that checks if LL is empty and deletes element at last position
void deleteAtPosition(int pos);           //function that checks if LL is empty and deletes element at a given position
void displayList(void);                        //function that checks if LL is empty and prints elements in order
void updateElement(int oldVal, int newVal); 
     //function that checks for a value 'old' and replaces it with value 'new'
int main() {
    int choice=-1, val, pos;
    while (choice!=9) {
        printf("Menu for Circular LinkedList\n");
        printf("1.Add Element at front\n2.Add Element at back\n3.Insert Element at position\n4.Delete First Element\n5.Delete Last Element\n6.Delete Element at position\n7.Display Linked List\n8.Search and update\n9.Exit\n");
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
                int oldVal, newVal;
                printf("Enter The element to be replaced:\n");
                scanf("%d", &oldVal);
                printf("Enter The new element:\n");
                scanf("%d", &newVal);
                updateElement(oldVal, newVal);
                break;
            case 9:
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
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}
void insertBack(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtPosition(int pos, int val) {
    if (pos == 1) {
        insertFront(val);
        return;
    }
    if (tail == NULL) {
        // Position out of range for empty list beyond pos 1
        insertBack(val);
        return;
    }
    struct node *current = tail->next; // Start at head
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
        if (current == tail->next) { // Wrapped back to head before reaching pos-1
            insertBack(val);
            return;
        }
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = current->next;
    current->next = newNode;
    if (current == tail) {
        tail = newNode;
    }
}
void deleteFirst() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *head = tail->next;
    if (tail == head) { // Only one element
        free(tail);
        tail = NULL;
    } else {
        tail->next = head->next;
        free(head);
    }
    printf("First element deleted\n");
}
void deleteLast() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *head = tail->next;
    if (tail == head) { // Only one element
        free(tail);
        tail = NULL;
    } else {
        struct node *current = head;
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;
        free(tail);
        tail = current;
    }
    printf("Last element deleted\n");
}
void deleteAtPosition(int pos) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteFirst();
        return;
    }
    struct node *current = tail->next; // Start at head
    for (int i = 1; i < pos - 1; i++) {
        if (current->next == tail->next) { // Reached end before pos
            printf("Position out of range\n");
            return;
        }
        current = current->next;
    }
    struct node *toDelete = current->next;
    if (toDelete == tail->next && current != tail) {
        printf("Position out of range\n");
        return;
    }
    current->next = toDelete->next;
    if (toDelete == tail) {
        tail = current;
    }
    free(toDelete);
    printf("Element at position %d deleted\n", pos);
}
void displayList(void) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = tail->next; // Start at head
    do {
        printf("%d\t", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("\n");
}
void updateElement(int oldVal, int newVal) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = tail->next; // Start at head
    do {
        if (current->data == oldVal) {
            current->data = newVal;
            printf("Element updated successfully\n");
            return;
        }
        current = current->next;
    } while (current != tail->next);
    printf("Element %d not found in the list\n", oldVal);
}
```

### Sample Output
```text
Menu for Circular LinkedList
1.Add Element at front
2.Add Element at back
3.Insert Element at position
4.Delete First Element
5.Delete Last Element
6.Delete Element at position
7.Display Linked List
8.Search and update
9.Exit
Enter Your choice:
1
Enter The element:
10
Enter Your choice:
2
Enter The element:
20
Enter Your choice:
2
Enter The element:
30
Enter Your choice:
7
10	20	30	
Enter Your choice:
3
Enter The element:
15
Enter The position:
2
Enter Your choice:
7
10	15	20	30	
Enter Your choice:
8
Enter The element to be replaced:
20
Enter The new element:
25
Element updated successfully
Enter Your choice:
7
10	15	25	30	
Enter Your choice:
4
First element deleted
Enter Your choice:
5
Last element deleted
Enter Your choice:
7
15	25	
Enter Your choice:
6
Enter The position:
2
Element at position 2 deleted
Enter Your choice:
7
15	
Enter Your choice:
9
Exiting Program
```

# Experiment 11: Implementation of binary search tree - creation, insertion, deletion, search

## Program 16: Implementation of binary search tree using struct and basic fucntions

```c
/***************************************************************
 * Program to implement binary search tree in C using struct  	*
 * Author: SOORAJ                                              			*
 * Date: 10-8-26                                               			*
 * Version: 1                                                 			*
 ***************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
// function prototypes
void insertElement(int val);             //function that checks if tree is empty and inserts element at appropriate position
void deleteElement(int val);             //function that checks if tree is empty and deletes a given element
void searchElement(int val);             //function that checks if tree is empty and searches for an element
void displayTree(void);                  //function that checks if tree is empty and prints elements in inorder traversal
void inorderTraversal(struct node *ptr); //helper function to perform recursive inorder traversal
struct node* deleteHelper(struct node *rootNode, int val); //helper function to handle recursive deletion
struct node* getMinNode(struct node *curr); //helper function to find inorder successor
int main() {
    int choice = -1, val;
    while (choice != 5) {
        printf("\nMenu for Binary Search Tree\n");
        printf("1.Insert Element\n2.Delete Element\n3.Search Element\n4.Display Tree (Inorder)\n5.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter The element to insert:\n");
                scanf("%d", &val);
                insertElement(val);
                break;
            case 2:
                printf("Enter The element to delete:\n");
                scanf("%d", &val);
                deleteElement(val);
                break;
            case 3:
                printf("Enter The element to search:\n");
                scanf("%d", &val);
                searchElement(val);
                break;
            case 4:
                displayTree();
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
void insertElement(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL) {
        root = newNode;
        printf("Element inserted\n");
        return;
    }
	//finding the parent nodee
    struct node *current = root;
    struct node *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (val < current->data) 
            current = current->left;
        else if (val > current->data) 
            current = current->right;
        else {
            printf("Element already exists in the tree\n");
            free(newNode);
            return;
        }
    }
    if (val < parent->data) 
        parent->left = newNode;
    else
        parent->right = newNode;
    printf("Element inserted\n");
}
void searchElement(int val) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    struct node *current = root;
    while (current != NULL) {
        if (current->data == val) {
            printf("Element %d found in the tree\n", val);
            return;
        }
        else if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }
    printf("Element %d not found in the tree\n", val);
}
void displayTree(void) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Tree elements (Inorder Traversal):\n");
    inorderTraversal(root);
    printf("\n");
}
void inorderTraversal(struct node *ptr) {
    if (ptr != NULL) {
        inorderTraversal(ptr->left);
        printf("%d\t", ptr->data);
        inorderTraversal(ptr->right);
    }
}
void deleteElement(int val) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    //finding the node with the element to be delted
    struct node *current = root;
    int found = 0;
    while (current != NULL) {
        if (current->data == val) {
            found = 1;
            break;
        }
        else if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (found!=1) {
        printf("Element %d not found in the tree\n", val);
        return;
    }
    root = deleteHelper(root, val);
    printf("Element %d deleted\n", val);
}
struct node* deleteHelper(struct node *rootNode, int val) {
    //empty tree
    if (rootNode == NULL)
        return NULL;    
    if (val < rootNode->data)
        rootNode->left = deleteHelper(rootNode->left, val);
	else if (val > rootNode->data) 
        rootNode->right = deleteHelper(rootNode->right, val);
	else {
        // Node with only one child or no child
        if (rootNode->left == NULL) {
            struct node *temp = rootNode->right;
            free(rootNode);
            return temp;
        }
        else if (rootNode->right == NULL) {
            struct node *temp = rootNode->left;
            free(rootNode);
            return temp;
        }
        
        struct node *temp = getMinNode(rootNode->right);// Node with two children: Get the inorder successor (smallest in the right subtree)
        rootNode->data = temp->data;					// Copy the inorder successor's content to this node  
        rootNode->right = deleteHelper(rootNode->right, temp->data); // Delete the inorder successor
    }
    return rootNode;
}
struct node* getMinNode(struct node *curr) {
    while (curr!=NULL && curr->left!=NULL) {
        curr = curr->left;
    }
    return curr;
}
```

### Sample Output
```text
  Menu for Binary Search Tree
1.Insert Element
2.Delete Element
3.Search Element
4.Display Tree (Inorder)
5.Exit
Enter Your choice:
1
Enter The element to insert:
50
Element inserted
Enter Your choice: 1
Enter The element to insert: 30
Element inserted
Enter Your choice: 1
Enter The element to insert: 70
Element inserted
Enter Your choice: 3
Enter The element to search:
30
Element 30 found in the tree
Enter Your choice: 4
Tree elements (Inorder Traversal):
30	50	70	
Enter Your choice: 2
Enter The element to delete:
50
Element 50 deleted
Enter Your choice: 5
Exiting Program
```

# Experiment 12: Implementation of tree traversals - inorder, preorder, postorder.

## Program 17: Binary Tree Traversals using iterations (no recursion)

```c
/***************************************************************
 * Program to implement binary search tree in C using struct    *
 * and perform iterative traversals (without recursion)        	 *
 * Author: SOORAJ                                             		 *
 * Date: 10-8-26                                              		 *
 * Version: 3                                                 		 *
 ***************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
// Function prototypes
void insertElement(int val); // Function to insert element into BST iteratively
void Inorder(int n);         // Function to display inorder traversal iteratively
void Preorder(int n);        // Function to display preorder traversal iteratively
void Postorder(int n);       // Function to display postorder traversal iteratively
int main() {
    int n, val;
    printf("Enter the number of elements to insert in the BST:\n");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insertElement(val);
    }
    printf("\nInorder Traversal:\n");
    Inorder(n);
    printf("\nPreorder Traversal:\n");
    Preorder(n);
    printf("\nPostorder Traversal:\n");
    Postorder(n);
    return 0;
}
void insertElement(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (root == NULL) {
        root = newNode;
        return;
    }
    
    struct node *current = root;
    struct node *parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (val < current->data)
            current = current->left;
        else if (val > current->data) 
            current = current->right;
        else {
            printf("Element %d already exists. Skipping.\n", val);
            free(newNode);
            return;
        }
    }
    
    if (val < parent->data) 
        parent->left = newNode;
    else
        parent->right = newNode;
}
void Inorder(int n) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    struct node **stack = (struct node**)malloc(n * sizeof(struct node*));
    int top = -1;
    struct node *current = root;
    
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current; 
            current = current->left;
        }
        current = stack[top--];
        printf("%d\t", current->data);
        current = current->right;
    }
    free(stack);
    printf("\n");
}
void Preorder(int n) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    
    struct node **stack = (struct node**)malloc(n * sizeof(struct node*));
    int top = -1;
    stack[++top] = root;
    
    while (top != -1) {
        struct node *current = stack[top--];
        printf("%d\t", current->data);
        if (current->right)
            stack[++top] = current->right;
        if (current->left) 
            stack[++top] = current->left;
    }
    free(stack);
    printf("\n");
}
void Postorder(int n) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    struct node **stack1 = (struct node**)malloc(n * sizeof(struct node*));
    struct node **stack2 = (struct node**)malloc(n * sizeof(struct node*));
    int top1 = -1, top2 = -1;
    
    stack1[++top1] = root;
    while (top1 != -1) {
        struct node *current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left) 
            stack1[++top1] = current->left;
        if (current->right) 
            stack1[++top1] = current->right;
    }
    while (top2 != -1) 
        printf("%d\t", stack2[top2--]->data);
        
    free(stack1);
    free(stack2);
    printf("\n");
}
```

### Sample Output
```text
Enter the number of elements to insert in the BST:
5
Enter element 1: 50
Enter element 2: 30
Enter element 3: 70
Enter element 4: 20
Enter element 5: 60

Inorder Traversal:
20	30	50	60	70	

Preorder Traversal:
50	30	20	70	60	

Postorder Traversal:
20	30	60	70	50
```

## Program 18: Binary Tree Traversals using recursion

```c
/***************************************************************
 * Program to implement Binary Search Tree in C using struct    *
 * and perform tree traversals using RECURSION                 *
 * Author: SOORAJ                                             		 *
 * Date: 10-8-26                                               		*
 * Version: 5                                                 		 *
 ***************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
// Function Prototypes
void insertElement(int val);
void Inorder(struct node *ptr);
void Preorder(struct node *ptr);
void Postorder(struct node *ptr);
int main() {
    int n, val;
    printf("Enter the number of elements to insert in the BST:\n");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insertElement(val);
    }
    printf("\nInorder Traversal:\n");
    Inorder(root);
    printf("\nPreorder Traversal:\n");
    Preorder(root);
    printf("\nPostorder Traversal:\n");
    Postorder(root);
    return 0;
}
void insertElement(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL) {
        root = newNode;
        return;
    }
    struct node *current = root;
    struct node *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (val < current->data) 
            current = current->left;
        else if (val > current->data)
            current = current->right;
        else {
            printf("Element %d already exists. Skipping.\n", val);
            free(newNode);
            return;
        }
    }
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}
void Inorder(struct node *ptr) {
    if (ptr != NULL) {
        Inorder(ptr->left);
        printf("%d\t", ptr->data);
        Inorder(ptr->right);
    }
}
void Preorder(struct node *ptr) {
    if (ptr != NULL) {
        printf("%d\t", ptr->data);
        Preorder(ptr->left);
        Preorder(ptr->right);
    }
}
void Postorder(struct node *ptr) {
    if (ptr != NULL) {
        Postorder(ptr->left);
        Postorder(ptr->right);
        printf("%d\t", ptr->data);
    }
}
```

### Sample Output
```text
Enter the number of elements to insert in the BST:
5
Enter element 1: 50
Enter element 2: 30
Enter element 3: 70
Enter element 4: 20
Enter element 5: 60

Inorder Traversal:
20	30	50	60	70	

Preorder Traversal:
50	30	20	70	60	

Postorder Traversal:
20	30	60	70	50
```

# Experiment 13: Implementation of sorting algorithms bubble sort, insertion sort and selection sort.

## Program 19: Implementation of bubble sort algorithm

```c
/***************************************************************
 * Program to implement bubblesort in and array in C           *
 * Author: SOORAJ                                              		*
 * Date: 12-10-26                                               		*
 * Version: 1                                                  		*		
 ***************************************************************/
#include <stdio.h>
void bubblesort(int arr[], int n) {
    int temp=0;
    int flag=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break; //no swap - fully sorted
     }
}               
int main() {
    int n, i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### Sample Output
```text
Enter no. of elements: 5
Enter 5 elements: 42 15 8 30 5
Sorted Array: 5 8 15 30 42
```

## Program 20: Implementation of insertion sort algorithm

```c
/***************************************************************
 * Program to implement insertion sort in and array in C       *
 * Author: SOORAJ                                              *
 * Date: 12-10-26                                               *
 * Version: 1                                                  *
 ***************************************************************/
#include <stdio.h>
void insertionsort(int arr[], int n) {
    int key;
    for(int i=0; i<n;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}         
int main() {
    int n, i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionsort(arr, n);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### Sample Output
```text
Enter no. of elements: 5
Enter 5 elements: 42 15 8 30 5
Sorted Array: 5 8 15 30 42
```

## Program 21: Implementation of selection sort algorithm

```c
/********************************0*******************************
 * Program to implement selection sort in and array in C     	  *
 * Author: SOORAJ                                             			 *
 * Date: 12-10-26                                             			 *
 * Version: 1                                                  			*
 ***************************************************************/
#include <stdio.h>
void selection_sort(int arr[], int n) {
    int temp, min_i;
    for(int i=0;i<n-1;i++){
        min_i=i;
        for(int j=i+1;j<n;j++)
            if(arr[min_i]>arr[j])
                min_i=j;
        if(min_i!=i){
            temp=arr[i];
            arr[i]=arr[min_i];
            arr[min_i]=temp;
        }    
    }
}               
int main() {
    int n, i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### Sample Output
```text
Enter no. of elements: 5
Enter 5 elements: 42 16 8 30 5
Sorted Array: 5 8 16 30 42
```

# Experiment 14: Implementation of Merge sort.

## Program 22: Implementation of Merge sort in an array in C

```c
/***************************************************************
 * Program to implement mergesort in and array in C            *
 * Author: SOORAJ                                             		 *
 * Date: 12-10-26                                             		  *
 * Version: 1                                                  		*
 ***************************************************************/
#include <stdio.h>
void merge(int arr[], int low, int mid, int high) {
    int i=low, j=mid+1, k=0;
    int temp[high-low+1];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=high)
        temp[k++]=arr[j++];
    for(i=low, k=0; i<=high; i++, k++)
        arr[i]=temp[k];
}
void mergesort(int arr[], int low, int high) {
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
int main() {
    int n, i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### Sample Output
```text
Enter no. of elements: 5
Enter 5 elements: 45 15 8 30 5
Sorted Array: 5 8 15 30 45
```

# Experiment 15: Implementation of Quick sort.

## Program 23: Implementation of Quick sort in an array in C

```c
/***************************************************************
 * Program to implement quicksort in an array in C             *
 * Author: SOORAJ                                              *
 * Date: 12-10-26                                               *
 * Version: 1                                                  *
 ***************************************************************/
#include <stdio.h>
int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=low-1;
    int temp=0;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
void quicksort(int arr[], int low, int high) {
    if(low<high){
        int i=partition(arr, low, high);
        quicksort(arr, low, i-1);
        quicksort(arr, i+1, high);
    }
}
int main() {
    int n, i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### Sample Output
```text
Enter no. of elements: 5
Enter 5 elements: 42 15 8 33 5
Sorted Array: 5 8 15 33 42
```

# Experiment 16: Implementation of BFS and DFS on graph.

## Program 24: Implementation of BFS and DFS on graph using adjacency matrix in C

```c
/*************************************************************************************
 * Program to implement BFS and DFS on graph using adjacency matrix in C             *
 * Author: SOORAJ                                              					  *
 * Date: 18-10-26                                              					 *
 * Version: 1                                                  					*
 **********************************************************************************/
#include <stdio.h>
#define max 50
int vertex[max];
int adj[max][max];
int find(int n, int x);             //check if the vertex is present in the list of vertices and return its index, else return -1
void display(int n);                //display the adjacency matrix of the graph
void bfs(int n, int s);             //perform bfs on the graph starting from vertex s
void dfs(int n, int x, int seen[]); //perform dfs on the graph starting from vertex x, using the seen array to track visited vertices
int main(void) {
    int n, m, a, b;
    //n is number of vertices, m is number of edges, a and b are the two vertices of an edge
    printf("Maximum Number of vertices: %d\n Enter the number of vertices: ", max);
    scanf("%d", &n);
    if ( n < 1 || n > max) {
        printf("Error: invalid number of vertices\n");
        return 1;
    }
    //initialize the adjacency matrix to 0
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        adj[i][j] = 0;
    }
}
    printf("Enter the vertex labels:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        if (scanf("%d", &vertex[i]) != 1) {
            printf("Error: invalid vertex label\n");
            return 1;
        }
        for (int j = 0; j < i; j++) {
            if (vertex[i] == vertex[j]) {
                printf("Error: vertex labels must be unique\n");
                return 1;
            }
        }
    }
    printf("Enter Number of edges: ");
    scanf("%d", &m);
    if (m < 0||m> n*(n-1)/2) {
        printf("Error: invalid number of edges\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        printf("Edge: %d \n", i + 1);
        printf("Enter the vertex 1: ");
        scanf("%d", &a);
        printf("Enter the vertex 2: ");
        scanf("%d", &b);
        int x = find(n, a);
        int y = find(n, b);
        if (x == -1 || y == -1 || x == y) {
            printf("Error: enter two different listed vertices\n");
            return 1;
        }
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    printf("Adjacency Matrix:\n\t");
    //show the adjacency matrix
    display(n);
    //show the BFS
    bfs(n, 0);
    
    //show the DFS
    int seen[max] = {0};
    printf("DFS: ");
    dfs(n, 0, seen);
    printf("\n");
    return 0;
}
int find(int n, int x) {
    for (int i = 0; i < n; i++)
        if (vertex[i] == x)
            return i;
    return -1;
}
void display(int n) {
    for (int i = 0; i < n; i++)
        printf("%d\t", vertex[i]);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", vertex[i]);
        for (int j = 0; j < n; j++)
            printf("%d\t", adj[i][j]);
        printf("\n");
    }
}
void bfs(int n, int s) {
    int queue[max], seen[max] = {0};
    int front = 0, back = 0;
    queue[back++] = s;
    seen[s] = 1;
    printf("BFS: ");
    while (front < back) {
        int x = queue[front++];
        printf("%d ", vertex[x]);
        for (int i = 0; i < n; i++) {
            if (adj[x][i] && !seen[i]) {
                queue[back++] = i;
                seen[i] = 1;
            }
        }
    }
    printf("\n");
}
void dfs(int n, int x, int seen[]) {
    seen[x] = 1;
    printf("%d ", vertex[x]);
    for (int i = 0; i < n; i++)
        if (adj[x][i] && !seen[i])
            dfs(n, i, seen);
}
```

### Sample Output
```text
Maximum Number of vertices: 50
Enter the number of vertices: 8
Enter the vertex labels:
Vertex 1: 1
Vertex 2: 2
Vertex 3: 3
Vertex 4: 4
Vertex 5: 5
Vertex 6: 6
Vertex 7: 7
Vertex 8: 8
Enter Number of edges: 10
Edge: 1 
Enter the vertex 1: 1
Enter the vertex 2: 3
Edge: 2 
Enter the vertex 1: 2
Enter the vertex 2: 5
Edge: 3 
Enter the vertex 1: 6
Enter the vertex 2: 7
Edge: 4 
Enter the vertex 1: 8
Enter the vertex 2: 4
Edge: 5 
Enter the vertex 1: 5
Enter the vertex 2: 3
Edge: 6 
Enter the vertex 1: 1
Enter the vertex 2: 5
Edge: 7 
Enter the vertex 1: 7
Enter the vertex 2: 5
Edge: 8 
Enter the vertex 1: 8
Enter the vertex 2: 1
Edge: 9 
Enter the vertex 1: 4
Enter the vertex 2: 2
Edge: 10 
Enter the vertex 1: 6
Enter the vertex 2: 5
Adjacency Matrix:
	1	2	3	4	5	6	7	8
1	0	0	1	0	1	0	0	1
2	0	0	0	1	1	0	0	0
3	1	0	0	0	1	0	0	0
4	0	1	0	0	0	0	0	1
5	1	1	1	0	0	1	1	0
6	0	0	0	0	1	0	1	0
7	0	0	0	0	1	1	0	0
8	1	0	0	1	0	0	0	0
BFS: 1 3 5 8 2 6 7 4 
DFS: 1 3 5 2 4 8 6 7 
```

# Experiment 17: Implementation of hash table using your own mapping functions and observe collisions and overflow resolving schemes.

## Program 25: Implementation of hash table using linear probing to handle collisions using arrays

```c
/************************************************************************************
 * Program to implement hash table using linear probing using arrays  in C                  *
 * Author: SOORAJ                                              					  *
 * Date: 18-10-26                                              					  *
 * Version: 1                                                  					  *
 ************************************************************************************/
#include <stdio.h>
#define max 10
int hashtable[max];
void insert(int key);               //insert key into the hash table using linear probing
void display(void);                 //display the hash table contents
int search(int key);                //search for key in the hash table and return its index, else return -1
int main() {
    int choice=0, key, index;
    //initialize the hash table slots to -1 (indicating empty)
    for (int i = 0; i < max; i++) {
        hashtable[i] = -1;
    }
    while (choice != 4) {
        printf("\n--- MENU ---\n");
        printf("1. Input (Insert)\n");
        printf("2. Display\n");
        printf("3. Search for element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = search(key);
                if (index != -1)
                    printf("Element %d found at index %d\n", key, index);
                else
                    printf("Element %d not found\n", key);
                break;
            case 4:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Error: invalid choice\n");
        }
    }
    return 0;
}
void insert(int key) {
    int index = key % 10; // Hash function: h(k)=k mod 10
    int start = index;
    while (hashtable[index] != -1) {
        // If element is already present
        if (hashtable[index] == key) {
            printf("Error: key %d already exists\n", key);
            return;
        }
        index = (index + 1) % max;
        // Table is full
        if (index == start) {
            printf("Error: Hash table is full\n");
            return;
        }
    }
    hashtable[index] = key;
    printf("Key %d inserted successfully at index %d\n", key, index);
}
void display(void) {
    printf("Index\tKey\n");
    for (int i = 0; i < max; i++) {
        if (hashtable[i] != -1)
            printf("%d\t%d\n", i, hashtable[i]);
        else
            printf("%d\t~\n", i);
    }
}
int search(int key) {
    // Hash function: h(k)=k mod 10
    int index = key % 10;
    int start = index;
    while (hashtable[index] != -1) {
        if (hashtable[index] == key)
            return index;
        index = (index + 1) % max;
        if (index == start)
            break;
    }
    return -1;
}
```

### Sample Output
```text
--- MENU ---
1. Input (Insert)
2. Display
3. Search for element
4. Exit
Enter your choice: 1
Enter key to insert: 21
Key 21 inserted successfully at index 1

Enter your choice: 1
Enter key to insert: 35
Key 35 inserted successfully at index 5

Enter your choice: 1
Enter key to insert: 75
Key 75 inserted successfully at index 6

Enter your choice: 1
Enter key to insert: 68
Key 68 inserted successfully at index 8

Enter your choice: 1
Enter key to insert: 48
Key 48 inserted successfully at index 9

Enter your choice: 1
Enter key to insert: 25
Key 25 inserted successfully at index 7

Enter your choice: 1
Enter key to insert: 96
Key 96 inserted successfully at index 0

Enter your choice: 1
Enter key to insert: 10
Key 10 inserted successfully at index 2

Enter your choice: 1
Enter key to insert: 24
Key 24 inserted successfully at index 4

Enter your choice: 1
Enter key to insert: 75
Error: key 75 already exists

Enter your choice: 1
Enter key to insert: 36
Key 36 inserted successfully at index 3

Enter your choice: 1
Enter key to insert: 42
Error: Hash table is full

Enter your choice: 2
Index	Key
0	96
1	21
2	10
3	36
4	24
5	35
6	75
7	25
8	68
9	48

Enter your choice: 3
Enter key to search: 15
Element 15 not found

Enter your choice: 4
Exiting program
```

## Program 26: Implementation of hash table using separate chaining to handle collisions using linked lists

```c
/*******************************************************************
 * Program to implement chaining in hashing using linked list  	 *
 * Author: SOORAJ                                              			*
 * Date: 12-10-26                                              			*
 * Version: 1                                                  			*
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define max 10
struct node {
    int data;
    struct node *next;
};
struct node *hashtable[max]; // Array of linked list head pointers
// function prototypes
void insert(int key);               //inserts key into the hash table chain
void display(void);                 //displays the hash table chains
void search(int key);                //searches for key in the hash table chain
int main(void) {
    int choice = -1, key;
    // initialize table heads to NULL
    for (int i = 0; i < 10; i++) 
        hashtable[i] = NULL;
    while (choice != 4) {
        printf("Menu for Hash Table Chaining\n");
        printf("1.Input (Insert)\n2.Display\n3.Search for element\n4.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert:\n");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter key to search:\n");
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
void insert(int key) {
    int index = key % 10;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = NULL;
    if (hashtable[index] == NULL) 
        hashtable[index] = newNode;
    else {
        struct node *current = hashtable[index];
        while (current->next != NULL) {
            if (current->data == key) {
                printf("Error: key %d already exists in chain\n", key);
                free(newNode);
                return;
            }
            current = current->next;
        }
        if (current->data == key) {
            printf("Error: key %d already exists in chain\n", key);
            free(newNode);
            return;
        }
        current->next = newNode;
    }
    printf("Key %d inserted successfully at index %d\n", key, index);
}
void display(void) {
    printf("Index\tChain\n");
    for (int i = 0; i < 10; i++) {
        printf("[%d]\t", i);
        if (hashtable[i] == NULL)
            printf("NULL\n");
        else {
            struct node *current = hashtable[i];
            while (current != NULL) {
                printf("%d -> ", current->data);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}
void search(int key) {
    int index = key % 10;
    struct node *current = hashtable[index];
    int pos = 1;
    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found at index %d at position %d in chain\n", key, index, pos);
            return;
        }
        current = current->next;
        pos++;
    }
    printf("Element %d not found in the hash table\n", key);
}
```

### Sample Output
```text
Menu for Hash Table Chaining
1.Input (Insert)
2.Display
3.Search for element
4.Exit
Enter Your choice: 1
Enter key to insert: 21
Key 21 inserted successfully at index 1

Enter Your choice: 1
Enter key to insert: 42
Key 42 inserted successfully at index 2

Enter Your choice: 1
Enter key to insert: 52
Key 52 inserted successfully at index 2

Enter Your choice: 1
Enter key to insert: 36
Key 36 inserted successfully at index 6

Enter Your choice: 1
Enter key to insert: 75
Key 75 inserted successfully at index 5

Enter Your choice: 148
Wrong choice

Enter Your choice: 1
Enter key to insert: 96
Key 96 inserted successfully at index 6

Enter Your choice: 1
Enter key to insert: 10
Key 10 inserted successfully at index 0

Enter Your choice: 1
Enter key to insert: 30
Key 30 inserted successfully at index 0

Enter Your choice: 1
Enter key to insert: 45
Key 45 inserted successfully at index 5

Enter Your choice: 1
Enter key to insert: 85
Key 85 inserted successfully at index 5

Enter Your choice: 1
Enter key to insert: 49
Key 49 inserted successfully at index 9

Enter Your choice: 1
Enter key to insert: 21
Error: key 21 already exists in chain

Enter Your choice: 1
Enter key to insert: 11
Key 11 inserted successfully at index 1

Enter Your choice: 1
Enter key to insert: 38
Key 38 inserted successfully at index 8

Enter Your choice: 1
Enter key to insert: 39
Key 39 inserted successfully at index 9

Enter Your choice: 1
Enter key to insert: 38
Error: key 38 already exists in chain

Enter Your choice: 1
Enter key to insert: 27
Key 27 inserted successfully at index 7

Enter Your choice: 2
Index	Chain
[0]	10 -> 30 -> NULL
[1]	21 -> 11 -> NULL
[2]	42 -> 52 -> NULL
[3]	NULL
[4]	NULL
[5]	75 -> 45 -> 85 -> NULL
[6]	36 -> 96 -> NULL
[7]	27 -> NULL
[8]	38 -> NULL
[9]	49 -> 39 -> NULL

Enter Your choice: 3
Enter key to search: 85
Element 85 found at index 5 at position 3 in chain

Enter Your choice: 4
Exiting Program
```
