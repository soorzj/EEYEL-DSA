/***************************************************************
 * Program to implement chaining in hashing using linked list   *
 * Author: SOORAJ                                              *
 * Date: 12-10-26                                              *
 * Version: 1                                                  *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define max 10

struct node {
    int data;
    struct node *next;
};

struct node *hashtable[max]; // Array of linked list head pointers

// function prototypes
void insert(int key);               //inserts key into the hash table chain
void display(void);                 //displays the hash table chains
void search(int key);                //searches for key in the hash table chain

int main(void) {
    int choice = -1, key;
    // initialize table heads to NULL
    for (int i = 0; i < 10; i++) 
        hashtable[i] = NULL;

    while (choice != 4) {
        printf("Menu for Hash Table Chaining\n");
        printf("1.Input (Insert)\n2.Display\n3.Search for element\n4.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert:\n");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter key to search:\n");
                scanf("%d", &key);
                search(key);
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

void insert(int key) {
    int index = key % 10;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = NULL;
    if (hashtable[index] == NULL) 
        hashtable[index] = newNode;
    else {
        struct node *current = hashtable[index];
        while (current->next != NULL) {
            if (current->data == key) {
                printf("Error: key %d already exists in chain\n", key);
                free(newNode);
                return;
            }
            current = current->next;
        }
        if (current->data == key) {
            printf("Error: key %d already exists in chain\n", key);
            free(newNode);
            return;
        }
        current->next = newNode;
    }
    printf("Key %d inserted successfully at index %d\n", key, index);
}

void display(void) {
    printf("Index\tChain\n");
    for (int i = 0; i < 10; i++) {
        printf("[%d]\t", i);
        if (hashtable[i] == NULL)
            printf("NULL\n");
        else {
            struct node *current = hashtable[i];
            while (current != NULL) {
                printf("%d -> ", current->data);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

void search(int key) {
    int index = key % 10;
    struct node *current = hashtable[index];
    int pos = 1;
    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found at index %d at position %d in chain\n", key, index, pos);
            return;
        }
        current = current->next;
        pos++;
    }
    printf("Element %d not found in the hash table\n", key);
}