#include<stdio.h>
void main(){
    int s,n,key;
    
    printf("Enter the size of array: ");
    scanf("%d",&s);
    int a[s];
    
    printf("Enter the position at which new elementis to be inserted: ");
    scanf("%d",&n);
    
    printf("Enter the new element: ");
    scanf("%d",&key);
    
    //taking inputs of elements
    for(int i=0;i<s;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    //entering the new element atspecified postion
    for(int i=0;i<s;i++){
        if((i+1)==n){
            a[i]=key;
        }
    }
    //printing the modified array
    for(int i=0;i<s;i++){
        printf("%d\t",a[i]);
    }
}
