#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX]; // adjacency list
int n = 0; // number of nodes

// Create new node
struct Node* createNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

// Add node
void addNode() {
    if (n >= MAX) {
        printf("Max nodes reached!\n");
        return;
    }
    adj[n] = NULL;
    printf("Node %d added\n", n);
    n++;
}

// Insert edge u -> v
void insertEdge(int u, int v) {
    if (u >= n || v >= n) {
        printf("Invalid nodes!\n");
        return;
    }

    struct Node* temp = createNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    printf("Edge inserted from %d to %d\n", u, v);
}

// Delete edge u -> v
void deleteEdge(int u, int v) {
    if (u >= n || v >= n) {
        printf("Invalid nodes!\n");
        return;
    }

    struct Node* temp = adj[u];
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == v) {
            if (prev == NULL)
                adj[u] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Edge deleted from %d to %d\n", u, v);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Edge not found!\n");
}

// Delete node
void deleteNode(int node) {
    if (node >= n) {
        printf("Invalid node!\n");
        return;
    }

    // Remove all edges from this node
    struct Node* temp = adj[node];
    while (temp) {
        struct Node* del = temp;
        temp = temp->next;
        free(del);
    }

    // Shift lists up
    for (int i = node; i < n - 1; i++) {
        adj[i] = adj[i + 1];
    }

    // Remove edges pointing to this node
    for (int i = 0; i < n - 1; i++) {
        struct Node* curr = adj[i];
        struct Node* prev = NULL;

        while (curr) {
            if (curr->data == node) {
                if (prev == NULL)
                    adj[i] = curr->next;
                else
                    prev->next = curr->next;

                struct Node* del = curr;
                curr = curr->next;
                free(del);
            } else {
                // Adjust node numbers after deletion
                if (curr->data > node)
                    curr->data--;

                prev = curr;
                curr = curr->next;
            }
        }
    }

    n--;
    printf("Node %d deleted\n", node);
}

// Degree function
void degree(int node) {
    if (node >= n) {
        printf("Invalid node!\n");
        return;
    }

    int out = 0, in = 0;

    // Out-degree
    struct Node* temp = adj[node];
    while (temp) {
        out++;
        temp = temp->next;
    }

    // In-degree
    for (int i = 0; i < n; i++) {
        temp = adj[i];
        while (temp) {
            if (temp->data == node)
                in++;
            temp = temp->next;
        }
    }

    printf("Out-degree: %d\n", out);
    printf("In-degree: %d\n", in);
}

// Display graph
void display() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main
int main() {
    int choice, u, v, node;

    while (1) {
        printf("\n1. Add Node\n2. Delete Node\n3. Insert Edge\n4. Delete Edge\n5. Degree\n6. Display\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNode();
                break;
            case 2:
                printf("Enter node: ");
                scanf("%d", &node);
                deleteNode(node);
                break;
            case 3:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                insertEdge(u, v);
                break;
            case 4:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                deleteEdge(u, v);
                break;
            case 5:
                printf("Enter node: ");
                scanf("%d", &node);
                degree(node);
                break;
            case 6:
                display();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
