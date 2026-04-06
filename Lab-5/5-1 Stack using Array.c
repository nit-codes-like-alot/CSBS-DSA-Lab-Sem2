#include <stdio.h>
#define MAX 5
int top = -1;
int stack[MAX];

int isEmpty()
{
    if (top == -1){ //cuz initially it was -1 (when it WAS empty)
        return 1;
    }
    return 0;
}

int isFull()
{
    if (top == MAX - 1){ //very simple
        return 1;
    }
    return 0;
}

void Push(int val)
{
    if(isFull()){
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack[top] = val; //top++ cuz we start the indexing from 0 and top was -1
}

void pop()
{
    if (isEmpty()){
        printf("Stack Underflow!\n");
        return; //-1 signifies an error here
    }
    printf("Popped element: %d\n", stack[top--]); //top-- means it'll return stack[top] & then do top--
}

void peek()
{
    if (isEmpty()){
        printf("Stack is Empty!\n");
        return;
    }
    printf("Element on top: %d\n",stack[top]);
}

// main function (testing)

int main() {
    Push(10);
    Push(20);
    Push(30);
    
    printf("The stack currently looks like: \n");
    printf("[");
    for (int i=0; i<=top; i++){
        printf("%d,", stack[i]);
    }
    printf("]\n");

    printf("Peeking: ");
    peek();   // prints 30
    printf("Popping: ");
    pop();    // prints 30
    printf("Popping: ");
    pop();    // prints 20
    printf("Peeking: ");
    peek();   // prints 10
    printf("Popping: ");
    pop();    // removes 10
    printf("Popping: ");
    pop();    // underflow case

    return 0;
}