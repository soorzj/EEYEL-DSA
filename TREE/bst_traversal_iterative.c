/***************************************************************
 * Program to implement binary search tree in C using struct   *
 * and perform iterative traversals (without recursion)        *
 * Author: SOORAJ                                              *
 * Date: 10-8-26                                               *
 * Version: 3                                                  *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// function prototypes
void insertElement(int val);// function to insert element into BST iteratively
void Inorder(int n);        // function to display inorder traversal iteratively
void Preorder(int n);       // function to display preorder traversal iteratively
void Postorder(int n);      // function to display postorder traversal iteratively

int main() {
    int n, val;
    printf("Enter the number of elements to insert in the BST:\n");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insertElement(val);
    }
    printf("\nInorder Traversal:\n");
    Inorder(n);
    printf("\nPreorder Traversal:\n");
    Preorder(n);
    printf("\nPostorder Traversal:\n");
    Postorder(n);
    return 0;
}

void insertElement(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL) {
        root = newNode;
        return;
    }
    struct node *current = root;
    struct node *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (val < current->data)
            current = current->left;
		else if (val > current->data) 
            current = current->right;
        else {
            printf("Element %d already exists. Skipping.\n", val);
            free(newNode);
            return;
        }
    }
    if (val < parent->data) 
        parent->left = newNode;
    else
        parent->right = newNode;
}

void Inorder(int n) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    struct node **stack = (struct node**)malloc(n * sizeof(struct node*));
    int top = -1;
    struct node *current = root;
    
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current; 
            current = current->left;
        }
        current = stack[top--];
        printf("%d\t", current->data);
        current = current->right;
    }
    free(stack);
    printf("\n");
}

void Preorder(int n) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    
    struct node **stack = (struct node**)malloc(n * sizeof(struct node*));
    int top = -1;
    stack[++top] = root;
    
    while (top != -1) {
        struct node *current = stack[top--];
        printf("%d\t", current->data);
        if (current->right)
            stack[++top] = current->right;
        if (current->left) 
            stack[++top] = current->left;
    }
    free(stack);
    printf("\n");
}

void iterativePostorder(int n) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    struct node **stack1 = (struct node**)malloc(n * sizeof(struct node*));
    struct node **stack2 = (struct node**)malloc(n * sizeof(struct node*));
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct node *current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left) 
            stack1[++top1] = current->left;
        if (current->right) 
            stack1[++top1] = current->right;
}

    while (top2 != -1) 
        printf("%d\t", stack2[top2--]->data);
    free(stack1);
    free(stack2);
    printf("\n");
}
