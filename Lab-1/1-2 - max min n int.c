#include <stdio.h>

int main() {
    printf("Lab 1.2");
    printf("\n");
    
    int min, max, i, j, n;
    printf("How many elements do you want to enter: ");
    scanf(" %d", &n);
    int arr[n];
    
    for (int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf(" %d", &arr[i]);
    }
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if (arr[j] < arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    max = arr[n-1];
    min = arr[0];
    
    printf("The Min & Max are: \n");
    printf("Max = %d, Min = %d", max, min);
    
}
