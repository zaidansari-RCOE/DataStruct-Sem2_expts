/* Expt3: Program to convert an Infix expression to Postfix expression using stack ADT
    Name: Mohd Zaid Ansari
    Division: C
    UIN: 241P057 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    if (top >= SIZE - 1) {
        printf("\nStack Overflow.");
    } else {
        top = top + 1;
        stack[top] = item;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top < 0) {
        printf("\nStack Underflow: Invalid infix expression");
        return 0;
    } else {
        return stack[top--];
    }
}

// Function to return the precedence of operators
int precedence(char symbol) {
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

// Function to check if a character is an operator
int is_operator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

// Function to convert infix expression to postfix
void InfixToPostfix(char infix_exp[], char postfix_exp[]) {
    int i = 0, j = 0;
    char item, x;

    push('(');  // Push '(' onto stack
    strcat(infix_exp, ")");  // Append ')' to the infix expression

    item = infix_exp[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } 
        else if (isalnum(item)) {  // If operand, add to postfix expression
            postfix_exp[j++] = item;
        } 
        else if (is_operator(item)) { // If operator, pop and add to postfix
            x = pop();
            while (is_operator(x) && precedence(x) >= precedence(item)) {
                postfix_exp[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        } 
        else if (item == ')') {  // If ')', pop until '(' is found
            x = pop();
            while (x != '(') {
                postfix_exp[j++] = x;
                x = pop();
            }
        }
        item = infix_exp[++i];  // Move to next character
    }
    postfix_exp[j] = '\0'; // Null terminate the postfix expression
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression: ");
    fgets(infix, SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';  // Remove newline character

    InfixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}




/*
Output:
Enter infix expression: a+b*c
Postfix expression: abc*+


...Program finished with exit code 0
Press ENTER to exit console.
…*/
