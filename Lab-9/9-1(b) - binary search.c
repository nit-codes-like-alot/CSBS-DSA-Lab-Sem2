#include <stdio.h>
int BinarySearch(int arr[],int size, int key){
    int mid,low=0,high=size-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low =mid+1;
        }
        else{
            high =mid-1;
        }
    }
    return -1;
}
void main(){
    int arr[5];
    int key;
    //taking input of array elements
    for(int i=0;i<5;i++){
        printf("enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    //taking input of the number that user wants to search
    printf("Enter the element you want to search: ");
    scanf("%d",&key);
    
    int result=BinarySearch(arr,5,key);
    
    if(result!=-1){
        printf("Element found at index %d: ",result);
    }
    else{
        printf("Element not found!!");
    }
}
