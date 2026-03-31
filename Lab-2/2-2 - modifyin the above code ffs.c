#include <stdio.h>

struct Student
{
    char name[10];
    int rn;
    char address[100];
};

int main(){

    printf("Lab 2.2\n");
    int n;
    printf("How many values do you want to enter?: ");
    scanf("%d", &n);
    getchar();

    struct Student s[n][3];

    int i = 0;
    printf("Enter the values as asked: \n");
    printf("-----------------\n");

    while (i < n){
        printf("Data %d.\n", i + 1);
        printf("Student Name: ");
        fgets(s[i][0].name, sizeof(s[i][0].name), stdin);
        printf("Roll Number: ");
        scanf(" %d", &s[i][1].rn);
        getchar();
        printf("Address: ");
        fgets(s[i][2].address, sizeof(s[i][2].address), stdin);
        i++;
    }

    printf("-----------------\n");

    printf("The Data you entered is as follows: \n");

    for (i = 0; i < n; i++){
        printf("-----------------\n");
        printf("Data %d\n", i + 1);
        printf("Name : %s", s[i][0].name);
        printf("Roll Number: %d\n", s[i][1].rn);
        printf("Address: %s", s[i][2].address);
    }

    return 0;
}
