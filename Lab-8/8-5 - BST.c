#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ================= INSERT (ITERATIVE) =================
struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);

    if (root == NULL)
        return newNode;

    struct Node* parent = NULL;
    struct Node* curr = root;

    while (curr != NULL) {
        parent = curr;

        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// ================= SEARCH (ITERATIVE) =================
struct Node* search(struct Node* root, int key) {
    struct Node* curr = root;

    while (curr != NULL) {
        if (key == curr->data)
            return curr;

        else if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return NULL;
}

// ================= DELETE (ITERATIVE) =================
struct Node* deleteNode(struct Node* root, int key) {
    struct Node* parent = NULL;
    struct Node* curr = root;

    // find node
    while (curr != NULL && curr->data != key) {
        parent = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL) {
        printf("Value not found\n");
        return root;
    }

    // Case 1 & 2: 0 or 1 child
    if (curr->left == NULL || curr->right == NULL) {
        struct Node* child;

        if (curr->left != NULL)
            child = curr->left;
        else
            child = curr->right;

        if (parent == NULL) { // deleting root
            free(curr);
            return child;
        }

        if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;

        free(curr);
    }
    // Case 3: 2 children
    else {
        struct Node* succParent = curr;
        struct Node* succ = curr->right;

        // find inorder successor
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        curr->data = succ->data;

        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        free(succ);
    }

    return root;
}

// ================= INORDER =================
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// ================= MAIN =================
int main() {
    struct Node* root = NULL;

    // insert
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder: ");
    inorder(root);

    // search
    int key = 40;
    if (search(root, key))
        printf("\n%d found", key);
    else
        printf("\n%d not found", key);

    // delete
    root = deleteNode(root, 30);

    printf("\nAfter deletion: ");
    inorder(root);

    return 0;
}
