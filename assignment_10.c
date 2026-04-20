#include <stdio.h>
#include <stdbool.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
bool divide(double a, double b, double *result);
double power(double base, int exponent);
bool factorial(int n, long long *result);

int main(void)
{
    int choice;

    printf("Simple Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Factorial (x!)\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    switch (choice)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        {
            double num1, num2;

            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &num1, &num2) != 2)
            {
                printf("Invalid input.\n");
                return 1;
            }
            if (choice == 1)
            {
                printf("Result = %.2lf\n", add(num1, num2));
            }
            else if (choice == 2)
            {
                printf("Result = %.2lf\n", subtract(num1, num2));
            }
            else if (choice == 3)
            {
                printf("Result = %.2lf\n", multiply(num1, num2));
            }
            else
            {
                double result;
                if (!divide(num1, num2, &result))
                {
                    printf("Division by zero not allowed.\n");
                    return 1;
                }
                printf("Result = %.2lf\n", result);
            }

            break;
        }

        case 5:
        {
            double base;
            int exponent;

            printf("Enter base and integer exponent: ");
            if (scanf("%lf %d", &base, &exponent) != 2)
            {
                printf("Invalid input.\n");
                return 1;
            }

            printf("Result = %.2lf\n", power(base, exponent));
            break;
        }

        case 6:
        {
            int n;
            long long result;

            printf("Enter a non-negative integer: ");
            if (scanf("%d", &n) != 1)
            {
                printf("Invalid input.\n");
                return 1;
            }

            if (!factorial(n, &result))
            {
                printf("Factorial not defined for negative numbers.\n");
                return 1;
            }

            printf("Result = %lld\n", result);
            break;
        }

        default:
            printf("Invalid choice.\n");
            return 1;
    }
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

bool divide(double a, double b, double *result)
{
    if (b == 0)
    {
        return false;
    }

    *result = a / b;
    return true;
}

double power(double base, int exponent)
{
    double result = 1.0;
    int abs_exp = exponent < 0 ? -exponent : exponent;

    for (int i = 0; i < abs_exp; i++)
    {
        result *= base;
    }

    if (exponent < 0)
    {
        return 1.0 / result;
    }

    return result;
}

bool factorial(int n, long long *result)
{
    if (n < 0)
    {
        return false;
    }

    *result = 1;

    for (int i = 1; i <= n; i++)
    {
        *result *= i;
    }

    return true;
}
