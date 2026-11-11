/***************************************************************
 * Program to implement binary tree in C using struct          *
 * Author: SOORAJ                                              *
 * Date: 10-8-26                                               *
 * Version: 1                                                  *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
int count = 0;

// function prototypes
struct node* createTree(int val);       //function that creates a binary tree by accepting left and right children
void displayTree(void);                 //function that checks if tree is empty and prints elements in inorder traversal
void inorderTraversal(struct node *ptr); //helper function to perform recursive inorder traversal
int isComplete(struct node *ptr, int index, int nodeCount); //recursive function to check completeness

int main() {
    int choice = -1, val;

    while (choice != 4) {
        printf("\nMenu for Binary Tree\n");
        printf("1.Create Tree\n2.Display Tree (Inorder)\n3.Check Complete Binary Tree\n4.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter The root element:\n");
                scanf("%d", &val);
                root = createTree(val);
                printf("Tree created\n");
                break;
            case 2:
                displayTree();
                break;
            case 3:
                count = 0;
                if (root == NULL) {
                    printf("Tree is empty\n");
                }
                else if (isComplete(root, 0, count)) {
                    printf("The binary tree is complete\n");
                }
                else {
                    printf("The binary tree is not complete\n");
                }
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}

struct node* createTree(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    int choice, childValue;

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    printf("%d has left node? (1/0):\n", val);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter The left child of %d:\n", val);
        scanf("%d", &childValue);
        count++;
        newNode->left = createTree(childValue);
    }
    printf("%d has right node? (1/0):\n", val);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter The right node of %d:\n", val);
        scanf("%d", &childValue);
        count++;
        newNode->right = createTree(childValue);
    }
    return newNode;
}

void displayTree(void) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Tree elements (Inorder Traversal):\n");
    inorderTraversal(root);
    printf("\n");
}

void inorderTraversal(struct node *ptr) {
    if (ptr != NULL) {
        inorderTraversal(ptr->left);
        printf("%d\t", ptr->data);
        inorderTraversal(ptr->right);
    }
}

int isComplete(struct node *ptr, int index, int nodeCount) {
    if (ptr == NULL)
        return 1;

    if (index >= nodeCount)
        return 0;

    return isComplete(ptr->left, 2 * index + 1, nodeCount) && isComplete(ptr->right, 2 * index + 2, nodeCount);
}
