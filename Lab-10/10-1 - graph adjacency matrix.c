#include<stdio.h>
#define MAX 10

int adj[MAX][MAX];
int n=0;//number of nodes

//function to add a new node
void addNode(){
    if(n>=MAX){
        printf("Max nodes reached!\n");
        return;
    }
    n++;
    printf("Node %d added.\n", n-1);
}

//function to delete a node
void deleteNode(int node){
    if(node>=n){
        printf("Invalid node!!\n");
        return;
    }
    for(int i=node;i<n-1;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=adj[i+1][j];
        }
    }
    for(int j=node;j<n-1;j++){
        for(int i=0;i<n-1;i++){
            adj[i][j]=adj[i][j+1];
        }
    }
     n--;
    printf("Node %d deleted.\n", node);
}
void degree(int node) {
    if (node >= n) {
        printf("Invalid node!\n");
        return;
    }

    int in = 0, out = 0;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1)
            out++;
        if (adj[i][node] == 1)
            in++;
    }

    printf("Out-degree: %d\n", out);
    printf("In-degree: %d\n", in);
}

//insert edge
void insertEdge(int u, int v){
    if(u>=n||v>=n){
        printf("invlaid node!!");
        return;
    }
    adj[u][v]=1;
    printf("Edge inserted from %d to %d\n", u, v);
}
//delete edge
void deleteEdge(int u, int v){
    if(u>=n||v>=n){
        printf("Invalid node!!");
        return;
    }
    adj[u][v]=0;
    printf("edge deleted from %d to %d\n", u, v);
}
//display adjacency matrix
void display() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

//main function
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
                printf("Enter node to delete: ");
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
