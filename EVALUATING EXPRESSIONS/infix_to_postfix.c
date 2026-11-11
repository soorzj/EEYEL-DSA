
/***************************************************************
* Program to implement infix to postfix as an stack in C       *
* Author: SOORAJ                                               *
* Date: 10-8-26                                                 *
* Version: 2                                                   *
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

char infix[MAX];
char symbol[MAX];
int topSymbol = -1;

/* function prototypes */
void pushSymbol(char value);    //Checks if the stack is full and pushes the symbols
char popSymbol(void);           //checks if the stack is emplty and pops out the last symbol
char peekSymbol(void);          //checks if the stack is emplty and just displays the last symbol
void print_stack(void);         //prints the stack until the end or a bracket is reached
int priority(char c);           //returns a numeric code for the priority of the passed symbol
int isSymbol(char c);           //return 1 if symbol else 0
int isEmpty(void);              //return 1 is stack empty else 0
int isSpace(char c);            //return 1 if c is whitespace els 0
int isDigit(char c);            //return 1 if c is a digit else 0

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
