#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee emp;
    int n, position;

    fp = fopen("employee.dat", "wb+");

    if (fp == NULL)
    {
        perror("File error");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp.id);

        printf("Name: ");
        scanf("%s", emp.name);

        printf("Salary: ");
        scanf("%f", &emp.salary);

        fwrite(&emp, sizeof(emp), 1, fp);
    }

    printf("\nEnter employee position to access (1-%d): ", n);
    scanf("%d", &position);

    if (position < 1 || position > n)
    {
        printf("Invalid position.\n");
    }
    else
    {
        fseek(fp, (position - 1) * sizeof(emp), SEEK_SET);

        fread(&emp, sizeof(emp), 1, fp);

        printf("\nEmployee Details:\n");
        printf("ID     : %d\n", emp.id);
        printf("Name   : %s\n", emp.name);
        printf("Salary : %.2f\n", emp.salary);
    }

    fclose(fp);

    return 0;
}