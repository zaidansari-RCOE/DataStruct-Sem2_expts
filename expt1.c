/*
Title : Array Implementation of stack
Name : Md zaid mashooque ansari
Class :First Year
DIV :C
Roll no. :051
UIN :241P057
*/
#include<stdio.h>

#define SIZE 15
int arr[SIZE] = {0};

void insertElmt() {
    int element, index;

retry_ins:
    printf("Enter the index to insert the element in (0-%d):\n", SIZE - 1);
    scanf("%d", &index);
    if (index < 0 || index >= SIZE) {
        printf("Please enter index number in the range given.\n");
        goto retry_ins;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    arr[index] = element;
    printf("Element %d inserted at index %d.\n", element, index);
}

void delElmt() {
    int index;
retry_del:
    printf("Enter index to delete the element from (0-%d): ", SIZE - 1);
    scanf("%d", &index);
    if (index < 0 || index >= SIZE) {
        printf("Please enter index number in the range given.\n");
        goto retry_del;
    }
    arr[index] = 0;
    printf("Element at index %d has been deleted.\n", index);
}

void displayArr() {
    printf("Array elements are: ");
    int isEmpty = 1;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] != 0) {
            printf("%d ", arr[i]);
            isEmpty = 0;
        }
    }
    if (isEmpty) {
        printf("The array is empty.");
    }
    printf("\n");
}

int main() {
    int choice;
    printf("\t\t*****Array Data Structure*****\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice(1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                insertElmt();
                break;
            case 2:
                delElmt();
                break;
            case 3:
                displayArr();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again with values in the specified range.\n");
        }
    }
    return 0;
}
