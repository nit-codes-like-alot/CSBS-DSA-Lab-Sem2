#include <stdio.h>
int LinearSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
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
    
    int result=LinearSearch(arr,5,key);
    
    if(result!=-1){
        printf("Element found at index %d", result);
    }
    else{
        printf("Element not found!!");
    }
}
