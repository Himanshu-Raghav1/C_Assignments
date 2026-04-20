#include <stdio.h>

#define MAX_STUDENTS 50
#define SUBJECTS 3

typedef struct
{
    int roll_no;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
}
Student;

void input_student(Student *s);
void calculate_result(Student *s);
void display_student(Student *s);

int main(void)
{
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_STUDENTS)
    {
        printf("Invalid number of students.\n");
        return 1;
    }

    Student students[MAX_STUDENTS];

    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        input_student(&students[i]);
        calculate_result(&students[i]);
    }

    printf("\n\nStudent Results\n");
    for (int i = 0; i < n; i++)
    {
        display_student(&students[i]);
    }

    return 0;
}

void input_student(Student *s)
{
    printf("Roll Number: ");
    scanf("%d", &s->roll_no);

    printf("Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter marks in %d subjects:\n", SUBJECTS);
    for (int i = 0; i < SUBJECTS; i++)
    {
        printf("  Subject %d: ", i + 1);
        scanf("%f", &s->marks[i]);
    }
}

void calculate_result(Student *s)
{
    s->total = 0;

    for (int i = 0; i < SUBJECTS; i++)
    {
        s->total += s->marks[i];
    }

    s->percentage = (s->total / (SUBJECTS * 100.0)) * 100.0;
}

void display_student(Student *s)
{
    printf("\nRoll No  : %d\n", s->roll_no);
    printf("Name     : %s\n", s->name);
    printf("Total    : %.2f\n", s->total);
    printf("Percentage: %.2f%%\n", s->percentage);
    printf("\n");
}
