#include <stdio.h>

struct Employee
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    struct Employee e;
    FILE *fp;
    int n, position;

    fp = fopen("employee.dat", "wb");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter ID, Name and Salary: ");
        scanf("%d %s %f", &e.id, e.name, &e.salary);

        fwrite(&e, sizeof(e), 1, fp);
    }

    fclose(fp);

    fp = fopen("employee.dat", "rb");

    printf("\nEnter employee position to view: ");
    scanf("%d", &position);

    fseek(fp, (position - 1) * sizeof(e), SEEK_SET);
    fread(&e, sizeof(e), 1, fp);

    printf("\nEmployee Details\n");
    printf("ID     : %d\n", e.id);
    printf("Name   : %s\n", e.name);
    printf("Salary : %.2f\n", e.salary);

    fclose(fp);

    return 0;
}
