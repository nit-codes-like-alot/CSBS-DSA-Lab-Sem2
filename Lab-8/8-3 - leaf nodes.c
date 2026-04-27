#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Count leaf nodes (iterative)
int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int count = 0;

    while (front < rear) {
        struct Node* temp = queue[front++];

        // check if leaf
        if (temp->left == NULL && temp->right == NULL)
            count++;

        if (temp->left)
            queue[rear++] = temp->left;

        if (temp->right)
            queue[rear++] = temp->right;
    }

    return count;
}

// Main
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Leaf nodes = %d\n", countLeaves(root));

    return 0;
}
