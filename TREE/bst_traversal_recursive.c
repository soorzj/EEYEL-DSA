/***************************************************************
 * Program to implement Binary Search Tree in C using struct   *
 * and perform tree traversals using RECURSION                 *
 * Author: SOORAJ                                              *
 * Date: 10-8-26                                               *
 * Version: 5                                                  *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Function Prototypes
void insertElement(int val);
void Inorder(struct node *ptr);
void Preorder(struct node *ptr);
void Postorder(struct node *ptr);

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
    Inorder(root);
    printf("\nPreorder Traversal:\n");
    Preorder(root);
    printf("\nPostorder Traversal:\n");
    Postorder(root);
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

void Inorder(struct node *ptr) {
    if (ptr != NULL) {
        Inorder(ptr->left);
        printf("%d\t", ptr->data);
        Inorder(ptr->right);
    }
}
void Preorder(struct node *ptr) {
    if (ptr != NULL) {
        printf("%d\t", ptr->data);
        Preorder(ptr->left);
        Preorder(ptr->right);
    }
}
void Postorder(struct node *ptr) {
    if (ptr != NULL) {
        Postorder(ptr->left);
        Postorder(ptr->right);
        printf("%d\t", ptr->data);
    }
}
