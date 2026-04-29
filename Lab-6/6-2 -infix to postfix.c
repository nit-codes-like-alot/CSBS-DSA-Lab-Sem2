#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Precedence function
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;

    while (infix[i] != '\0') {

        // Operand
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        // Left parenthesis
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        // Right parenthesis
        else if (infix[i] == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

// Main
int main() {
    char infix[] = "A+B*C";
    char postfix[MAX];

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}
