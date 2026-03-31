#include <stdio.h>

struct Student
{
    char name[10];
    int rn;
    char address[100];
};

int main(){

    printf("Lab 2.1\n");

    printf("Enter the values as asked: \n");
    struct Student s;
    printf("Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    printf("Roll Number: ");
    scanf(" %d", &s.rn);
    getchar();
    printf("Address: ");
    fgets(s.address, sizeof(s.address), stdin);

    printf("The Data you entered is as follows: \n");
    printf("Name : %s", s.name);
    printf("Roll Number: %d\n", s.rn);
    printf("Address: %s", s.address);

    return 0;
}
