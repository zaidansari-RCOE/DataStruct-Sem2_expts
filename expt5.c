/* Expt5: Array Implementation of Linear Queue.
    Name: Mohd Zaid Ansari
    Division: C
    UIN: 241P057 
*/
#include <stdio.h>

#define SIZE 5  // Define the size of the queue

int queue[SIZE]; // Array to hold queue elements
int front = -1, rear = -1; // Front and rear pointers

// Function to insert an element into the queue
void enQueue(int value) {
    if (rear == SIZE - 1) { // Check if the queue is full
        printf("Queue is FULL. Insertion not possible!\n");
    } else {
        if (front == -1) front = 0; // Set front if inserting first element
        queue[++rear] = value; // Increment rear and insert value
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to delete an element from the queue
void deQueue() {
    if (front == -1 || front > rear) { // Check if the queue is empty
        printf("Queue is EMPTY! Deletion not possible!\n");
        front = rear = -1; // Reset queue
    } else {
        printf("Deleted %d from the queue.\n", queue[front++]); // Remove front element
        if (front > rear) front = rear = -1; // Reset queue if empty
    }
}

// Function to display the queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
/*
OUTPUT
Queue Operations:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 12
Inserted 12 into the queue.

Queue Operations:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 13
Inserted 13 into the queue.

Queue Operations:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 2
Deleted 12 from the queue.

Queue Operations:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 3
Queue elements: 13

Queue Operations:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 4
  */
