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
int top = -1;

void push_operand(int number);                                  // Checks if the stack is full and pushes a value.
int pop_operand(void);                                          // Checks if the stack is empty and removes the top value.
int isOperator(char symbol);                                 // Identifies whether a character is an operator.
int operation(int operand1, int operand2, char operator);     // Performs the specified arithmetic operation.
int isSpace(char symbol);                                    // Identifies whitespace characters.
int isDigit(char symbol);                                    // Identifies numeric digits.
int main()
{
    printf("Enter the postfix expression with whitespace: ");
    fgets(postfix, MAX, stdin);
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char x = postfix[i];
        if (isSpace(x))
            continue; //skip space
        if (isDigit(x))
        {
            int number = 0;
            while (isDigit(postfix[i])) //go on till the continous digits are exausted and combine them to get a single number
            {
                number = number * 10 + (postfix[i] - '0'); //previous digit x 10 + the nextdigit .... and so on 
                i++;
            }
            push_operand(number); //push operand to stack
            i--;
        }
        else if (isOperator(x))
        {
            int operand2 = pop_operand();
            int operand1 = pop_operand();
            push_operand(operation(operand1, operand2, x)); //take the last 2 operands, do the operation and push back to stack
        }
    }
    printf("Result: %d\n", pop_operand());
    return 0;
}

void push_operand(int number){
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        value[top] = number;
    }
}

int pop_operand(){
    if (top == -1)
        return -1;
    return value[top--];
}

int isOperator(char symbol){
    switch (symbol)
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

int operation(int operand1, int operand2, char operator){
    switch (operator)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
        {
            int result = 1;
            for (int i = 0; i < operand2; i++)
                result = result * operand1;

            return result;
        }
        default:
            return 0;
    }
}

int isSpace(char symbol){
    if (symbol == ' ' || symbol == '\n' || symbol == '\t')
        return 1;

    return 0;
}

int isDigit(char symbol){
    if (symbol >= '0' && symbol <= '9')
        return 1;

    return 0;
}

