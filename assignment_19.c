#include <stdio.h>
#include <string.h>

#define MAX_EMP 100

typedef struct
{
    char name[50];
    char designation[50];
    char gender;
    char doj[15];
    float salary;
}
Employee;

void input_employee(Employee *e);
void count_employees(int n);
void count_gender(Employee emp[], int n);
void high_salary(Employee emp[], int n);
void find_designation(Employee emp[], int n);

int main(void)
{
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_EMP)
    {
        printf("Invalid count. Enter between 1 and %d.\n", MAX_EMP);
        return 1;
    }

    Employee emp[MAX_EMP];

    for (int i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        input_employee(&emp[i]);
    }

    printf("\nResults\n");
    count_employees(n);
    count_gender(emp, n);
    high_salary(emp, n);
    find_designation(emp, n);

    return 0;
}

void input_employee(Employee *e)
{
    printf("Name: ");
    scanf(" %[^\n]", e->name);

    printf("Designation: ");
    scanf(" %[^\n]", e->designation);

    printf("Gender (M/F): ");
    scanf(" %c", &e->gender);

    printf("Date of Joining (DD-MM-YYYY): ");
    scanf(" %s", e->doj);

    printf("Salary: ");
    scanf("%f", &e->salary);
}

void count_employees(int n)
{
    printf("Total number of employees = %d\n", n);
}

void count_gender(Employee emp[], int n)
{
    int male = 0, female = 0;

    for (int i = 0; i < n; i++)
    {
        if (emp[i].gender == 'M' || emp[i].gender == 'm')
        {
            male++;
        }
        else if (emp[i].gender == 'F' || emp[i].gender == 'f')
        {
            female++;
        }
    }

    printf("Male employees   = %d\n", male);
    printf("Female employees = %d\n", female);
}

void high_salary(Employee emp[], int n)
{
    printf("\nEmployees with salary > 10000:\n");
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (emp[i].salary > 10000)
        {
            printf("  %s (Rs. %.2f)\n", emp[i].name, emp[i].salary);
            found = 1;
        }
    }

    if (!found)
    {
        printf("  None\n");
    }
}

void find_designation(Employee emp[], int n)
{
    printf("\nEmployees with designation 'Asst Manager':\n");
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(emp[i].designation, "Asst Manager") == 0 ||
            strcmp(emp[i].designation, "AsstManager") == 0)
        {
            printf("  %s\n", emp[i].name);
            found = 1;
        }
    }

    if (!found)
    {
        printf("  None\n");
    }
}
