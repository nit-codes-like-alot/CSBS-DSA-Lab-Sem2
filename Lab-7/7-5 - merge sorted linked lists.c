#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Merge two sorted lists
struct node* merge(struct node *l1, struct node *l2) {
    // Dummy node to simplify linking
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } 
        else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Helper: insert at end
struct node* insert_end(struct node *head, int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) return newnode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

// Display
void display(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *l1 = NULL, *l2 = NULL;

    // List 1: 10 -> 30 -> 50
    l1 = insert_end(l1, 10);
    l1 = insert_end(l1, 30);
    l1 = insert_end(l1, 50);

    // List 2: 20 -> 40 -> 60
    l2 = insert_end(l2, 20);
    l2 = insert_end(l2, 40);
    l2 = insert_end(l2, 60);

    printf("List 1:\n");
    display(l1);

    printf("List 2:\n");
    display(l2);

    struct node *merged = merge(l1, l2);

    printf("Merged List:\n");
    display(merged);

    return 0;
}
