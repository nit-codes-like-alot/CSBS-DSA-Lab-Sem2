#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Checking if queue is full
int isFull() {
    if ((rear + 1) % MAX == front)
        return 1;
    return 0;
}

//Checking if queue is empty
int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void Enqueue(int x) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;
    printf("Inserted %d\n", x);
}

//Deleting element
void Dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;   // Queue becomes empty
    } else {
        front = (front + 1) % MAX;
    }
}

//Printing front element
void Front() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

//Printing rear element
void Rear() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Rear element: %d\n", queue[rear]);
    }
}

//Main function (for testing)
int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Front();
    Rear();
    Dequeue();
    Front();
    Rear();
    return 0;
}
