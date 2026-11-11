/***************************************************************
* Program to add two polynomials using singly linked list      *
* Author: SOORAJ                                               *
* Date: 10-8-26                                                *
* Version: 3                                                   *
****************************************************************/

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
void insertBack(int c, int e, struct node **headRef);   // inserts term at end of list
void insertSorted(int c, int e);                        // inserts term in descending order of exponent
void displayList(struct node *head);                    // displays polynomial
void addPolynomials();                                  // adds poly1 and poly2, stores in result

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

// Insert a new term in the result list in descending order of exponent
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

// Display the polynomial starting from given head
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

// Add two polynomials poly1 and poly2, store result in result list
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