#include <stdio.h>

int main(void)
{
    int choice;
    float num1, num2;

    printf("Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch (choice)
    {
        case 1:
            printf("Addition = %.2f\n", num1 + num2);
            break;
        case 2:
            printf("Subtraction = %.2f\n", num1 - num2);
            break;
        case 3:
            printf("Multiplication = %.2f\n", num1 * num2);
            break;
        case 4:
            if (num2 != 0)
            {
                printf("Division = %.2f\n", num1 / num2);
            }
            else
            {
                printf("Error! Division by zero not allowed.\n");
            }
            break;
        default:
            printf("Invalid Choice\n");
    }
}
