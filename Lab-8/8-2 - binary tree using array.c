#include <stdio.h>

#define MAX 100

int tree[MAX];
int n;

// Get parent
void getParent(int i) {
    if (i == 0) {
        printf("Root node has no parent\n");
        return;
    }
    printf("Parent of %d is %d\n", tree[i], tree[(i - 1) / 2]);
}

// Get children
void getChildren(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
        printf("Left child of %d is %d\n", tree[i], tree[left]);
    else
        printf("No left child\n");

    if (right < n)
        printf("Right child of %d is %d\n", tree[i], tree[right]);
    else
        printf("No right child\n");
}

// Get sibling
void getSibling(int i) {
    if (i == 0) {
        printf("Root node has no sibling\n");
        return;
    }

    if (i % 2 == 0) { // right child
        int sibling = i - 1;
        printf("Sibling of %d is %d\n", tree[i], tree[sibling]);
    } else { // left child
        int sibling = i + 1;
        if (sibling < n)
            printf("Sibling of %d is %d\n", tree[i], tree[sibling]);
        else
            printf("No sibling\n");
    }
}

// Main
int main() {
    int i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    int index;
    printf("Enter index: ");
    scanf("%d", &index);

    getParent(index);
    getChildren(index);
    getSibling(index);

    return 0;
}
