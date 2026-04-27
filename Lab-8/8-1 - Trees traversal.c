#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// -------- PREORDER --------
void preorder(struct Node* root) {
    if (!root) return;

    struct Node* stack[MAX];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right)
            stack[++top] = curr->right;
        if (curr->left)
            stack[++top] = curr->left;
    }
}

// -------- INORDER --------
void inorder(struct Node* root) {
    struct Node* stack[MAX];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d ", curr->data);

        curr = curr->right;
    }
}

// -------- POSTORDER (2 stacks) --------
void postorder(struct Node* root) {
    if (!root) return;

    struct Node* s1[MAX], *s2[MAX];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 != -1) {
        struct Node* curr = s1[top1--];
        s2[++top2] = curr;

        if (curr->left)
            s1[++top1] = curr->left;
        if (curr->right)
            s1[++top1] = curr->right;
    }

    while (top2 != -1) {
        printf("%d ", s2[top2--]->data);
    }
}

// -------- LEVEL ORDER --------
void levelOrder(struct Node* root) {
    if (!root) return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }
}

// -------- MAIN --------
int main() {
    // Creating tree manually
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nLevel Order: ");
    levelOrder(root);

    return 0;
}
