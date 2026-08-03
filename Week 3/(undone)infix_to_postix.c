/************************************************************
 * Program to implement infix to postfix as an stack in C	*
 * Author: SOORAJ											*
 * Date: 3-8-26												*
 * Version: 1												*
 ************************************************************/

#include <stdio.h>
#include <stdlib.h>
int MAX =50;
char infix[MAX];
char symbol[MAX];
int topInfix = -1, topSymbol=-1;

/* function prototypes */
void push(char value);
char popInfix(void);
char popsymbol(void);
void print_stack(void);
int isEmpty(void);

int main()
{
	printf("Enter the expression without whitespace");
	scanf("%s",infix);
	
	
	char x=popInfix();
	
	
	
	
	if(char[i]=='\0'){
		char remain=popSymbol();
		while (remain!=-1){
			printf("%c",remain);
			remain=pop();
			}
		}
}


void pushSymbol(char value)
{
	if (topSymbol == MAX - 1)
		printf("Stack Overflow\n");
	else
	{
		topSymbol++;
		symbol[topSymbol] = value;
	}
}

void pushInfix(char value)
{
	if (topInfix == MAX - 1)
		printf("Stack Overflow\n");
	else
	{
		topInfix++;
		symbol[topInfix] = value;
	}
}

char popInfix()
{
	if (topInfix==-1)
	{
		return -1;
	}
	else
		return infix[topInfix--];
}

char popSymbol()
{
	if (topSymbol==-1)
	{
		return -1;
	}
	else
		return symbol[topSymbol--];
}

int priority(char c){
	switch(c){
		case '+': case'-':
			return 1;
		case '*': case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
		}
	}

int isSymbol(char c)
	switch(c){
		case '+': case'-': case '*': case '/': case '^':
			return 1;
		case '(': case ')':
			return 2;
		default: 
			return 0;
		}
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


