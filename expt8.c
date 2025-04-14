/*
Title : Implementation of stack using linked list
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

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (!top) {
        printf("Stack is Empty!\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void display() {
    if (!top) {
        printf("Stack is Empty!\n");
        return;
    }
    struct Node* temp = top;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}

/*OUTPUT
30 -> 20 -> 10 -> NULL
20 -> 10 -> NULL

Process returned 0 (0x0)   execution time : 0.057 s
Press any key to continue.*/	
