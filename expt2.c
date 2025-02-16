#include <stdio.h>
#define SIZE 10

int stack[SIZE], top = -1;

void push() {
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);
    if (top == SIZE - 1) {
        printf("Stack is full. Insertion is not possible.\n");
        goto end;
    }
    stack[++top] = value;
    printf("Inserted %d into the stack.\n", value);
end:;
}

void pop() {
    if (top == -1) {
        printf("Stack is empty. Deletion is not possible.\n");
        goto end;
    }
    printf("Deleted %d from the stack.\n", stack[top--]);
end:;
}

void display() {
    if (top == -1) {
        printf("Stack is EMPTY.\n");
        goto end;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
end:;
}

int main() {
    int choice;
    printf("\t\t*****STACK STRUCTURE*****\n");

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                goto exit;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

exit:
    return 0;
}
