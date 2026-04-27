#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int n = 0;

// Create node
struct Node* createNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

// Add edge u -> v
void addEdge(int u, int v) {
    struct Node* temp = createNode(v);
    temp->next = adj[u];
    adj[u] = temp;
}

// DFS function
void DFS(int node) {
    visited[node] = 1;
    printf("%d ", node);

    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFS(temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    n = 5;

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    printf("DFS Traversal: ");
    DFS(0);

    return 0;
}
