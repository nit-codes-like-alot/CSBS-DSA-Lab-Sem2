#include <stdio.h>
#include <ctype.h>

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
int evaluate(char *exp) {
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If number (multi-digit)
        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
            i++;
        }
    }

    return pop();
}

// Main
int main() {
    char exp[] = "10 5 + 30 6 / 5 * 3 * * + 8 -";

    int result = evaluate(exp);

    printf("Result = %d\n", result);

    return 0;
}
