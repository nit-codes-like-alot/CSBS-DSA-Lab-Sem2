#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

/* -------------------- STACK -------------------- */
// Push (insert at beginning)
struct node* push(struct node *top, int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = top;
    return newnode;
}

// Pop (delete from beginning)
struct node* pop(struct node *top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }
    struct node *temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
    return top;
}

// Display stack
void display_stack(struct node *top) {
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

/* -------------------- QUEUE -------------------- */
// Enqueue (insert at end)
void enqueue(struct node **front, struct node **rear, int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newnode;
        return;
    }

    (*rear)->next = newnode;
    *rear = newnode;
}

// Dequeue (delete from beginning)
void dequeue(struct node **front, struct node **rear) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = *front;
    printf("Dequeued: %d\n", temp->data);

    *front = (*front)->next;

    if (*front == NULL) // if queue becomes empty
        *rear = NULL;

    free(temp);
}

// Display queue
void display_queue(struct node *front) {
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

/* -------------------- MAIN -------------------- */
int main() {
    // STACK
    struct node *top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    printf("Stack:\n");
    display_stack(top);

    top = pop(top);
    display_stack(top);

    // QUEUE
    struct node *front = NULL, *rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    printf("\nQueue:\n");
    display_queue(front);

    dequeue(&front, &rear);
    display_queue(front);

    return 0;
}
