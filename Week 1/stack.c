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
