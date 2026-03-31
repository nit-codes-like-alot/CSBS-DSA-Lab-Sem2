#include<stdio.h>
struct Student {
    char name[50];
    int roll;
    char address[100];
};
void main(){
    struct Student s;//creating a structure variable 
    struct Student *ptr;//pointer to structure
    
    ptr=&s;
    
    //taking input
    printf("Enter student name: ");
    fgets(ptr->name,sizeof(ptr->name),stdin);
    
    printf("Enter roll number: ");
    scanf("%d", &ptr->roll);
    getchar();//consume the newline after scanf
    
    printf("Enter address: ");
    fgets(ptr->address,sizeof(ptr->address),stdin);
    
    //displaying output 
    printf("\nStudent Details:\n");
    printf("Name: %s",ptr->name);
    printf("Roll number: %d",ptr->roll);
    printf("Address: %s",ptr->address);
}
    return 0;
}
