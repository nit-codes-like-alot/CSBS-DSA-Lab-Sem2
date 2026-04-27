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

// Find height iteratively
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int h = 0;

    while (front < rear) {
        int size = rear - front;  // nodes in current level

        // process one level
        for (int i = 0; i < size; i++) {
            struct Node* temp = queue[front++];

            if (temp->left)
                queue[rear++] = temp->left;

            if (temp->right)
                queue[rear++] = temp->right;
        }

        h++;  // completed one level
    }

    return h;
}

// Main
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Height = %d\n", height(root));

    return 0;
}
