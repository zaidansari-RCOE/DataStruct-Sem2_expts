/* Expt7: Program to Implement Singly Linked List.
    Name: Mohd Zaid Ansari
    Division: C
    UIN: 241P057 
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert after a specific value
void insertAfter(int value, int afterValue) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Given node not found!\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    struct Node* temp1 = head;
    struct Node* temp2 = NULL;
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
    printf("Node deleted from the end.\n");
}

// Function to delete a specific node
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp1 = head;
    struct Node* temp2 = NULL;
    while (temp1 != NULL && temp1->data != value) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1 == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (temp1 == head) {
        head = head->next;
        free(temp1);
        return;
    }
    temp2->next = temp1->next;
    free(temp1);
}

// Function to display the linked list
void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, afterValue;
    while (1) {
        printf("\t\t*****LINKED LIST*****\n");
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Specific Value\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete a Specific Node\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter value after which to insert: ");
                scanf("%d", &afterValue);
                insertAfter(value, afterValue);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

/* Output
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 1
Enter value to insert at beginning: 1
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 2
Enter value to insert at end: 2
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 3
Enter value to insert: 2
Enter value after which to insert: 1
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 7
1 -> 2 -> 2 -> NULL
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 7
1 -> 2 -> 2 -> NULL
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 6
Enter value to delete: 1
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 3
Enter value to insert: 5
Enter value after which to insert: 2
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 7
2 -> 5 -> 2 -> NULL
                *****LINKED LIST*****

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After a Specific Value
4. Delete from Beginning
5. Delete from End
6. Delete a Specific Node
7. Display List
8. Exit
Enter your choice: 8
Exiting...


...Program finished with exit code 0
Press ENTER to exit console.
*/
