/*Write a program in C to implement arrays of pointers and pointers to arrays*/

#include <stdio.h>

int main()
{
    printf("Lab 3.1\n");

    printf("Array of pointers: \n");
    int a=10, b=20, c=30;
    int *ArrPtr[3] = {&a, &b, &c};

    for (int i=0; i<3; i++){
        printf("Value at ArrPtr[%d] = %d\n",i, *ArrPtr[i]);
    }

    printf("\n");

    printf("Pointer to an array: \n");

    int arr[3] = {10, 20, 30};
    int (*p) = &arr;

    for (int i=0; i<3; i++){
        printf("Value at arr[%d]: %d\n", i, *(p+i));
    }

    return 0;
}
