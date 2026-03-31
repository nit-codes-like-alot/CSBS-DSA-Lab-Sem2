#include <stdio.h>
#define MAX 5
int deque[MAX];
int front = -1;
int rear = -1;
//Checking if Deque is full
int isFull() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    return 0;
}
//Checking if Deque is empty
int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}
//Inserting at front
void enqueueFront(int x) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = x;
    printf("Inserted %d at Front\n", x);
}
//Inserting at rear
void enqueueRear(int x) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
    printf("Inserted %d at Rear\n", x);
}
//Deleting from front
void dequeueFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted %d from Front\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}
//Deleting from rear
void dequeueRear() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted %d from Rear\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}
//Getting front element
void getFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
    } else {
        printf("Front element: %d\n", deque[front]);
    }
}
//Getting rear element
void getRear() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
    } else {
        printf("Rear element: %d\n", deque[rear]);
    }
}
// Main function (for testing)
int main() {
    enqueueFront(10);
    enqueueRear(20);
    enqueueFront(5);
    getFront();
    getRear();
    dequeueFront();
    dequeueRear();
    return 0;
}
