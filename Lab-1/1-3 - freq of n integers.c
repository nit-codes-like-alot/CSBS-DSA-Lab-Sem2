#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n], freq[n];
    
    // Taking input of array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = 0;   // initializing frequency array
    }
    // Counting frequency of each element
    for (int i = 0; i < n; i++) {
        if (freq[i] != -1) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = -1;  // mark as counted
                }
            }
            freq[i] = count;
        }
    }
    // Printing frequency of each element
    printf("\nElement Frequency:\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] != -1) {
            printf("%d -> %d\n", arr[i], freq[i]);
        }
    }
    // Printing unique elements
    printf("\nUnique elements:\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] == 1) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
