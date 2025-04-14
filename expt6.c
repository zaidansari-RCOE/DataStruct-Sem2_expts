/* Expt6: Program to Implement a Circular Queue.
    Name: Mohd Zaid Ansari
    Division: C
    UIN: 241P057 
*/

#include <stdio.h>
#define size 5

int queue[size], front = -1, rear = -1, value;

void enqueue();
void dequeue();
void display();

void enqueue() {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Queue full, can't insert element\n");
        return;
    }

    printf("Enter element to insert:\n");
    scanf("%d", &value);

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
    printf("Element inserted...\n");
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty, can't delete element\n");
    }
    else if (front == rear) {
        printf("Element deleted...\n");
        front = -1, rear = -1;
    }
    else {
        printf("Element deleted...\n");
        front = (front + 1) % size;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else if (front <= rear) {
        printf("\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
    else {
        for (int i = 0; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        for (int i = front; i < size; i++) {
            printf("%d\t", queue[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\t\t*****CIRCULAR QUEUE*****\n\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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

/* output
                *****CIRCULAR QUEUE*****


1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element to insert:
1
Element inserted...
                *****CIRCULAR QUEUE*****


1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element to insert:
2
Element inserted...
                *****CIRCULAR QUEUE*****


1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3

1       2
                *****CIRCULAR QUEUE*****


1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Element deleted...
                *****CIRCULAR QUEUE*****


1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3

2
                *****CIRCULAR QUEUE*****


1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4


...Program finished with exit code 0
Press ENTER to exit console.
*/
