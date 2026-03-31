#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int x,y;
    int a[]={1,2,3,4,5,6};
    printf("Enter the positions to swap");
    printf("\nindex 1: ");
    scanf("%d",&x);
    printf("\nindex 2: ");
    scanf("%d",&y);
    int *c=&a[x-1];
    int *d=&a[y-1];
    swap(c,d);
    printf("New array is: ");
    for(int i=0;i<6;i++){
        printf("%d,",a[i]);
    }
}
