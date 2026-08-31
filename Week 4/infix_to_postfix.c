
/***************************************************************
 * Program : Infix to Postfix Conversion Using Stack
 * Version : 3
 * Date    : 31-08-2026
 * Author  : Sooraj
 *
 * Description:
 * This program converts an infix expression into its
 * equivalent postfix expression using a stack.
 * Operands are directly added to the postfix expression,
 * while operators are temporarily stored in the stack
 * according to their precedence.
 *
 * Operations:
 * 1. Read Expression    - Read the infix expression from the user
 * 2. Process Operands   - Add operands directly to the output
 * 3. Process Operators  - Use the stack according to precedence
 * 4. Process Brackets   - Handle opening and closing brackets
 * 5. Display Postfix    - Display the converted expression
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Array used to store the input infix expression.
char infix[MAX];

// Array used as a stack for temporarily storing operators and brackets.
char symbol[MAX];

// topSymbol stores the index of the operator currently at the top of the stack.
int topSymbol = -1;


// Function prototypes for stack operations and expression processing.
void pushSymbol(char value);    // Checks if the stack is full and pushes a symbol.
char popSymbol(void);           // Checks if the stack is empty and removes the top symbol.
char peekSymbol(void);          // Checks if the stack is empty and returns the top symbol.
void print_stack(void);         // Displays the contents of the symbol stack.
int priority(char symbol);      // Returns the precedence value of an operator.
int isSymbol(char symbol);      // Identifies operators and brackets.
int isEmpty(void);              // Checks whether the stack is empty.
int isSpace(char symbol);       // Identifies whitespace characters.
int isDigit(char symbol);       // Identifies numeric digits.


int main()
{
    // Read the complete infix expression from the user.
    printf("Enter the expression: ");
    fgets(infix, MAX, stdin);

    printf("Postfix Expression: ");

    // i represents the current character position being processed in the infix expression.
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char currentSymbol = infix[i];

        // Ignore spaces, tabs and the newline character from the input expression.
        if (isSpace(currentSymbol))
            continue;

        // Consecutive digits are treated as one complete number.
        if (isDigit(currentSymbol))
        {
            // Continue reading digits until a non-digit character is encountered.
            while (isDigit(infix[i]))
            {
                printf("%c", infix[i]);
                i++;
            }

            // Add a space after the complete number to separate it from the next operand.
            printf(" ");

            // Move back one position because the for loop will increment i again.
            i--;
        }

        // Any character that is not an operator or bracket is treated as an operand.
        else if (isSymbol(currentSymbol) == 0)
        {
            printf("%c ", currentSymbol);
        }

        // An opening bracket is pushed onto the stack for later processing.
        else if (currentSymbol == '(')
        {
            pushSymbol(currentSymbol);
        }

        // A closing bracket causes operators to be popped until the matching opening bracket.
        else if (currentSymbol == ')')
        {
            // Pop all operators belonging to the expression inside the brackets.
            while (!isEmpty() && peekSymbol() != '(')
                printf("%c ", popSymbol());

            // Remove the matching opening bracket from the stack.
            if (!isEmpty() && peekSymbol() == '(')
                popSymbol();
        }

        // Process an operator according to its precedence.
        else
        {
            // Remove operators with greater or equal precedence before pushing the current operator.
            while (!isEmpty() &&
                   peekSymbol() != '(' &&
                   priority(peekSymbol()) >= priority(currentSymbol))
            {
                printf("%c ", popSymbol());
            }

            // Store the current operator in the stack.
            pushSymbol(currentSymbol);
        }
    }

    // Pop all remaining operators after the entire infix expression has been processed.
    while (!isEmpty())
        printf("%c ", popSymbol());

    printf("\n");

    return 0;
}


// Push a symbol onto the top of the operator stack.
void pushSymbol(char value)
{
    // Prevent insertion when the stack has reached its maximum capacity.
    if (topSymbol == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        // Move the top position upward and store the new symbol.
        topSymbol++;
        symbol[topSymbol] = value;
    }
}


// Remove and return the symbol currently at the top of the stack.
char popSymbol()
{
    // Return -1 when there is no symbol available to remove.
    if (topSymbol == -1)
        return -1;

    // Return the top symbol and move the top position down by one.
    return symbol[topSymbol--];
}


// Return the top symbol without removing it from the stack.
char peekSymbol()
{
    // Return -1 when the stack contains no symbols.
    if (topSymbol == -1)
        return -1;

    // Return the symbol currently at the top of the stack.
    return symbol[topSymbol];
}


// Return the precedence level associated with each supported operator.
int priority(char symbol)
{
    switch (symbol)
    {
        // Addition and subtraction have the lowest operator precedence.
        case '+':
        case '-':
            return 1;

        // Multiplication and division have higher precedence than addition and subtraction.
        case '*':
        case '/':
            return 2;

        // Exponentiation has the highest precedence among the supported operators.
        case '^':
            return 3;

        // Return zero for characters that are not operators.
        default:
            return 0;
    }
}


// Identify whether a character is a whitespace character.
int isSpace(char symbol)
{
    // Spaces, newlines and tabs are ignored while processing the expression.
    if (symbol == ' ' || symbol == '\n' || symbol == '\t')
        return 1;

    return 0;
}


// Identify whether a character is a numeric digit.
int isDigit(char symbol)
{
    // Digits from 0 through 9 are considered valid numeric characters.
    if (symbol >= '0' && symbol <= '9')
        return 1;

    return 0;
}


// Identify whether a character is an operator or bracket.
int isSymbol(char symbol)
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

        // Opening and closing brackets are also handled specially during conversion.
        case '(':
        case ')':
            return 2;

        // Any other character is treated as an operand.
        default:
            return 0;
    }
}


// Check whether the operator stack currently contains no symbols.
int isEmpty()
{
    // topSymbol remains -1 whenever the stack contains no elements.
    if (topSymbol == -1)
        return 1;

    return 0;
}


// Display all symbols currently stored in the stack from top to bottom.
void print_stack()
{
    // Do not attempt to display anything when the stack is empty.
    if (isEmpty())
    {
        printf("Stack Empty\n");
        return;
    }

    // i represents the current stack position while traversing from top to bottom.
    for (int i = topSymbol; i >= 0; i--)
        printf("%c ", symbol[i]);
}
