/***************************************************************
 * Hash table implementation using linear probing in C         *
 ***************************************************************/

#include <stdio.h>

#define max 10
int hashtable[max];

void insert(int key);               //insert key into the hash table using linear probing
void display(void);                 //display the hash table contents
int search(int key);                //search for key in the hash table and return its index, else return -1

int main() {
    int choice=0, key, index;
    //initialize the hash table slots to -1 (indicating empty)
    for (int i = 0; i < max; i++) {
        hashtable[i] = -1;
    }

    while (choice != 4) {
        printf("\n--- MENU ---\n");
        printf("1. Input (Insert)\n");
        printf("2. Display\n");
        printf("3. Search for element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = search(key);
                if (index != -1)
                    printf("Element %d found at index %d\n", key, index);
                else
                    printf("Element %d not found\n", key);
                break;
            case 4:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Error: invalid choice\n");
        }
    }
    return 0;
}

void insert(int key) {
    int index = key % 10; // Hash function: h(k)=k mod 10
    int start = index;

    while (hashtable[index] != -1) {
        // If element is already present
        if (hashtable[index] == key) {
            printf("Error: key %d already exists\n", key);
            return;
        }
        index = (index + 1) % max;
        // Table is full
        if (index == start) {
            printf("Error: Hash table is full\n");
            return;
        }
    }
    hashtable[index] = key;
    printf("Key %d inserted successfully at index %d\n", key, index);
}

void display(void) {
    printf("Index\tKey\n");
    for (int i = 0; i < max; i++) {
        if (hashtable[i] != -1)
            printf("%d\t%d\n", i, hashtable[i]);
        else
            printf("%d\t~\n", i);
    }
}

int search(int key) {
    // Hash function: h(k)=k mod 10
    int index = key % 10;
    int start = index;

    while (hashtable[index] != -1) {
        if (hashtable[index] == key)
            return index;
        index = (index + 1) % max;
        if (index == start)
            break;
    }
    return -1;
}