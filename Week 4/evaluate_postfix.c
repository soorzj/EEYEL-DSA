/****************************************************************
* Program to evaluate a postfix expression using stack in C	    *
* Author: SOORAJ					                        	*
* Date: 10-8-26						                            *
* Version: 2						                            *
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

char postfix[MAX];
int value[MAX];
int topValue = -1;

/* function prototypes */
void pushValue(int value);     // Checks if the stack is full and pushes the value
int popValue(void);            // Checks if the stack is empty and pops out the last value
int peekValue(void);           // Checks if the stack is empty and displays the last value
void print_stack(void);        // Prints the stack from top to bottom
int isOperator(char c);        // Returns 1 if operator else 0
int isEmpty(void);             // Returns 1 if stack empty else 0
int operation(int a, int b, char op);  // Performs the given operation

int main(){
	printf("Enter the postfix expression without whitespace: ");
	scanf("%s", postfix);

	for (int i = 0; postfix[i] != '\0'; i++)
	{
		char ch = postfix[i];
		if (ch >= '0' && ch <= '9')
			pushValue(ch - '0'); //deduct the asci value of 0 from the integer character asci to get the integer value
		else if (isOperator(ch) == 1)
		{
			int b = popValue();
			int a = popValue();
			pushValue(operation(a, b, ch));
		}
	}
	printf("Result: %d\n", popValue());
	return 0;
}

void pushValue(int val){
	if (topValue == MAX - 1)
		printf("Stack Overflow\n");
	else
	{
		topValue++;
	    value[topValue] = val;
	}
}

int popValue(){
	if (topValue == -1)
		return -1;
	else
		return value[topValue--];
}

int peekValue(){
	if (topValue == -1)
		return -1;
	else
		return value[topValue];
}

int isOperator(char c){
	switch (c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return 1;

		default:
			return 0;
	}
}

int operation(int a, int b, char op){
	switch (op)
	{
		case '+':
			return a + b;

		case '-':
			return a - b;

		case '*':
			return a * b;

		case '/':
			return a / b;

		case '^':
		{
			int result = 1;

			for (int i = 0; i < b; i++)
				result = result * a;

			return result;
		}

		default:
			return 0;
	}
}

int isEmpty(){
	if (topValue == -1)
		return 1;
	else
		return 0;
}

void print_stack(){
	if (isEmpty() == 1)
	{
		printf("Stack Empty\n");
		return;
	}

	for (int i = topValue; i >= 0; --i)
		printf("%d\n", value[i]);
}
