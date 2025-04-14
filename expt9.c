/*
Title : Implement Linear Queue ADT using Linked List.
Name : Md.Zaid Mashooque Ansari
Class :First Year
DIV :C
Roll no. :51
UIN :241P057
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enQueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = NULL;

    if (!rear) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void deQueue() {
    if (!front) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    free(temp);
    if (!front) rear = NULL;
}

void display() {
    if (!front) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node* temp = front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enQueue(10);
    enQueue(20);
    enQueue(30);
    display();
    deQueue();
    display();
    return 0;
}

/*OUTPUT :
10 -> 20 -> 30 -> NULL
20 -> 30 -> NULL

Process returned 0 (0x0)   execution time : 0.065 s
Press any key to continue.
*/
