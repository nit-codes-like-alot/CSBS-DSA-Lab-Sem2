#include <stdio.h>
void bubblesort(int arr[], int len){
    for(int i=0;i<len;i++){//first loop to traverse all the elements
        for(int j=0;j<len-1;j++){//second loop to interchange consequent elements
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void main(){
    int arr[5];
    int key;
    //taking input of array elements
    for(int i=0;i<5;i++){
        printf("enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    bubblesort(arr, 5);
    printf("Sorted array:\n");
    for(int i=0;i<5;i++){
        printf("%d, ", arr[i]);
    }
}
