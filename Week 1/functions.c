/*
 * functions.c
 * Function definitions for the array-based queue implementation
 * Author: SOORAJ
 * Date: 6-7-26
 * Version: 1
 */

#include <stdio.h>

#define MAX 10
extern int queue[MAX];
extern int front, back;

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
		return (queue[back]);
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
	else if (front==back==-1)
		return 1;
	else
		return 0;
	}
	
int isFull(){
	if(back==MAX)
		return 1;
	else
		return 0;
	}
