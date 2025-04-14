/*Expt4: Program to Evaluate Postfix Expression using Stack ADT.
    Name: Mohd Zaid Ansari
    Division:c
    UIN:241P057   */

#include <stdio.h>
#include <ctype.h>

#define size 10

int top = -1, stack[size];

void push(int value) {
    if (top == size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int evaluator(char* expr) {
    int i = 0, operand1, operand2, result;

    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();

            switch (expr[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero!\n");
                        return -1;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator!\n");
                    return -1;
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    int result;
    char expression[50];

    printf("Enter postfix expression: ");
    scanf("%s", expression);

    result = evaluator(expression);
    printf("Result: %d\n", result);

    return 0;
}
/*
Output: Enter postfix expression: 512+4*+3
Result: 3


...Program finished with exit code 0
Press ENTER to exit console*/
