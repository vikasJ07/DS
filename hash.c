#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 13

int h[TABLE_SIZE] = {0}; // Initialize all elements to 0 instead of NULL

void insert() {
    int key, index, i, hash2, hkey;
    printf("\nEnter a value to insert into hash table: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    hash2 = 1 + key % (TABLE_SIZE - 2);
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i * hash2) % TABLE_SIZE;
        if (h[index] == 0) { // Change comparison to 0 instead of NULL
            h[index] = key;
            break;
        }
    }
    if (i == TABLE_SIZE)
        printf("\nElement cannot be inserted.\n");
}

void search() {
    int key, index, i, hash2, hkey;
    printf("\nEnter search element: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    hash2 = 1 + key % (TABLE_SIZE - 2);
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i * hash2) % TABLE_SIZE;
        if (h[index] == key) {
            printf("Value is found at index %d.\n", index);
            return;
        }
    }
    printf("Value is not found.\n");
}

void display() {
    printf("\nElements in the hash table are:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("At index %d: Value = %d\n", i, h[i]);
    }
}

int main() {
    int opt;
    while (1) {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4. Exit \n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}

