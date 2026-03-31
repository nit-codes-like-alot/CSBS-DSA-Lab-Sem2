#include <stdio.h>

struct Employee
{
    int emp_id;
    char emp_name[20];
    float emp_salary;
};

struct Organization
{
    char org_name[20];
    int org_id;
    struct Employee e[2];
};

int main()
{
    printf("Lab 2.3\n");

    struct Organization o[2];
    int i, j;

    printf("Enter the values as asked:\n");
    printf("----------------------\n");

    for (i = 0; i < 2; i++)
    {
        printf("Organization %d\n", i + 1);

        printf("Organization Name: ");
        fgets(o[i].org_name, sizeof(o[i].org_name), stdin);

        printf("Organization ID: ");
        scanf("%d", &o[i].org_id);
        getchar();

        for (j = 0; j < 2; j++)
        {
            printf("Employee %d\n", j + 1);

            printf("Employee Name: ");
            fgets(o[i].e[j].emp_name, sizeof(o[i].e[j].emp_name), stdin);

            printf("Employee ID: ");
            scanf("%d", &o[i].e[j].emp_id);

            printf("Employee Salary: ");
            scanf("%f", &o[i].e[j].emp_salary);
            getchar();
        }
        printf("----------------------\n");
    }

    printf("The Data you entered is as follows:\n");

    for (i = 0; i < 2; i++)
    {
        printf("----------------------\n");
        printf("Organization %d\n", i + 1);
        printf("Organization Name: %s", o[i].org_name);
        printf("Organization ID: %d\n", o[i].org_id);

        for (j = 0; j < 2; j++)
        {
            printf("Employee %d\n", j + 1);
            printf("Employee Name: %s", o[i].e[j].emp_name);
            printf("Employee ID: %d\n", o[i].e[j].emp_id);
            printf("Employee Salary: %.2f\n", o[i].e[j].emp_salary);
        }
    }

    return 0;
}
