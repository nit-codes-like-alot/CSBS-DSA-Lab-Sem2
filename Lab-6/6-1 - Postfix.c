#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

// Evaluate postfix
int evaluate(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        // If operand
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); // convert char to int
        }
        // If operator
        else {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
            }
        }
        i++;
    }

    return pop();
}

// Main
int main() {
    char exp[] = "23*5+";

    int result = evaluate(exp);

    printf("Result = %d\n", result);

    return 0;
}
