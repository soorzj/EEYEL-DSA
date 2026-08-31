
/****************************************************************
 * Program : Postfix Expression Evaluation Using Stack
 * Version : 3
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program evaluates a postfix expression using a stack.
 * The input expression must contain operands and operators
 * separated by spaces. Each operand is pushed onto the stack,
 * while an operator removes the required operands, performs
 * the operation and pushes the result back onto the stack.
 * sooraj worked hard to implement this properly
 *
 * Input Format:
 * Operands and operators must be separated by spaces.
 * Example: 12 5 + 3 *
 *
 * Operations:
 * 1. Read Expression   - Read the postfix expression
 * 2. Process Operands  - Push each operand onto the stack
 * 3. Process Operators - Perform operations using stack values
 * 4. Display Result    - Display the final result
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Array used to store the postfix expression entered by the user.
char postfix[MAX];

// Array used as a stack for storing operands and intermediate results.
int value[MAX];

// topValue stores the index of the value currently at the top of the stack.
int topValue = -1;


// Function prototypes for stack operations and expression evaluation.
void pushValue(int number);                                  // Checks if the stack is full and pushes a value.
int popValue(void);                                          // Checks if the stack is empty and removes the top value.
int peekValue(void);                                         // Checks if the stack is empty and returns the top value.
void print_stack(void);                                      // Displays the stack from top to bottom.
int isOperator(char symbol);                                 // Identifies whether a character is an operator.
int isEmpty(void);                                           // Checks whether the stack is empty.
int operation(int operand1, int operand2, char operator);     // Performs the specified arithmetic operation.
int isSpace(char symbol);                                    // Identifies whitespace characters.
int isDigit(char symbol);                                    // Identifies numeric digits.


int main()
{
    // Read the complete postfix expression with operands and operators separated by spaces.
    printf("Enter the postfix expression with whitespace: ");
    fgets(postfix, MAX, stdin);

    // i represents the current character position being processed in the postfix expression.
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char currentSymbol = postfix[i];

        // Ignore spaces, tabs and the newline character from the input expression.
        if (isSpace(currentSymbol))
            continue;

        // Consecutive digits are combined to form one complete integer operand.
        if (isDigit(currentSymbol))
        {
            int number = 0;

            // Continue reading digits and construct the complete operand.
            while (isDigit(postfix[i]))
            {
                // Convert the current digit character into its integer value.
                number = number * 10 + (postfix[i] - '0');
                i++;
            }

            // Push the complete operand onto the value stack.
            pushValue(number);

            // Move back one position because the for loop will increment i again.
            i--;
        }

        // Process the current character as an operator.
        else if (isOperator(currentSymbol))
        {
            // The second operand is removed first because the stack follows LIFO order.
            int operand2 = popValue();

            // The first operand is removed after the second operand.
            int operand1 = popValue();

            // Perform the operation and push the result back onto the stack.
            pushValue(operation(operand1, operand2, currentSymbol));
        }
    }

    // The final value remaining in the stack is the result of the postfix expression.
    printf("Result: %d\n", popValue());

    return 0;
}


// Push an integer value onto the top of the stack.
void pushValue(int number)
{
    // Prevent insertion when the stack has reached its maximum capacity.
    if (topValue == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        // Move the top position upward and store the new value.
        topValue++;
        value[topValue] = number;
    }
}


// Remove and return the integer value currently at the top of the stack.
int popValue()
{
    // Return -1 when the stack contains no values.
    if (topValue == -1)
        return -1;

    // Return the top value and move the top position down by one.
    return value[topValue--];
}


// Return the top value without removing it from the stack.
int peekValue()
{
    // Return -1 when the stack contains no values.
    if (topValue == -1)
        return -1;

    // Return the value currently at the top of the stack.
    return value[topValue];
}


// Identify whether a character is one of the supported arithmetic operators.
int isOperator(char symbol)
{
    switch (symbol)
    {
        // Supported arithmetic operators.
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;

        // Any other character is not considered an operator.
        default:
            return 0;
    }
}


// Perform the required arithmetic operation on the two operands.
int operation(int operand1, int operand2, char operator)
{
    switch (operator)
    {
        // Add the two operands.
        case '+':
            return operand1 + operand2;

        // Subtract the second operand from the first operand.
        case '-':
            return operand1 - operand2;

        // Multiply the two operands.
        case '*':
            return operand1 * operand2;

        // Divide the first operand by the second operand.
        case '/':
            return operand1 / operand2;

        // Calculate operand1 raised to the power of operand2.
        case '^':
        {
            int result = 1;

            // i represents the number of multiplication repetitions.
            for (int i = 0; i < operand2; i++)
                result = result * operand1;

            return result;
        }

        // Return zero for an unsupported operator.
        default:
            return 0;
    }
}


// Identify whether a character is a whitespace character.
int isSpace(char symbol)
{
    // Spaces, tabs and newlines are ignored while processing the expression.
    if (symbol == ' ' || symbol == '\n' || symbol == '\t')
        return 1;

    return 0;
}


// Identify whether a character is a numeric digit.
int isDigit(char symbol)
{
    // Characters from 0 through 9 are considered digits.
    if (symbol >= '0' && symbol <= '9')
        return 1;

    return 0;
}


// Check whether the value stack currently contains no elements.
int isEmpty()
{
    // topValue remains -1 whenever the stack is empty.
    if (topValue == -1)
        return 1;

    return 0;
}


// Display all values currently stored in the stack from top to bottom.
void print_stack()
{
    // Do not attempt to display anything when the stack is empty.
    if (isEmpty())
    {
        printf("Stack Empty\n");
        return;
    }

    // i represents the current stack position while traversing from top to bottom.
    for (int i = topValue; i >= 0; i--)
        printf("%d\n", value[i]);
}
