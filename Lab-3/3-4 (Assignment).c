#include <stdio.h>

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    char names[n][50];

    printf("Enter student names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    printf("\nStudent Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
