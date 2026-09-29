/***************************************************************
* Program to multiply two polynomials using singly linked list*
*                                                             *
* Author  : SOORAJ                                            *
* Date    : 10-8-26                                           *
* Version : 3                                                 *
*                                                             *
* Description:                                                 *
* This program represents two polynomials using singly linked *
* lists and multiplies them to obtain a resultant polynomial.  *
*                                                             *
* Each node of the linked list represents one term of a       *
* polynomial and contains the coefficient, exponent and       *
* pointer to the next term.                                   *
*                                                             *
* The polynomial terms are stored in descending order of      *
* their exponents. Zero coefficient terms are not stored.     *
*                                                             *
* The program performs the following operations:              *
* 1. Accept the coefficients of the first polynomial          *
* 2. Accept the coefficients of the second polynomial         *
* 3. Store both polynomials using singly linked lists         *
* 4. Multiply every term of the first polynomial with every    *
*    term of the second polynomial                             *
* 5. Combine terms having the same exponent                   *
* 6. Display the resultant polynomial                          *
***************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;              // Stores the coefficient of the term
    int exp;                // Stores the exponent of the term
    struct node *next;      // Points to the next term
};

struct node *poly1 = NULL;
struct node *poly2 = NULL;
struct node *result = NULL;

// Function prototypes
void insertBack(int c, int e, struct node **headRef);
void insertSorted(int c, int e);
void displayList(struct node *head);
void multiplyPolynomials(void);

int main(void)
{
    int deg1, deg2, i, coeff;

    // Read the first polynomial
    printf("Enter the highest degree of first polynomial: ");
    scanf("%d", &deg1);

    printf("Enter coefficients from x^%d to constant:\n", deg1);

    for (i = deg1; i >= 0; i--)
    {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff);

        // Ignore terms having zero coefficient
        if (coeff != 0)
            insertBack(coeff, i, &poly1);
    }

    printf("\nFirst polynomial entered: ");
    displayList(poly1);

    // Read the second polynomial
    printf("\nEnter the highest degree of second polynomial: ");
    scanf("%d", &deg2);

    printf("Enter coefficients from x^%d to constant:\n", deg2);

    for (i = deg2; i >= 0; i--)
    {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff);

        // Ignore terms having zero coefficient
        if (coeff != 0)
            insertBack(coeff, i, &poly2);
    }

    printf("\nSecond polynomial entered: ");
    displayList(poly2);

    // Multiply the two polynomials
    multiplyPolynomials();

    printf("Resultant polynomial: ");
    displayList(result);

    return 0;
}

void insertBack(int c, int e, struct node **headRef)
{
    struct node *newNode;
    struct node *temp;

    // Create a new node for the polynomial term
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    // Insert the node if the list is empty
    if (*headRef == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        temp = *headRef;

        // Traverse to the last node
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

// Insert a term into the result list in descending exponent order
void insertSorted(int c, int e)
{
    struct node *newNode;
    struct node *current;

    // Create a new node for the result
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->coeff = c;
    newNode->exp = e;

    // Insert into an empty result list
    if (result == NULL)
    {
        newNode->next = NULL;
        result = newNode;
        return;
    }

    // Insert before the current first node
    if (e > result->exp)
    {
        newNode->next = result;
        result = newNode;
        return;
    }

    // Combine terms having the same exponent
    if (e == result->exp)
    {
        result->coeff += c;
        free(newNode);
        return;
    }

    current = result;

    // Find the correct position for the new term
    while (current->next != NULL && current->next->exp > e)
        current = current->next;

    // Combine the term if the exponent already exists
    if (current->next != NULL && current->next->exp == e)
    {
        current->next->coeff += c;
        free(newNode);
    }
    else
    {
        // Insert the new term at the required position
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Display the polynomial starting from the given head
void displayList(struct node *head)
{
    struct node *current = head;
    int first = 1;

    // Display zero when the polynomial has no terms
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    while (current != NULL)
    {
        // Display only non-zero terms
        if (current->coeff != 0)
        {
            // Print the sign between consecutive terms
            if (!first && current->coeff > 0)
                printf("+ ");

            if (current->exp == 0)
                printf("%d ", current->coeff);
            else if (current->exp == 1)
                printf("%dx ", current->coeff);
            else
                printf("%dx^%d ", current->coeff, current->exp);

            first = 0;
        }

        current = current->next;
    }

    // Print zero if all coefficients became zero
    if (first)
        printf("0");

    printf("\n");
}

// Multiply the two polynomials and store the result
void multiplyPolynomials(void)
{
    struct node *p1 = poly1;
    struct node *p2;
    int coeff, exp;

    // Select each term from the first polynomial
    while (p1 != NULL)
    {
        p2 = poly2;

        // Multiply it with every term of the second polynomial
        while (p2 != NULL)
        {
            coeff = p1->coeff * p2->coeff;
            exp = p1->exp + p2->exp;

            // Insert the product into the result list
            insertSorted(coeff, exp);

            p2 = p2->next;
        }

        p1 = p1->next;
    }
}
