/***************************************************************
 * Program to implement binary search tree in C using struct   *
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

// function prototypes
void insertElement(int val);             //function that checks if tree is empty and inserts element at appropriate position
void deleteElement(int val);             //function that checks if tree is empty and deletes a given element
void searchElement(int val);             //function that checks if tree is empty and searches for an element
void displayTree(void);                  //function that checks if tree is empty and prints elements in inorder traversal
void inorderTraversal(struct node *ptr); //helper function to perform recursive inorder traversal
struct node* deleteHelper(struct node *rootNode, int val); //helper function to handle recursive deletion
struct node* getMinNode(struct node *curr); //helper function to find inorder successor

int main() {
    int choice = -1, val;
    while (choice != 5) {
        printf("\nMenu for Binary Search Tree\n");
        printf("1.Insert Element\n2.Delete Element\n3.Search Element\n4.Display Tree (Inorder)\n5.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter The element to insert:\n");
                scanf("%d", &val);
                insertElement(val);
                break;
            case 2:
                printf("Enter The element to delete:\n");
                scanf("%d", &val);
                deleteElement(val);
                break;
            case 3:
                printf("Enter The element to search:\n");
                scanf("%d", &val);
                searchElement(val);
                break;
            case 4:
                displayTree();
                break;
            case 5:
                printf("Exiting Program\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

void insertElement(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        printf("Element inserted\n");
        return;
    }
	//finding the parent nodee
    struct node *current = root;
    struct node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (val < current->data) 
            current = current->left;
        else if (val > current->data) 
            current = current->right;
        else {
            printf("Element already exists in the tree\n");
            free(newNode);
            return;
        }
    }

    if (val < parent->data) 
        parent->left = newNode;
    else
        parent->right = newNode;
    printf("Element inserted\n");
}

void searchElement(int val) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct node *current = root;
    while (current != NULL) {
        if (current->data == val) {
            printf("Element %d found in the tree\n", val);
            return;
        }
        else if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }
    printf("Element %d not found in the tree\n", val);
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

void deleteElement(int val) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    //finding the node with the element to be delted
    struct node *current = root;
    int found = 0;
    while (current != NULL) {
        if (current->data == val) {
            found = 1;
            break;
        }
        else if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (found!=1) {
        printf("Element %d not found in the tree\n", val);
        return;
    }

    root = deleteHelper(root, val);
    printf("Element %d deleted\n", val);
}

struct node* deleteHelper(struct node *rootNode, int val) {
    if (rootNode == NULL)
        return rootNode;
        
    if (val < rootNode->data)
        rootNode->left = deleteHelper(rootNode->left, val);
	else if (val > rootNode->data) 
        rootNode->right = deleteHelper(rootNode->right, val);
	else {
        // Node with only one child or no child
        if (rootNode->left == NULL) {
            struct node *temp = rootNode->right;
            free(rootNode);
            return temp;
        }
        else if (rootNode->right == NULL) {
            struct node *temp = rootNode->left;
            free(rootNode);
            return temp;
        }
        
        struct node *temp = getMinNode(rootNode->right);// Node with two children: Get the inorder successor (smallest in the right subtree)
        rootNode->data = temp->data;					// Copy the inorder successor's content to this node  
        rootNode->right = deleteHelper(rootNode->right, temp->data); // Delete the inorder successor
    }
    return rootNode;
}

struct node* getMinNode(struct node *curr) {
    while (curr!=NULL && curr->left!=NULL) {
        curr = curr->left;
    }
    return curr;
}
