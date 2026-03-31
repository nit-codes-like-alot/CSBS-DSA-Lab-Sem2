#include <stdio.h>

int main() {
    printf("Lab 1.1");
    printf("\n");
    
    int n;
    printf("What size array do you want?: ");
    scanf("%d", &n);
    char arr[n];
    
    for (int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf(" %c", &arr[i]);
    }
    
    printf("Reversed array is: ");
    printf("\n");
    printf("[");
    for (int i=n-1; i>=0; i--){
        printf("%c ", arr[i]);
        
    }
    printf("]");
    return 0;
}
