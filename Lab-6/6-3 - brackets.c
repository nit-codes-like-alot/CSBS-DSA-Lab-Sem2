#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    if (top == -1)
        return '#'; // error
    return stack[top--];
}

// Check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Check balanced brackets
int isBalanced(char exp[]) {
    for (int i = 0; exp[i]; i++) {

        // Opening brackets
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        // Closing brackets
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            if (top == -1)
                return 0;

            char popped = pop();

            if (!isMatchingPair(popped, exp[i]))
                return 0;
        }
    }

    return (top == -1);
}

// Main
int main() {
    char exp[] = "{[()]}";

    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
