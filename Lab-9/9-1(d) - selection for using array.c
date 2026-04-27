#include <stdio.h>
void selectionsort(int arr[],int len){
    for(int i=0;i<len-1;i++){
        int min_pos=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[min_pos]){
                 min_pos=j;
            }
        }
        if(min_pos!=i){
            int temp=arr[i];
            arr[i]=arr[min_pos];
            arr[min_pos]=temp;
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
    selectionsort(arr, 5);
    printf("Sorted array:\n");
    for(int i=0;i<5;i++){
        printf("%d, ", arr[i]);
    }
}
